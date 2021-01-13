#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// 공백덱 생성
Deque* create() {
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// 덱이 포화상태인지 확인하는 연산					
int isFull(Deque* DQ) {
	// Fill your code
	return 0;

}

// 덱이 공백상태인지 확인하는 연산				
int isEmpty(Deque* DQ) {
	// Fill your code
	return DQ->front == NULL;

}

// 덱의 머리에 요소 추가하는 연산			
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

// 덱의 꼬리에 요소 추가하는 연산
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

// 덱의 머리에 위치한 요소 삭제 및 반환하는 연산	
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

// 덱의 꼬리에 위치한 요소 삭제 및 반환하는 연산 		
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

// 덱의 머리에 위치한 요소 반환하는 연산. 삭제 X		
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

// 덱의 꼬리에 위치한 요소 반환하는 연산. 삭제 X		
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

// 덱의 모든 요소 출력		
void displayDeque(Deque* DQ) {
	dequeNode* p = DQ->front;
	printf("Deque [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf(" ]\n");
}

// 덱 비우기 	
void clear(Deque* DQ) {
	dequeNode* p;
	while(DQ->front) {
		p = DQ->front;
		DQ->front = DQ->front->rlink;
		free(p);
		p = NULL;
	}
}				
