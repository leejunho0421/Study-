#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"		// �迭�� ������ ���� �̿�� �ּ� ����
//#include "LinkedStack.h"		// ���Ḯ��Ʈ�� ������ ���� �̿�� �ּ� ���� 

int testPair(char* exp) {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	char symbol, lparen;
	int i, length = strlen(exp);
	// Fill your code
	lparen = pop(S);
	
	for (i = 0;i < length;i++) {
		symbol = exp[i];
		switch (symbol) {	
		case '(':
			push(S, symbol);
			break;
		case '{':
			push(S, symbol);
			break;
		case '[':
			push(S, symbol);
			break;
		case ')':
			if(pop(S)!='(')
			return FALSE;
			break;
		case '}':
			if (pop(S) != '{')
				return FALSE;
			break;
		case ']':
			if (pop(S) != '[')
				return FALSE;
			break;		
		}		
	}
	if (!isEmpty(S))
		return FALSE;
	return TRUE;
}

int main() {
	int i;
	char* x[4] = {"(A - B) * C) + D", "(A - B) * C + ( D", "A [ B ( C ] )", "{A / (B - C)}"};
	
	for(i=0; i<4; i++) {
		printf("%s ", x[i]);
		if(testPair(x[i]))
			printf("-> ������ ��ȣ�� �ùٸ��� ���Ǿ����ϴ�!\n");
		else
			printf("-> ������ ��ȣ�� Ʋ�Ƚ��ϴ�!\n");
	}
	
	return 0;
}
