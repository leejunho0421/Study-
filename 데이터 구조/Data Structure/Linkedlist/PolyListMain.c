#include <stdio.h>
#include "PolyList.h"

int main(){
	polyList *A = initList();
	polyList *B = initList();
	polyList *C = initList();
	
	// A(x) = 4x^3 + 3x^2 + 5x
	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	printf("A(x) = ");
	displayPoly(A);
	
	// B(x) = 3x^4 + x^3 + 2x + 1
	appendTerm(B, 3, 4);
	appendTerm(B, 1, 3);
	appendTerm(B, 2, 1);
	appendTerm(B, 1, 0);
	printf("B(x) = ");
	displayPoly(B);
	
	// C(x) = A(x) + B(x)
	C = addPoly(A, B);
	printf("C(x) = ");
	displayPoly(C);
	
	return 0;
}


