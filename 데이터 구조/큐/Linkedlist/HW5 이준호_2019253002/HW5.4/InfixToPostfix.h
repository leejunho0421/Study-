#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

// 연산자, 피연산자, 괄호를 처리하기 위한 enumeration type 선언 
typedef enum { 
	lparen, rparen, plus, minus, multiply, divide, mod, eos, operand
}precedence;

precedence getToken(char ch);			// 연산자, 피연산자, 괄호 -> enueration type 변환 
char printToken(precedence token);		// enumeration type에 따라 연산자, 괄호 출력 
int prec(precedence symbol);			// 연산자 우선순위 계산: 괄호 < +, - < *, /, % 
char* toPostfix(Stack* S, char* exp);				// 중위표기식 -> 후위표기식 변환 연산 
float evalPostfix(Stack* S, char* exp);			// 후위표기식의 계산 연산 

#endif
