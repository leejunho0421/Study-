#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// ����ť ����
Queue* create() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// ť�� ��ȭ�������� Ȯ���ϴ� ����				
int isFull(Queue* Q) {
	// Fill your code
	if (Q->rear + 1 % MAX_SIZE == Q->front) {
		return 1;
	}
	else return 0;
}

// ť�� ����������� Ȯ���ϴ� ����			
int isEmpty(Queue* Q) {
	// Fill your code
	if (Q->front == Q->rear) {
		return 1;
	}
	else return 0;
}	

// ť�� rear�� ��Ҹ� �߰��ϴ� ����		
void enqueue(Queue* Q, element x) {
	// Fill your code
	
	if (isFull(Q)) {
	
		printf("ERROR");
		return ;
	
	}
	else {
		Q->rear = Q->rear + 1 % MAX_SIZE;
		
		Q->queue[Q->rear] = x;
		return;
	}


}	

// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element dequeue(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		printf("ERROR\n");
		return ; 
	}
	else {
		Q->front = Q->front + 1 % MAX_SIZE;
		return Q->queue[Q->front];
	}


}

// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����	
element peek(Queue* Q) {
	// Fill your code
	if (isEmpty(Q)) {
		return ;
	}
	else {
		return Q->queue[Q->front + 1%MAX_SIZE];
	}


}	

// ť�� ��� ��� ���	
void displayQueue(Queue* Q) {
	int i, first, rear;
	first = (Q->front+1) % MAX_SIZE;
	rear = (Q->rear+1) % MAX_SIZE;
	i = first;
	printf("QUEUE [ ");
	while(i != rear) {
		printf("%d ", Q->queue[i]);
		i = (i+1) % MAX_SIZE;
	}
	printf(" ]\tfront: %d\trear: %d\n", Q->front, Q->rear);
}

// ť ����		
void clear(Queue* Q) {
	Q->rear = Q->front;
}			
