#include <stdio.h>
#include "Heap.h"

int main() {
	Heap* h = createHeap();
	
	insertHeap(h, 20);
	insertHeap(h, 15);
	insertHeap(h, 19);
	insertHeap(h, 8);
	insertHeap(h, 13);
	insertHeap(h, 10);	
	displayHeap(h);
	
	printf("(1) 23 삽입\n");
	insertHeap(h, 23);
	displayHeap(h);
	
	printf("(2) 10 삽입\n");
	insertHeap(h, 10);
	displayHeap(h);
	
//	printf("%d\n", deleteHeap(h));
//	displayHeap(h);
	
	printf("(3) Heap 요소 차레로 삭제\n");
	while(!isEmpty(h))
		printf("%d \n", deleteHeap(h));
	
	return 0;	
}
