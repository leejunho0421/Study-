#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* PL, float coef, int exp) {
	// Fill your code
	Node* newNode = PL->head;
	newNode->coef = coef;
	newNode->exp = exp;
	newNode->link = NULL;
	if (PL->last == NULL) {
		PL->head = newNode;
		PL->last = newNode;
	}
	else {
		PL->last->link = newNode;
		PL->last = newNode;
	}
	
}

polyList* addPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	Node* polyA = A->head;
	Node* polyB = B->head;
	
	int sum = 0;
	// Fill your code
	while (polyA != NULL && polyB != NULL) {
		if (polyA->exp == polyB->exp) {
			sum = polyA->coef + polyB->coef;
			if (sum != 0) {
				appendTerm(C, sum, polyA->exp);
				polyA = polyA->link;
				polyB = polyB->link;
			}
			else if (polyA->exp > polyB->exp) {
				appendTerm(C, polyA->coef, polyA->exp);
				polyA = polyA->link;
			}
			else {
				appendTerm(C, polyB->coef, polyB->exp);
				polyB = polyB->link;

			}
		}
		while (polyA != NULL) {
			appendTerm(C, polyA->coef, polyA->exp);
			polyA = polyA->link;
		}
		while (polyB != NULL) {
			appendTerm(C, polyB->coef, polyB->exp);
			polyB = polyB->link;
		}


	}
		
	return C;
}

void displayPoly(polyList* PL) {
	Node* p = PL->head;
	for(; p; p=p->link) {
		printf("%3.0fx^%d", p->coef, p->exp);
		if(p->link != NULL)
			printf(" +");
	}
	printf("\n");
}
