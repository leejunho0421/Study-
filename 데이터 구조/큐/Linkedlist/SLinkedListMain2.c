#include <stdio.h>
#include "SLinkedList2.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���鸮��Ʈ �����ϱ�\n");
	L = initList();
	displayList(L);

	
	printf("\n(2)����Ʈ�� ��, ȭ, �� ��带 ������� �����ϱ�\n");
	insertFirst(L, "��");
	insert(L, search(L, "��"), "ȭ");
	insertLast(L, "��");
	displayList(L);
	 
	printf("\n(3)�� ��� �ڿ� �� ��� �����ϱ�\n");
	insertLast(L, "��");
	displayList(L);



	 
	printf("\n(4)����Ʈ���� �� ��� Ž���ϱ�\n");
	search(L, "��");
	


	
	printf("\n(5)����Ʈ ������ �������� �ٲٱ�\n");
	reverse(L);

	displayList(L);

	
	clear(L);

	return 0;
}

