#ifndef __POLY_LINKED_LIST_H__
#define __POLY_LINKED_LIST_H__

typedef struct PolyNode {
	float coef;
	int exp;
	struct PolyNode* link;
}Node;

typedef struct PolyList {
	Node* head;
	Node* last;
}polyList;

polyList* initList();		// ���鸮��Ʈ ���� 
void appendTerm(polyList* PL, float coef, int exp);		// ���׽� ����Ʈ ������ ���� �� �߰� 
polyList* addPoly(polyList* A, polyList* B);			// �� ���׽��� ���� 
void displayPoly(polyList* PL);							// ���׽� ����Ʈ�� ��� ��� ���

#endif
