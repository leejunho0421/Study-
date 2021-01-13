#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ���� ���� Ʈ�� ���� ����
BinTree* createBT(){
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = EMPTY;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

// ���� Ʈ���� ����ִ��� �˻��ϴ� ����
int isBTEmpty(BinTree* bt) {
	if(bt->left == NULL && bt->right == NULL && bt->key == EMPTY)
		return TRUE;
	else
		return FALSE;
}

// ���� ����Ʈ���� bt1, ������ ����Ʈ���� bt2, x���� ������ ��带 ��Ʈ�� �ϴ� ����Ʈ�� ��ȯ
BinTree* makeBT(BinTree* bt1, BTData x, BinTree* bt2) {
	BinTree* bt = (BinTree*)malloc(sizeof(BinTree));
	bt->key = x;
	bt->left = bt1;
	bt->right = bt2;
	return bt;
}

// bt2�� bt1�� ���� ����Ʈ���� ����
void makeLSubtree(BinTree* bt1, BinTree* bt2) {
	// Fill your code
	// HW #7.1
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
	// HW #7.1
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
	// HW #7.1
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
	// HW #7.1
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
	// HW #7.1
	bt->key = x;
}

// bt�� root�� ����� �����͸� ��ȯ
BTData getData(BinTree* bt) {
	// Fill your code
	// HW #7.1
	return bt->key;
}

// bt�� ����Ű�� ��带 ��Ʈ�� �ϴ� Ʈ�� ���� �Ҹ�
void deleteBT(BinTree* bt) {
	if(bt == NULL)
		return;
	
	deleteBT(bt->left);
	deleteBT(bt->right);
	
	printf("delete tree data: %d \n", bt->key);
	free(bt);
}

// ���� ��ȸ 
void InorderTraverse(BinTree* bt, visitFuncPtr action) {
	// Fill your code
	// HW #7.1
	if (bt != NULL) {
		InorderTraverse(bt->left, action);
		action(bt->key);
		InorderTraverse(bt->right, action);
	}
}

// ���� ��ȸ
void PreorderTraverse(BinTree* bt, visitFuncPtr action) {
	// Fill your code
	// HW #7.1
	if (bt != NULL) {
		action(bt->key);
		PreorderTraverse(bt->left, action);
		PreorderTraverse(bt->right, action);
	}
}

// ���� ��ȸ
void PostorderTraverse(BinTree* bt, visitFuncPtr action) {
	// Fill your code
	// HW #7.1
	if (bt != NULL) {
		PostorderTraverse(bt->left, action);
		PostorderTraverse(bt->right, action);
		action(bt->key);
	}
}

// ������ x�� ����� ��� Ž��
BinTree* searchBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	
	// Fill your code
	if (p == NULL) {
		return NULL;
	}
	if (x == p->key) {
		return p;
	}
	if (x < p->key) {
		return searchBST(p->left, x);
	}
	else return searchBST(p->right, x);


}

// ������ x ����
void insertBST(BinTree* bt, BTData x) {
	BinTree* p = bt;
	BinTree* parent = NULL;

	// ������ ��� Ž��
	// Fill your code
	while (p != NULL) {
		if (x == p->key)
			return;

		parent = p;

		if (x < p->key)
			p = p->left;
		else p = p->right;
	}



	// ������ ��� ����
	// Fill your code
	BinTree* newNode = createBT();
	newNode->key = x;


	// ���� ��� ����
	// Fill your code
		if (bt == NULL) {
			bt = newNode;
		}
		else if (x < parent->key) {
			parent->left = newNode;
		}
		else parent->right = newNode;
	
}

// ������ x ��� ����	
void deleteBST(BinTree* bt, BTData x) {
	// Fill your code
	BinTree* p = bt;
	BinTree* parent = bt;

	searchBST(bt,x);
	if (p == NULL) {
		return;
	}
	//case1
	if (p->left == NULL && p->right == NULL) {
		if (parent->left == p) {
			parent->left == NULL;
		}
		else parent->right = NULL;
	}
	//case2
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {
			if (parent->left == p) {
				parent->left = p->left;
			}
			else parent->right = p->left;
		}
		else {
			if (parent->left == p) {
				parent->left = p->right;
			}
			else parent->right = p->right;
		}
	}
	//case3
	else if (p->left != NULL && p->right != NULL) {
		BinTree* q = p->left;
		BTData temp;
		while (1) {
			if (q->left == NULL && q->right == NULL) {
				temp = p->key;
				break;
			}
			if (q->right != NULL)
				q = q->right;

		}
		p->key = q->key;
		q->key = temp;
		deleteBST(p->left, q->key);
	}
}	

