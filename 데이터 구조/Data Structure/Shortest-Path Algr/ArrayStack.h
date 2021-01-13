#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_STACK_SIZE 10
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ����ü�� ����
typedef struct ArrayStack {
	element stack[MAX_STACK_SIZE];
	int top;
}Stack;

Stack* createStack();					// ���齺�� ����
int isFullStack(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����
int isEmptyStack(Stack* S);				// ������ ����������� Ȯ���ϴ� ����
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����
element pop(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayStack(Stack* S);		// ������ ��� ��� ���
void clearStack(Stack* S);				// ���� ���� 

#endif

