#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_STACK_SIZE 10
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack을 구조체로 정의
typedef struct ArrayStack {
	element stack[MAX_STACK_SIZE];
	int top;
}Stack;

Stack* createStack();					// 공백스택 생성
int isFullStack(Stack* S);				// 스택이 포화상태인지 확인하는 연산
int isEmptyStack(Stack* S);				// 스택이 공백상태인지 확인하는 연산
void push(Stack* S, element x);		// 스택의 top에 요소를 추가하는 연산
element pop(Stack* S);				// 스택에서 마지막에 저장된 요소를 반환하는 연산
void displayStack(Stack* S);		// 스택의 모든 요소 출력
void clearStack(Stack* S);				// 스택 비우기 

#endif

