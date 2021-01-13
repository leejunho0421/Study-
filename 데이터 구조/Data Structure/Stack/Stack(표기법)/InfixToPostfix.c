#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"		// �迭�� ������ ���� �̿�� �ּ� ����
//#include "LinkedStack.h"		// ���Ḯ��Ʈ�� ������ ���� �̿�� �ּ� ���� 
#include "InfixToPostfix.h"

// ������, �ǿ�����, ��ȣ -> enueration type ��ȯ
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

// enumeration type�� ���� ������, ��ȣ ��� 
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

// ������ �켱���� ���: ��ȣ < +, - < *, /, % 
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

// ����ǥ��� -> ����ǥ��� ��ȯ ����
char* toPostfix(Stack* S, char* exp) {
	static char result[256] = "";
	int len = 0, n = 0;
	char symbol = exp[0];
	precedence token = getToken(symbol);		// �������� ���� ��� 
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

// ����ǥ����� ��� ���� 
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
