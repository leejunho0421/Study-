#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"		// 배열로 구현한 스택 이용시 주석 해제
//#include "LinkedStack.h"		// 연결리스트로 구현한 스택 이용시 주석 해제 
#include "InfixToPostfix.h"

int main() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S = create();
	
	int result, i;
	char* x[3] = {"5+4*2", "(2+4)*3", "3*(5+2)*4"};
	char* postExp;
	
	for(i=0; i<3; i++) {
		postExp = toPostfix(S, x[i]);
		printf("%s -> %s\n", x[i], postExp);
		
		result = evalPostfix(S, postExp);
		printf("연산결과 => %d\n\n", result);
		
	}	
	
	return 0;
}
