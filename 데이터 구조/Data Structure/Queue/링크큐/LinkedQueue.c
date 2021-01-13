#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 공백큐 생성
Queue* createQ() {
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

// 큐가 포화상태인지 확인하는 연산				
int isFullQ(Queue* Q) {
	// Fill your code
	return 0;

}

// 큐가 공백상태인지 확인하는 연산			
int isEmptyQ(Queue* Q) {
	// Fill your code
	return Q->front == NULL;
}	

// 큐의 rear에 요소를 추가하는 연산		
void enqueue(Queue* Q, element x) {
	// Fill your code
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode)); 
	newNode->data = x; 
	newNode->link = NULL;
	if (isEmptyQ(Q)) Q->front = newNode; 
	else Q->rear->link = newNode; 
	Q->rear = newNode;




}	

// 큐에서 가장 먼저 저장된 요소 삭제 및 반환하는 연산
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

// 큐에서 가장 먼저 저장된 요소를 반환하는 연산	
element peekQ(Queue* Q) {
	// Fill your code

	if (isEmptyQ(Q)) {
		printf("[ERROR] Queue is EMPTY!!\n"); 
		return ERROR; 
	}
	else return Q->front->data;




}	

// 큐의 모든 요소 출력	
void displayQueue(Queue* Q) {
	queueNode* p = Q->front;
	printf("Queue [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 큐 비우기		
void clearQ(Queue* Q) {
	queueNode* p;
	while(Q->front) {
		p = Q->front;
		Q->front = Q->front->link;
		free(p);
		p = NULL;
	}
}			

