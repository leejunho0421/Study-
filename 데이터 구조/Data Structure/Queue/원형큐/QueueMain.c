#include <stdio.h>
#include "CircularQueue.h"

int main() {
	Queue* Q;
	element item;
	int i;
	
	printf("(1) ���� ť �����ϱ�\n");
	Q = create();
	displayQueue(Q);
	
	printf("\n(2) ť�� 10, 20, 30�� ���ʷ� ����\n");
	enqueue(Q, 10);
	displayQueue(Q);
	enqueue(Q, 20);
	displayQueue(Q); 
	enqueue(Q, 30);
	displayQueue(Q);
	
	printf("\n(3) ���� ���� ���Ե� ��Ҹ� ���\n");
	item = peek(Q);
	if(item != ERROR)
		printf("���� ���� ���Ե� ���: %d\n", item);
	displayQueue(Q);
	
	printf("\n(4) ������ ���� 4�� ����\n");
	for(i=0; i<4; i++){
		item = dequeue(Q);
		if(item != ERROR) {
			printf("%d ����\n", item);
			displayQueue(Q);
		}
		else {
			displayQueue(Q);
			break;
		}
	}

	printf("\n(5) ť ����\n");
	clear(Q);
	displayQueue(Q);
	return 0;	
}
