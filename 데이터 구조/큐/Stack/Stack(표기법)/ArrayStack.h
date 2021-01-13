#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ����ü�� ����
typedef struct ArrayStack {
	element stack[MAX_SIZE];
	int top;
}Stack;

Stack* create();					// ���齺�� ����
int isFull(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����
element peek(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayStack(Stack* S);		// ������ ��� ��� ���
void clear(Stack* S);				// ���� ���� 

#endif

