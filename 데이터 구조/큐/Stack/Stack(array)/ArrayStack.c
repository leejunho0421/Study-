#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Stack* S) {
	return S->top == MAX_SIZE - 1;
}

// ������ ����������� Ȯ���ϴ� ����			
int isEmpty(Stack* S) {
	// Fill your code
	return S->top == -1;
}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code
	if (isFull(S)) {
		printf("error");
		return;
	}
	else {
		S->top += 1;
		S->stack[S->top] = x;
	}



}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code
	if (isEmpty(S)) {
		printf("error");
		return ERROR;
	}
	else {
		element e = S->stack[S->top];
		S->top -= 1;
		return e;

	}



}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peek(Stack* S) {
	// Fill your code
	if (isEmpty(S)) {
		printf("error");
		return ERROR;
	}
	else {
		return S->stack[S->top];
	}



}

// ������ ��� ��� ��� 			
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// ���� ����
void clear(Stack* S) {
	S->top = -1;
}				

