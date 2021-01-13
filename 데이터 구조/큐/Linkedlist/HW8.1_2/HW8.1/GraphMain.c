#include <stdio.h>
#include "ArrayGraph.h"

int main() {
	int i;
	Graph *G1, *G2, *G3, *G4;
	G1 = createGraph(UNDIRECT);
	G2 = createGraph(DIRECT);
	G3 = createGraph(UNDIRECT);
	G4 = createGraph(DIRECT);
	
	// ������ �׷��� G1
	for(i=0; i<4; i++)
		insertVertex(G1, i);	// G1�� ���� 0~3 ����
	insertEdge(G1, 0, 1);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 2, 3);
	printf("G1�� �������\n");
	displayGraph(G1);
	
	deleteVertex(G1, 2);
	printf("G1�� �������\n");
	displayGraph(G1);
	
	// ���� �׷��� G2 
	for(i=0; i<4; i++)
		insertVertex(G2, i);	// G2�� ���� 0~3 ����
	insertEdge(G2, 0, 1);
	insertEdge(G2, 0, 3);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 3);
	insertEdge(G2, 2, 3);
	printf("G2�� �������\n");
	displayGraph(G2);
	
	deleteVertex(G2, 2);
	printf("G2�� �������\n");
	displayGraph(G2);
	
	// ������ �׷��� G3
	for(i=0; i<3; i++)
		insertVertex(G3, i);	// G3�� ���� 0~2 ����
	insertEdge(G3, 0, 1);
	insertEdge(G3, 0, 2);
	insertEdge(G3, 1, 2);
	printf("G3 �������\n");
	displayGraph(G3);
	
	deleteEdge(G3, 0, 1);
	printf("G3 �������\n");
	displayGraph(G3);
	
	// ������ �׷��� G4
	for(i=0; i<3; i++)
		insertVertex(G4, i);	// G4�� ���� 0~2 ����
	insertEdge(G4, 0, 1);
	insertEdge(G4, 0, 2);
	insertEdge(G4, 1, 2);
	printf("G4 �������\n");
	displayGraph(G4);
	
	deleteEdge(G4, 0, 1);
	printf("G4 �������\n");
	displayGraph(G4);
	
	destroyGraph(G1);
	destroyGraph(G2);
	destroyGraph(G3);
	destroyGraph(G4);
	 
	return 0;
}
