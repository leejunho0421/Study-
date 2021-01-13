#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// 공백스택 생성
Stack* create() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// 스택이 포화상태인지 확인하는 연산					
int isFull(Stack* S) {
	return S->top == MAX_SIZE - 1;
}

// 스택이 공백상태인지 확인하는 연산			
int isEmpty(Stack* S) {
	// Fill your code
	return S->top == -1;
}

// 스택의 top에 요소를 추가하는 연산			
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

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산	
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

// 스택에서 마지막에 저장된 요소를 반환하는 연산			
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

// 스택의 모든 요소 출력 			
void displayStack(Stack* S) {
	int i;
	printf("STACK [ "); 
	for(i=0; i<=S->top; i++)
		printf("%d ", S->stack[i]);
	printf(" ]\ttop: %d\n", S->top);
}

// 스택 비우기
void clear(Stack* S) {
	S->top = -1;
}				

