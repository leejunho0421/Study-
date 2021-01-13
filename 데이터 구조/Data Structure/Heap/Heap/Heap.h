#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef int HData;

typedef struct {
	HData heap[MAX_SIZE];
	int numOfData;
}Heap;

Heap* createHeap();					// 공백 힙 생성
int isEmpty(Heap* h);				// 힙이 공백인지 검사
void insertHeap(Heap* h, HData x);	// 힙의 적당한 위치에 원소 x 삽입
HData deleteHeap(Heap* h);			// 힙에서 키 값이 가장 큰 원소 삭제하고 반환

int getParentIdx(int idx);			// 부모 노드의 인덱스 값 반환
int getLChildIdx(int idx);			// 왼쪽 자식 노드의 인덱스 값 반환
int getRChildIdx(int idx);			// 오른쪽 자식 노드의 인덱스 값 반환
void displayHeap(Heap* h);

#endif
