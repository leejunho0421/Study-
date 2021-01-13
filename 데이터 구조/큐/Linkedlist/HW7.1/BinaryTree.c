#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->data == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->data = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
	// Fill your code
	if (isBTEmpty(bt1)) {
		printf("ERROR");
	}
	else {
		while (bt1->left == NULL) {
			bt1->left = bt2;
		}
	}

}

// bt2�� bt1�� ������ ����Ʈ���� ����
void makeRSubtree(BinTree* bt1, BinTree* bt2) {
	// Fill your code
	if (isBTEmpty(bt1)) {
		printf("ERROR");
	}
	else {
		while (bt1->right == NULL) {
			bt1->right = bt2;	
		}
	}


}

// bt�� ���� ����Ʈ���� ��ȯ
BinTree* getLSubtree(BinTree* bt) {
	// Fill your code
	if (isBTEmpty(bt)) {
		printf("ERROR");
	}
	else {
		return bt->left;
	}
}

// bt�� ������ ����Ʈ���� ��ȯ
BinTree* getRSubtree(BinTree* bt) {
	// Fill your code
	if (isBTEmpty(bt)) {
		printf("ERROR");
	}
	else {
		return bt->right;
	}
}

// bt�� root ��忡 x �� ����
void setData(BinTree* bt, BTData x) {
	// Fill your code
	bt->data = x;

}

// bt�� root�� ����� �����͸� ��ȯ
BTData getData(BinTree* bt) {
	// Fill your code
	return bt->data;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->data);
	free(bt);
}

// ���� ��ȸ 
void InorderTraverse(BinTree* bt, visitFuncPtr action) { 
	// Fill your code
	if (bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->data);
		InorderTraverse(bt->right, action);
	}
}

// ���� ��ȸ
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {
	// Fill your code
	if (bt != NULL) {
		action(bt->data);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}
}

// ���� ��ȸ
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {
	// Fill your code
	if (bt != NULL) {
		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->data);
	}
}

