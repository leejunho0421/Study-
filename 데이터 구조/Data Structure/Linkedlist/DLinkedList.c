#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}


void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	if (L->head == NULL) {
		newNode->rlink = NULL;
		newNode->llink = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->llink = NULL;
		newNode->rlink = L->head;
		L->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL) {
			newNode->rlink->llink = newNode;
			
		}


	}

	L->length++;

}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	newNode->llink = NULL;
	newNode->rlink = L->head;
	L->head = newNode;
	L->length++;


}

void insertLast(linkedList* L, element x) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	
	if (L->head == NULL)
		L->head = newNode;
	temp = L->head;
	while (temp->llink != NULL) {
		temp = temp->llink;
	}
	insert(L, temp, x);
	return;
	L->length++;


}

int delete(linkedList* L, listNode* p) {
	listNode* pre = L->head;
	if (L->head == p) {
		L->head = NULL;
		return FALSE;
	}

	else if (p->rlink == NULL) {
		while (pre != p) {
			if (pre->rlink == NULL) {
				return FALSE;
			}
			pre = pre->rlink;
		}
		pre->llink->rlink = pre->rlink;
	}
	else {
		while (pre != p) {
			if (pre->rlink == NULL) {
				return FALSE;
			}
			pre = pre->rlink;
		}
		pre->llink->rlink = pre->rlink;
		pre->rlink->llink = pre->llink;
	}
	L->length--;
	return 1;
	
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	
	while(temp != NULL) {
		if(temp->data == x)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;
	printf("L=(");
	p = L->head;
	while(p != NULL) {
		printf("%d", p->data);
		p = p->rlink;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->rlink;
		free(p);
		p = NULL;
	}
}

