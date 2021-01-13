#ifndef __DEQUE_H__
#define __DEQUE_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0
 
typedef int element;

// Deque�� ��� ������ ����ü�� ����
typedef struct DequeNode {
	element data;
	struct DequeNode* llink;
	struct DequeNode* rlink;
}dequeNode;

// Queue�� front, rear�� ǥ���� ����ü
typedef struct LinkedDeque {
	dequeNode *front, *rear;
}Deque; 

Deque* create();						// ���鵦 ����
int isFull(Deque* DQ);					// ���� ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Deque* DQ);					// ���� ����������� Ȯ���ϴ� ����
void insertFront(Deque* DQ, element x);	// ���� �Ӹ��� ��� �߰��ϴ� ����
void insertRear(Deque* DQ, element x);	// ���� ������ ��� �߰��ϴ� ����
element deleteFront(Deque* DQ);			// ���� �Ӹ��� ��ġ�� ��� ���� �� ��ȯ�ϴ� ����
element deleteRear(Deque* DQ);			// ���� ������ ��ġ�� ��� ���� �� ��ȯ�ϴ� ���� 
element getFront(Deque* DQ);			// ���� �Ӹ��� ��ġ�� ��� ��ȯ�ϴ� ����. ���� X
element getRear(Deque* DQ);				// ���� ������ ��ġ�� ��� ��ȯ�ϴ� ����. ���� X
void displayDeque(Deque* DQ);			// ���� ��� ��� ���
void clear(Deque* DQ);					// �� ���� 

#endif




