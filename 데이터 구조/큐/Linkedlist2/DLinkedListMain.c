#include <stdio.h>
#include "DLinkedList.h"

int main(){
	linkedList* L;
	listNode* p;
	
	printf("(1)���� ���� ����Ʈ �����ϱ�\n");
	L = initList();
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(2)����Ʈ�� 10 ��带 ù ��° ���� �����ϱ�\n");
	insertFirst(L, 10);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(3)����Ʈ�� 50 ��带 ������ ���� �����ϱ�\n");
	insertLast(L, 50);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(4)����Ʈ�� 5 ��带 ù ��° ���� �����ϱ�\n");
	insertFirst(L, 5);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
		
	printf("\n(5)����Ʈ�� 50 ��� �ڿ� 80 ��带 �����ϱ�\n");
	p = search(L, 50);
	insert(L, p, 80);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(6)80 ��带 �˻��ϰ� �����ϱ�\n");
	p = search(L, 80);
	if(p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);
	if(delete(L, p))
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(7)50 ��� �ڿ� 70 ��� �����ϱ�\n");
	p = search(L, 50);
	insert(L, p, 70);
	displayList(L);
	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	printf("\n(8)10 ��带 �˻��ϰ� �����ϱ�\n");
	p = search(L, 10);
	if(p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("%d ��带 ã�ҽ��ϴ�\n", p->data);
	
	if (delete(L, p))
		printf("��� ���� ����!\n");
	else
		printf("��� ���� ����!\n");
	displayList(L);

	printf("����Ʈ�� ����� ������ ����: %d\n", getLength(L));
	
	return 0;
}

