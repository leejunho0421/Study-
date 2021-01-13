#include <stdio.h>
#include "DLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)이중 연결 리스트 생성하기\n");
	L = initList();
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(2)리스트에 10 노드를 첫 번째 노드로 삽입하기\n");
	insertFirst(L, 10);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(3)리스트의 50 노드를 마지막 노드로 삽입하기\n");
	insertLast(L, 50);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(4)리스트에 5 노드를 첫 번째 노드로 삽입하기\n");
	insertFirst(L, 5);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
		
	printf("\n(5)리스트의 50 노드 뒤에 80 노드를 삽입하기\n");
	p = search(L, 50);
	insert(L, p, 80);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(6)80 노드를 검색하고 삭제하기\n");
	p = search(L, 80);
	if(p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("%d 노드를 찾았습니다\n", p->data);
	if(delete(L, p))
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(7)50 노드 뒤에 70 노드 삽입하기\n");
	p = search(L, 50);
	insert(L, p, 70);
	displayList(L);
	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	printf("\n(8)10 노드를 검색하고 삭제하기\n");
	p = search(L, 10);
	if(p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("%d 노드를 찾았습니다\n", p->data);
	
	if (delete(L, p))
		printf("노드 삭제 성공!\n");
	else
		printf("노드 삭제 실패!\n");
	displayList(L);

	printf("리스트에 저장된 데이터 개수: %d\n", getLength(L));
	
	return 0;
}

