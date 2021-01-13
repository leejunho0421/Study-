#include <stdio.h>

#include "SLinkedList3.h"

int whoIsPrecede(element d1, element d2) {
	return d1 < d2 ? 0 : 1;
}

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	L = initList();
	displayList(L);


	
	setSortRule(L, whoIsPrecede);	// ����Ʈ�� ���� ������ �Ǵ� �Լ� ���

	printf("\n(2)����Ʈ�� 10, 80, 50 ��带 �����ϵ� ������������ ������ �ϱ�\n");
	sortInsert(L, 10);
	displayList(L);
	sortInsert(L, 80);
	displayList(L);
	sortInsert(L, 50);



	displayList(L);
	printf("\n(3)����Ʈ���� 50 ��� Ž���ϱ�\n");
	p=search(L, 50);
	



	
	printf("\n(4)40 ��� �����ϱ�(��������)\n");
	sortInsert(L, 40);
	displayList(L);




	
	printf("\n(5)����Ʈ���� 80 ��� �����ϱ�\n");
	delete(L, search(L, 80));
	displayList(L);



	
	clear(L);

	return 0;
}

