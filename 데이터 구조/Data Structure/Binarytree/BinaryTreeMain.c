#include <stdio.h>
#include "BinaryTree.h"

void showData(BTData x) {
	printf("%d ", x);
}

int main() {
	BinTree* root = createBT();
	BinTree* bt1 = createBT();
	BinTree* bt2 = createBT();
	BinTree* bt3 = createBT();
	
	setData(root, 1);
	setData(bt1, 2);
	setData(bt2, 3);
	setData(bt3, 4);
		
	makeLSubtree(root, bt1);
	makeRSubtree(root, bt2);
	makeLSubtree(bt1, bt3);
	
	// #1 root, 왼쪽 자식 노드, 왼쪽 자식 노드의 왼쪽 자식 출력
	printf("=== (1) print ===\n");
	printf("root: %d\n", getData(root));
	printf("left child of root: %d\n", getData(getLSubtree(root)));
	printf("left child of left child of root: %d\n", getData(getLSubtree(getLSubtree(root))));
	 
	// #2 InorderTraverse
	printf("\n=== (2) Inorder Traverse ===\n");
	InorderTraverse(root, showData);
	printf("\n");
	
	// #3 PreorderTraverse
	printf("\n=== (3) Preorder Traverse ===\n");
	PreorderTraverse(root, showData);
	printf("\n");
	
	// #4 PostorderTraverse
	printf("\n=== (4) Postorder Traverse ===\n");
	PostorderTraverse(root, showData);
	printf("\n");
	
	// #5 deleteTree
	printf("\n=== (5) Delete Tree ===\n");
	deleteBT(root);
	printf("\n");
	
	return 0;	
}
