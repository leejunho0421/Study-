#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// ���鵦 ����
Deque* create() {
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ���� ��ȭ�������� Ȯ���ϴ� ����					
int isFull(Deque* DQ) {
	// Fill your code
	return 0;

}

// ���� ����������� Ȯ���ϴ� ����				
int isEmpty(Deque* DQ) {
	// Fill your code
	return DQ->front == NULL;

}

// ���� �Ӹ��� ��� �߰��ϴ� ����			
void insertFront(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
	newNode->data = x;
	
	if (isEmpty(DQ)) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;

	}	
	

	

}

// ���� ������ ��� �߰��ϴ� ����
void insertRear(Deque* DQ, element x) {
	// Fill your code
	dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
	newNode->data = x;
	
	if (isEmpty(DQ)) {
		DQ->rear = newNode;
		DQ->front = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->llink = DQ->rear;
		newNode->rlink = NULL;
		DQ->rear = newNode;

	}
		
	


}

// ���� �Ӹ��� ��ġ�� ��� ���� �� ��ȯ�ϴ� ����	
element deleteFront(Deque* DQ) {
	// Fill your code
	dequeNode* temp = DQ->front;
	element item;

	if (isEmpty(DQ)) {
		printf("[ERROR] DeQueue is EMPTY!!\n");

		return 0;
	}
	else {
		
		item = temp->data;
		DQ->front = DQ->front->rlink;
		DQ->front->llink = NULL;
		free(temp);
	}
	return item;


}

// ���� ������ ��ġ�� ��� ���� �� ��ȯ�ϴ� ���� 		
element deleteRear(Deque* DQ) {
	// Fill your code
	dequeNode* temp = DQ->rear;
	element item = DQ->rear->data;
	if (isEmpty(DQ)) {
		printf("[ERROR] DeQueue is EMPTY!!\n");

		return ERROR;
	}
	else {
		item = temp->data;
		DQ->rear = DQ->rear->llink;
		DQ->rear->rlink = NULL;
		free(temp);
	}
	return item;
}

// ���� �Ӹ��� ��ġ�� ��� ��ȯ�ϴ� ����. ���� X		
element getFront(Deque* DQ) {
	// Fill your code
	element item;
	if (isEmpty(DQ)) {
		return FALSE;
	}
	else {
		item = DQ->front->data;
	}
	return item;

}

// ���� ������ ��ġ�� ��� ��ȯ�ϴ� ����. ���� X		
element getRear(Deque* DQ) {
	// Fill your code
	element item;
	if (isEmpty(DQ)) {
		return FALSE;
	}
	else {
		item = DQ->rear->data;
	}
	return item;
}	

// ���� ��� ��� ���		
void displayDeque(Deque* DQ) {
	dequeNode* p = DQ->front;
	printf("Deque [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// �� ���� 	
void clear(Deque* DQ) {
	dequeNode* p;
	while(DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}				
