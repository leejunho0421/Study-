#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinaryTree.h"
#include "LinkedStack.h"

BinTree* createExpTree(char exp[]) {
	Stack* S = createStack();
	BinTree* bNode;
	int expLen = strlen(exp);
	int i;
	
	// Fill your code


	for (i = 0;i < expLen;i++) {
		bNode = createBT();
		bNode->data = exp[i];
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			makeRSubtree(bNode,pop(S));
			makeLSubtree(bNode, pop(S));
			setData(bNode, exp[i]);
		}
		else {
			setData(bNode, exp[i]-'0');
		}
		push(S, bNode);
	}
	return pop(S);
}

int evalExpTree(BinTree* bt) {
	int op1, op2;
	
	// Fill your code
	if (getLSubtree(bt) == NULL && getRSubtree(bt) == NULL)
		return getData(bt);

	op1 = evalExpTree(getLSubtree(bt));
	op2 = evalExpTree(getRSubtree(bt));
	switch (getData(bt)) {
	case '+': 
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '/': 
		return op1 / op2;
	case '*':
		return op1 * op2;
	}	

	return 0;
}

void showNodeData(int x) {
	if(0<=x && x<=9)			// 피연산자 출력 
		printf("%d ", x);
	else						// 연산자 출력 
		printf("%c ", x);
}

void showPrefixExp(BinTree* bt) { //전위 : 중왼오
	// Fill your code
	
		PreorderTraverse(bt, showNodeData);

}

void showInfixExp(BinTree* bt) { //중위 : 왼중오
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
	
	showInfixExp(bt->left);		// 첫 번째 피연산자 출력
	showNodeData(bt->data);		// 연산자 출력
	showInfixExp(bt->right);	// 두 번째 피연산자 출력
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ) "); 
}

void showPostfixExp(BinTree* bt) { //후위 : 왼중오
	// Fill your code
	PostorderTraverse(bt, showNodeData);
}
