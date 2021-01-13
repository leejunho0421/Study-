#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define MAX_SIZE 100
#define ERROR 123456789
#define TRUE 1
#define FALSE 0
 
typedef int element;

// Queue�� ����ü�� ����
typedef struct CircularQueue {
	element queue[MAX_SIZE];
	int front, rear;
}Queue;

Queue* create();					// ����ť ����
int isFull(Queue* Q);				// ť�� ��ȭ�������� Ȯ���ϴ� ����
int isEmpty(Queue* Q);				// ť�� ����������� Ȯ���ϴ� ����
void enqueue(Queue* Q, element x);	// ť�� rear�� ��Ҹ� �߰��ϴ� ����
element dequeue(Queue* Q);			// ť���� ���� ���� ����� ��� ���� �� ��ȯ�ϴ� ����
element peek(Queue* Q);				// ť���� ���� ���� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayQueue(Queue* Q);		// ť�� ��� ��� ���
void clear(Queue* Q);				// ť ���� 

#endif


