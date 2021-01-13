#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define TRUE 1
#define FALSE 0
#define EMPTY 123456789

typedef int BTData;

typedef struct BinaryTreeNode {
	BTData key;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinTree;

BinTree* createBT();			// ���� ���� Ʈ�� ���� ����
int isBTEmpty(BinTree* bt);		// ���� Ʈ���� ����ִ��� �˻��ϴ� ����
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2); 	// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ
void makeLSubtree(BinTree* bt1, BinTree* bt2);		// bt2�� bt1�� ���� ����Ʈ���� ����
void makeRSubtree(BinTree* bt1, BinTree* bt2);		// bt2�� bt1�� ������ ����Ʈ���� ����
BinTree* getLSubtree(BinTree* bt);		// bt�� ���� ����Ʈ���� ��ȯ
BinTree* getRSubtree(BinTree* bt);		// bt�� ������ ����Ʈ���� ��ȯ
void setData(BinTree* bt, BTData x);	// bt�� root ��忡 x �� ����
BTData getData(BinTree* bt);			// bt�� root�� ����� �����͸� ��ȯ
void deleteBT(BinTree* bt);	// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�

typedef void visitFuncPtr(BTData x);						// ��� �湮�� action ���� 
void InorderTraverse(BinTree* bt, visitFuncPtr action);		// ���� ��ȸ 
void PreorderTraverse(BinTree* bt, visitFuncPtr action);	// ���� ��ȸ 
void PostorderTraverse(BinTree* bt, visitFuncPtr action);	// ���� ��ȸ 

BinTree* searchBST(BinTree* bt, BTData x);	// ������ x�� ����� ��� Ž��
void insertBST(BinTree* bt, BTData x);		// ������ x ����
void deleteBST(BinTree* bt, BTData x);	// ������ x ��� ���� 

#endif
