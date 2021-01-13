#ifndef __S_LINKED_LIST3_H__
#define __S_LINKED_LIST3_H__

#define TRUE 1
#define FALSE 0

typedef int element;

// �ܼ����Ḯ��Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct LinkedList {
	listNode* head;
	int length;
	int (*comp)(element d1, element d2);				// ���� ������ ����ϱ� ���� ���
}linkedList;

linkedList* initList();		// ���鸮��Ʈ ���� 
int getLength(linkedList* L);							// ����Ʈ�� ����Ǿ� �ִ� �������� �� ��ȯ 
void displayList(linkedList* L);						// ����Ʈ�� ��� ��� ���
void clear(linkedList* L);								// ����Ʈ�� ��ü �޸� ���� 
void setSortRule(linkedList* L, int (*comp)(element d1, element d2));	// ���� ���� �Լ� ��� 
void sortInsert(linkedList* L, element x);				// ��� ���Խ� ���� ���ؿ� ���� ����
int delete(linkedList* L, listNode* p);					// ��� ���� 
listNode* search(linkedList* L, element x);				// �˻�  

#endif

