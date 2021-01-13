#include <stdio.h>
#include "SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	L = initList();
	displayList(L);

	
	printf("\n(2)리스트에 월, 화, 목 노드를 순서대로 삽입하기\n");
	insertFirst(L, "월");
	insert(L, search(L, "월"), "화");
	insertLast(L, "목");
	displayList(L);
	 
	printf("\n(3)목 노드 뒤에 일 노드 삽입하기\n");
	insertLast(L, "일");
	displayList(L);



	 
	printf("\n(4)리스트에서 수 노드 탐색하기\n");
	search(L, "수");
	


	
	printf("\n(5)리스트 순서를 역순으로 바꾸기\n");
	reverse(L);

	displayList(L);

	
	clear(L);

	return 0;
}

