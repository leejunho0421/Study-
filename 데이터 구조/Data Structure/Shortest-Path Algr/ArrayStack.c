#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// ���齺�� ����
Stack* createStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isFullStack(Stack* S) {
	// Fill your code
	return S->top == MAX_STACK_SIZE - 1;
}

// ������ ����������� Ȯ���ϴ� ����			
int isEmptyStack(Stack* S) {
	// Fill your code
	return S->top == -1;
}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code
	if(isFullStack(S)) {
		printf("Stack is FULL!!\n");
		return;
	}
	else
		S->stack[++(S->top)] = x;
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code
	if(isEmptyStack(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else
		return S->stack[(S->top)--];
}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peek(Stack* S) {
	// Fill your code
	if(isEmptyStack(S)) {
		
		return ERROR;
	}
	else
		return S->stack[S->top];
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
void clearStack(Stack* S) {
	S->top = -1;
}				

