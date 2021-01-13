#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BinTree* bt = createExpTree(exp);	
	
	printf("���� ǥ����� ����: ");
	showPrefixExp(bt);
	printf("\n");
	
	printf("���� ǥ����� ����: ");
	showInfixExp(bt);
	printf("\n");
	
	printf("���� ǥ����� ����: ");
	showPostfixExp(bt);
	printf("\n");
	
	printf("���� ���: %d \n", evalExpTree(bt));
	
	return 0;
}
