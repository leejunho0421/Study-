#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ����ť ����
Queue* createQ() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// ť�� ��ȭ�������� Ȯ���ϴ� ����				
int isFullQ(Queue* Q) {
	// Fill your code
	return 0;

}

// ť�� ����������� Ȯ���ϴ� ����			
int isEmptyQ(Queue* Q) {
	// Fill your code
	return Q->front == NULL;
}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����		
void enqueue(Queue* Q, element x) {
	// Fill your code
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode)); 
	newNode->data = x; 
	newNode->link = NULL;
	if (isEmptyQ(Q)) Q->front = newNode; 
	else Q->rear->link = newNode; 
	Q->rear = newNode;




}	

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element dequeue(Queue* Q) {
	// Fill your code
	queueNode* temp; element e;
	if (isEmptyQ(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n");

		return ERROR;
	}
	else {
		temp = Q->front; 
		e = temp->data;
		Q->front = temp->link;
		free(temp);
	}
	if (Q->front == NULL) {
		Q->rear = NULL;
			return e;
	}
	
}

// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����	
element peekQ(Queue* Q) {
	// Fill your code

	if (isEmptyQ(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n"); 
		return ERROR; 
	}
	else return Q->front->data;




}	

// ť�� ��� ��� ���	
void displayQueue(Queue* Q) {
	queueNode* p = Q->front;
	printf("Queue [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ť ����		
void clearQ(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

