#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"		// 배열로 구현한 스택 이용시 주석 해제
//#include "LinkedStack.h"		// 연결리스트로 구현한 스택 이용시 주석 해제 
#include "InfixToPostfix.h"

// 연산자, 피연산자, 괄호 -> enueration type 변환
precedence getToken(char ch) {
	precedence token;
	switch(ch) {
		case '(':	token = lparen;		break;
		case ')': 	token = rparen;		break;
		case '+':	token = plus;		break;
		case '-':	token = minus;		break;
		case '*':	token = multiply;	break;
		case '/':	token = divide;		break;
		case '%':	token = mod;		break;
		case '\0':	token = eos;		break;
		default:	token = operand;
	}
	
	return token;
}

// enumeration type에 따라 연산자, 괄호 출력 
char printToken(precedence token) {
	char ch;
	switch(token) {
		case lparen:	ch = '(';	break;
		case rparen:	ch = ')';	break;
		case plus:		ch = '+';	break;
		case minus:		ch = '-';	break;
		case multiply:	ch = '*';	break;
		case divide:	ch = '/';	break;
		case mod:		ch = '%';	break; 
	}
	
	return ch;
}

// 연산자 우선순위 계산: 괄호 < +, - < *, /, % 
int prec(precedence symbol) {
	switch(symbol) {
		case lparen:
		case rparen:	return 0;
		case plus:
		case minus:		return 1;
		case multiply:
		case divide:
		case mod:		return 2;
	}
}

// 중위표기식 -> 후위표기식 변환 연산
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// 연산자의 종류 기록 
	int i = 0;
	int length = strlen(exp);
	// Fill your code
	while ((token=getToken(exp)) == eos) {
		token = getToken(exp);
		if (token ==operand||token==eos) {
			printf("%c", symbol);
			result[n] = pop(S);
		}
		else if (token == rparen) {
			while (peek(S) != '(') {
				result[n] = pop(S);
				n++;
			}
			pop(S);
		}
		else { 
			while (token != lparen && prec(token) <= prec(getToken(peek(S)))) {
				result[n] = pop(S); 
				n++;
			}
			push(S, printToken(token));
		}
		i++;
		symbol = exp[i];

	}
	while (S->top != NULL) {
		result[n] = pop(S); 
		n++;
	
	}
	return result;
}

// 후위표기식의 계산 연산 
float evalPostfix(Stack* S, char* exp) {
	int op1, op2;
	int n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);
	
	// Fill your code
	int x, y, z;
	while (token == getToken(exp) != NULL) {
		if (token == operand) {
			push(S, token);
		}
		else if (token == plus || token == minus || token == divide || token == mod || token == multiply) {
			switch (token) {
			case plus:
				x = pop(S);
				y = pop(S);
				z = y + x;
				push(S, z);
				break;
			case minus:
				x = pop(S);
				y = pop(S);
				z = y - x;
				push(S, z);
				break;
			case divide:
				x = pop(S);
				y = pop(S);
				z = y / x;
				push(S, z);
				break;
			case multiply:
				x = pop(S);
				y = pop(S);
				z = y * x;
				push(S, z);
				break;
			case mod:
				x = pop(S);
				y = pop(S);
				z = y % x;
				push(S, z);
				break;
			}
			
		}
		printf("%c",pop(S));
	}
}
