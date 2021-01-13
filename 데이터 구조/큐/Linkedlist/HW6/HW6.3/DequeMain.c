#include <stdio.h>
#include "Deque.h"

int main() {
	Deque* DQ;
	element e;
	int i;
	
	printf("== Deque �����ϱ�==\n");
	DQ = create();
	displayDeque(DQ);
	
	printf("\n== front ���� 10 ==\n");
	insertFront(DQ, 10);	displayDeque(DQ);
	printf("\n== front ���� 20 ==\n");
	insertFront(DQ, 20);	displayDeque(DQ);
	printf("\n== rear ���� 30 ==\n");
	insertRear(DQ, 30);	displayDeque(DQ);
	printf("\n== front ����==\n");
	e = deleteFront(DQ);	displayDeque(DQ);
	if(e != ERROR)	printf("���� ������: %d\n", e);
	printf("\n== rear ����==\n");
	e = deleteRear(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("���� ������: %d\n", e);
	printf("\n== rear ���� 40 ==\n");
	insertRear(DQ, 40);	displayDeque(DQ);
	printf("\n== front ���� 50 ==\n");
	insertFront(DQ, 50);	displayDeque(DQ);
	
	printf("\n== front �˻�==\n");
	e = getFront(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("front ������: %d\n", e);
	printf("\n== rear �˻�==\n");
	e = getRear(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("rear ������: %d\n", e);
	printf("\n== Deque ���� ==\n");
	clear(DQ);	displayDeque(DQ);	
	
	return 0;
}
