#include <stdio.h>
#include "ArrayGraph.h"

int main() {
	int i;
	Graph *G1, *G2;

	G1 = createGraph();
	G2 = createGraph();
	
	// ���� �׷��� G1
	for(i=0; i<5; i++)
		insertVertex(G1, i);	// G1�� ���� 0~4 ����
	insertEdge(G1, 0, 1, 10); 
	insertEdge(G1, 0, 2, 5);
	insertEdge(G1, 1, 2, 2);
	insertEdge(G1, 1, 3, 1);
	insertEdge(G1, 2, 1, 3);
	insertEdge(G1, 2, 3, 9);
	insertEdge(G1, 2, 4, 2);
	insertEdge(G1, 3, 4, 4);
	insertEdge(G1, 4, 0, 7);
	insertEdge(G1, 4, 3, 6);
	
	printf("G1 ����ġ ���\n");
	displayGraph(G1);
	printf("\n");
	
	dijkstra(G1, 0);
	printf("G1: ���� ���� 0, Dijkstra Algorithm ���\n");
	for(i=1; i<G1->n; i++) {
		printShortestPath(G1, 0, i);
		printShortestPathCost(G1, 0, i);
	}
	printf("\n");
	
	// ���� �׷��� G2
	for(i=0; i<5; i++)
		insertVertex(G2, i);	// G2�� ���� 0~7 ����
	insertEdge(G2, 0, 1, 6);
	insertEdge(G2, 0, 3, 7);
	insertEdge(G2, 1, 2, 5);
	insertEdge(G2, 1, 3, 8);
	insertEdge(G2, 1, 4, -4);
	insertEdge(G2, 2, 1, -2);
	insertEdge(G2, 3, 2, -3);
	insertEdge(G2, 3, 4, 9);
	insertEdge(G2, 4, 2, 7);
	
	printf("G2 ����ġ ���\n");
	displayGraph(G2);
	printf("\n");
	
	if(bellmanFord(G2, 0)) {
		printf("G2: ���� ���� 0, Bellman-Ford Algorithm ���\n");
		for(i=1; i<G2->n; i++) {
			printShortestPath(G2, 0, i);
			printShortestPathCost(G2, 0, i);
		}
	}
	else
		printf("[ERROR]G2 has negative cycles!");
	printf("\n");
	
	floyd(G1);
	printf("G1: ��� ���� ���� �ִ� ��� ���(Flyod-Warshall Algorithm ���)\n");
	printAllPairShortestCost(G1);
	
	destroyGraph(G1);
	destroyGraph(G2);
		 
	return 0;
}
