#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	L=initList();
	displayList(L);

	printf("\n(2)����Ʈ�� 10, 50, 80 ��带 ������� �����ϱ�\n");
	insertFirst(L, 10);
	insert(L, search(L, 10), 50);
	insertLast(L, 80);
	displayList(L);

	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");
	search(L, 50);
	displayList(L);

	printf("\n(4)50 ��� �ڿ� 60 ��� �����ϱ�\n");
	insert(L, search(L,50), 60);	
	displayList(L);

	printf("\n(5)����Ʈ���� 80 ��� �����ϱ�\n");
	delete(L, search(L,80));
	displayList(L);




	
	clear(L);

	return 0;
}
