#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ��� ������ ����ü�� ����
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack�� ������ ���(���� �ֱٿ� ���Ե� ���)�� ��Ÿ���� top�� ����ü�� ���� 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* create();					// ���齺�� ����
int getLength(Stack* S);			// ���ÿ� ����� ��� ������ ��ȯ�ϴ� ���� 
int isFull(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����
element peek(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayStack(Stack* S);		// ������ ��� ��� ���
void clear(Stack* S);				// ���� ���� 

#endif


