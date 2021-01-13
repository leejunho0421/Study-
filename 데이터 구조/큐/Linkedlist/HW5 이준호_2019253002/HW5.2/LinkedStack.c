#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Stack* S) {
	return 0;

}

// ������ ����������� Ȯ���ϴ� ����			
int isEmpty(Stack* S) {
	return S->top == NULL;

}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code
	stackNode* temp; element e;
	if (isEmpty(S)) {
		printf("ERROR");
		return ERROR;
	}
	else {
		temp = S->top;
		e = temp->data;
		S->top = temp->link;
		free(temp);
		return e;
	}



}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peek(Stack* S) {
	// Fill your code
	if (isEmpty(S)) {
		printf("ERROR");
		return ERROR;
	}
	else return S->top->data;



}

// ������ ��� ��� ��� 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


