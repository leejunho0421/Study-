#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// 공백스택 생성
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// 스택이 포화상태인지 확인하는 연산					
int isFull(Stack* S) {
	return 0;

}

// 스택이 공백상태인지 확인하는 연산			
int isEmpty(Stack* S) {
	return S->top == NULL;

}

// 스택의 top에 요소를 추가하는 연산			
void push(Stack* S, element x) {
	// Fill your code
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->data = x;
	newNode->link = S->top;
	S->top = newNode;
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산	
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

// 스택에서 마지막에 저장된 요소를 반환하는 연산			
element peek(Stack* S) {
	// Fill your code
	if (isEmpty(S)) {
		printf("ERROR");
		return ERROR;
	}
	else return S->top->data;



}

// 스택의 모든 요소 출력 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 스택 비우기
void clear(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


