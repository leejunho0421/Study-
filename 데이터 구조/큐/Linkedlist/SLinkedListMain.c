#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	L=initList();
	displayList(L);

	printf("\n(2)리스트에 10, 50, 80 노드를 순서대로 삽입하기\n");
	insertFirst(L, 10);
	insert(L, search(L, 10), 50);
	insertLast(L, 80);
	displayList(L);

	printf("\n(3)리스트에서 50 노드 탐색하기\n");
	search(L, 50);
	displayList(L);

	printf("\n(4)50 노드 뒤에 60 노드 삽입하기\n");
	insert(L, search(L,50), 60);	
	displayList(L);

	printf("\n(5)리스트에서 80 노드 삭제하기\n");
	delete(L, search(L,80));
	displayList(L);




	
	clear(L);

	return 0;
}
