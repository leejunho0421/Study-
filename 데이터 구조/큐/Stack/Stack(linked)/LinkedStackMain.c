#include <stdio.h>
#include "LinkedStack.h"

int main() {
	Stack* S;
	element item;
	int i;
	
	printf("(1) ���� ���� �����ϱ�\n");
	S = create();
	displayStack(S);
	
	printf("\n(2) ���ÿ� 10, 20, 30�� ���ʷ� ����\n");
	// Fill your code
	push(S, 10);
	displayStack(S);
	push(S, 20);
	displayStack(S);
	push(S, 30);
	displayStack(S);
	
	printf("\n(3) ���� top�� ��Ҹ� ���\n");
	// Fill your code
	peek(S);
	displayStack(S);


	printf("\n(4-1) ���ÿ��� ��һ���\n");
	// Fill your code
	pop(S, 30);
	displayStack(S);
	printf("\n(4-2) ���ÿ��� ��һ���\n");
	pop(S, 20);
	displayStack(S);
	printf("\n(4-3) ���ÿ��� ��һ���\n");
	pop(S, 10);
	displayStack(S);
	printf("\n(4-4) ���ÿ��� ��һ���\n");
	pop(S, 30);
	displayStack(S);
	
	printf("\n(5) ���� ����\n");
	clear(S);
	displayStack(S);
	
	return 0;
}

