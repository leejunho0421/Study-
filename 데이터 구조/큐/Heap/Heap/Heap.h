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

Heap* createHeap();					// ���� �� ����
int isEmpty(Heap* h);				// ���� �������� �˻�
void insertHeap(Heap* h, HData x);	// ���� ������ ��ġ�� ���� x ����
HData deleteHeap(Heap* h);			// ������ Ű ���� ���� ū ���� �����ϰ� ��ȯ

int getParentIdx(int idx);			// �θ� ����� �ε��� �� ��ȯ
int getLChildIdx(int idx);			// ���� �ڽ� ����� �ε��� �� ��ȯ
int getRChildIdx(int idx);			// ������ �ڽ� ����� �ε��� �� ��ȯ
void displayHeap(Heap* h);

#endif
