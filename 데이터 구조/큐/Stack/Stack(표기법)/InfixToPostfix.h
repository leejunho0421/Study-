#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

// ������, �ǿ�����, ��ȣ�� ó���ϱ� ���� enumeration type ���� 
typedef enum { 
	lparen, rparen, plus, minus, multiply, divide, mod, eos, operand
}precedence;

precedence getToken(char ch);			// ������, �ǿ�����, ��ȣ -> enueration type ��ȯ 
char printToken(precedence token);		// enumeration type�� ���� ������, ��ȣ ��� 
int prec(precedence symbol);			// ������ �켱���� ���: ��ȣ < +, - < *, /, % 
char* toPostfix(Stack* S, char* exp);				// ����ǥ��� -> ����ǥ��� ��ȯ ���� 
float evalPostfix(Stack* S, char* exp);			// ����ǥ����� ��� ���� 

#endif
