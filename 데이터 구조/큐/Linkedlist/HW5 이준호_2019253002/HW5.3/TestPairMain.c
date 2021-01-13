#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"		// 배열로 구현한 스택 이용시 주석 해제
//#include "LinkedStack.h"		// 연결리스트로 구현한 스택 이용시 주석 해제 

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
			printf("-> 수식의 괄호가 올바르게 사용되었습니다!\n");
		else
			printf("-> 수식의 괄호가 틀렸습니다!\n");
	}
	
	return 0;
}
