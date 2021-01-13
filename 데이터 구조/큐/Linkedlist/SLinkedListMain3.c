#include <stdio.h>

#include "SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 < d2 ? 0 : 1;
}

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)공백리스트 생성하기\n");
	L = initList();
	displayList(L);


	
	setSortRule(L, whoIsPrecede);	// 리스트의 정렬 기준이 되는 함수 등록

	printf("\n(2)리스트에 10, 80, 50 노드를 삽입하되 오름차순으로 들어가도록 하기\n");
	sortInsert(L, 10);
	displayList(L);
	sortInsert(L, 80);
	displayList(L);
	sortInsert(L, 50);



	displayList(L);
	printf("\n(3)리스트에서 50 노드 탐색하기\n");
	p=search(L, 50);
	



	
	printf("\n(4)40 노드 삽입하기(오름차순)\n");
	sortInsert(L, 40);
	displayList(L);




	
	printf("\n(5)리스트에서 80 노드 삭제하기\n");
	delete(L, search(L, 80));
	displayList(L);



	
	clear(L);

	return 0;
}

