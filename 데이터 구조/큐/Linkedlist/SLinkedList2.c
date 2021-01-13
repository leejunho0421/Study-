#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList2.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {		// SLinkedList.c와 동일
	return L->length;

}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;

	}
	L->length++;
}
void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;
	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->link = NULL;
	newNode->data = x;
	if (L->head == NULL)
		L->head = newNode;
	temp = L->head;
	while (temp->link != NULL) {
		temp = temp->link;
	}
	insert(L, temp, x);
	return;
	L->length++;
}
int delete(linkedList* L, listNode* p) {
	listNode* pre;
	if (L->head == NULL) {
		return FALSE;
	}
	else if (p == NULL) {
		return FALSE;
	}
	else if (L->head == p) {
		L->head = p->link;
	}
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
			if (pre == NULL) {
				return FALSE;
			}
			else {
				pre->link = p;
				free(p);
			}
		}
	}
	L->length--;
	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	temp = L->head;

	while (temp->link != NULL) {
		if (temp->data == x) {	
			return temp;		
		}
		
		else {
			temp = temp->link;
		}

	}

	if (temp->link == NULL) {

		printf("no dab");
	}
	return temp;
}
void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
	printf("List number is : %d", L->length);
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void reverse(linkedList* L) {
	listNode* p;
	listNode* q;
	listNode* r;
	q = NULL;
	r = NULL;
	p = L->head;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
		L->head = q;
	}
}
