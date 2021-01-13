#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BinTree* bt = createExpTree(exp);	
	
	printf("전위 표기법의 수식: ");
	showPrefixExp(bt);
	printf("\n");
	
	printf("중위 표기법의 수식: ");
	showInfixExp(bt);
	printf("\n");
	
	printf("후위 표기법의 수식: ");
	showPostfixExp(bt);
	printf("\n");
	
	printf("연산 결과: %d \n", evalExpTree(bt));
	
	return 0;
}
