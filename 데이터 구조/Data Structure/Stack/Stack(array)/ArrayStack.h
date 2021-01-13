#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack을 구조체로 정의
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}Stack;

Stack* create();					// 공백스택 생성
int isFull(Stack* S);				// 스택이 포화상태인지 확인하는 연산
int isEmpty(Stack* S);				// 스택이 공백상태인지 확인하는 연산
void push(Stack* S, element x);		// 스택의 top에 요소를 추가하는 연산
element pop(Stack* S);				// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산
element peek(Stack* S);				// 스택에서 마지막에 저장된 요소를 반환하는 연산
void displayStack(Stack* S);		// 스택의 모든 요소 출력
void clear(Stack* S);				// 스택 비우기 

#endif

