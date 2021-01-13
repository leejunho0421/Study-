#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

// 공백스택 생성
Stack* createStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;
	return S;
}

// 스택이 포화상태인지 확인하는 연산					
int isFullStack(Stack* S) {
	// Fill your code
	return S->top == MAX_STACK_SIZE - 1;
}

// 스택이 공백상태인지 확인하는 연산			
int isEmptyStack(Stack* S) {
	// Fill your code
	return S->top == -1;
}

// 스택의 top에 요소를 추가하는 연산			
void push(Stack* S, element x) {
	// Fill your code
	if(isFullStack(S)) {
		printf("Stack is FULL!!\n");
		return;
	}
	else
		S->stack[++(S->top)] = x;
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산	
element pop(Stack* S) {
	// Fill your code
	if(isEmptyStack(S)) {
		printf("[ERROR] Stack is EMPTY!!\n");
		return ERROR;
	}
	else
		return S->stack[(S->top)--];
}

// 스택에서 마지막에 저장된 요소를 반환하는 연산			
element peek(Stack* S) {
	// Fill your code
	if(isEmptyStack(S)) {
		
		return ERROR;
	}
	else
		return S->stack[S->top];
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
void clearStack(Stack* S) {
	S->top = -1;
}				

