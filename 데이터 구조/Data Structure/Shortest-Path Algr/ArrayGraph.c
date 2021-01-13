#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"
#include "ArrayStack.h"

// ���� �׷����� �����ϴ� ����
Graph* createGraph() {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	for(i=0; i<MAX_SIZE; i++) {
		for(j=0; j<MAX_SIZE; j++) {
			if(i==j)
				G->cost[i][j] = 0;
			else
				G->cost[i][j] = INF;
			G->A[i][j] = INF;
		}
		G->dist[i] = INF;
		G->pred[i] = NONE;
		G->S[i] = 0;
	}
	return G;
}

// �׷����� �������� �˻�	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// �׷��� G�� ���� v�� ����
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] �׷��� ������ ���� �ʰ�\n");
		return;
	}
	G->n++;
}

// �׷��� G�� ����(u, v)�� ����
void insertEdge(Graph* G, int u, int v, int weight) {
	G->cost[u][v] = weight;	
}

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����
void deleteVertex(Graph* G, int v) {
	int i;
	for(i=0; i<G->n; i++) {
		G->cost[i][v] = INF;
		G->cost[v][i] = INF;
	}	
}

// �׷��� G�� ���� (u, v)�� ����
void deleteEdge(Graph* G, int u, int v) {
	G->cost[u][v] = INF;
}

// �׷��� G�� ���ҽ� ����
void destroyGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			if(i != j)
				G->cost[i][j] = INF;
	}
		G->dist[i] = INF;
		G->pred[i] = NONE;
	}
	G->n = 0;
}

// �׷��� G�� ���� ��� ���� ���
void displayGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++){
			if(G->cost[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->cost[i][j]);
		}			
		printf("\n");
	}
}

// �ּ� ����� ���� ���� ������ ã�� ����
// Dijkstra Algorithm ������ �ʿ��� ��� �̿� 
int nextVertex(Graph* G) {
	int i, minCost, minVertex;
	minCost = INF;
	minVertex = -1;
	for(i=0; i<G->n; i++) {
		if(G->dist[i] < minCost && !G->S[i]) {
			minCost = G->dist[i];
			minVertex = i;
		}
	}
	return minVertex;
}	

// Dijkstra Algorithm
void dijkstra(Graph* G, int v) {
	// Fill your code
	int a = v;
	int I = INF;
	for (int i = 0; i < MAX_SIZE; i++) {
		G->S[i] = 0;
		G->pred[i] = 0;
	}
	G->S[v] = 1;
	for (int i = 0; i < G->n - 1; i++) { 
		G->dist[i] = G->cost[v][i];
		if (G->cost[v][i] != INF) {
			G->pred[i] = v;
		}
		else G->pred[i] = NONE;
	}
	for (int i = 0; i < G->n - 1; i++) { 
		for (int j = 0; j < G->n; j++) {
			if (G->S[j] == 0) {
				if (G->dist[j] > G->dist[a] + G->cost[a][j]) {
					G->dist[j] = G->dist[a] + G->cost[a][j];
					G->pred[j] = a;
				}
			}
		}
		for (int k = 0; k < G->n; k++) {
			if (G->S[k] == 0 && I > G->dist[k]) {
				I = G->dist[k];
				a = k;
			}
		}
		G->S[a] = 1;
	}
}

// Bellman-Ford Algorithm
int bellmanFord(Graph* G, int v) {
	// Fill your code;
	int n = G->n;
	G->dist[0] = 0;
	for (int i = 1;i < n;i++) {
		G->dist[i] = INF;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
	
			if (G->dist[j] > G->dist[i] + G->cost[i][j]) {
				G->dist[j] = G->dist[i] + G->cost[i][j];
				G->pred[j] = i;
			}
		}
	}	
	for (int i = n-1;i > 0;i--) {
		for (int j = n-1;j > 0;j--) {
			
			if (G->dist[j] > G->dist[i] + G->cost[i][j]) {
				G->dist[j] = G->dist[i] + G->cost[i][j];
				G->pred[j] = i;
			}
		}
	}
	return TRUE;
}	

// Floyd-Warshall Algorithm
void floyd(Graph* G){
	// Fill your code
	int n = G->n;
	for (int i = 0;i < G->n;i++) {
		for (int j = 0;j < G->n;j++) {
			G->A[i][j] = G->cost[i][j];
		}
	}
	for (int k = 0;k < G->n;k++) {
		for (int i = 0;i < G->n;i++) {
			for (int j = 0;j < G->n;j++) {
				if (G->A[i][k] + G->A[k][j] < G->A[i][j]) {
					G->A[i][j] = G->A[i][k] + G->A[k][j];
				}
			}
		}
	}
}	

// �ִܰ�� ���
void printShortestPath(Graph* G, int src, int dst) {
	printf("%c -> %c �ִ� ���: %c", src+65, dst+65, src+65);
	int v = dst;
	Stack* stack = createStack();
	// Fill your code
	int a = 0;
	if (G->pred[v] != src) {
		push(stack, v);
		push(stack, G->pred[v]);
		a = a + 2;
		for (int i = 0; i < MAX_SIZE; i++) {
			if (i == G->pred[v]) {
			    if (G->pred[i] != src) {
				    push(stack, G->pred[i]);
					v = i;
					a++;
				}
			}
		}
	}
	else {
		push(stack, v);
		a++;
	}
	for (int i = 0; i < a;i++) {
		printf("%c \n", pop(stack) + 65);
	}
}	

// �ִܰ�� ��� ���
int printShortestPathCost(Graph* G, int src, int dst) {
	printf("%c -> %c �ִ� ��� ���: %d", src+65, dst+65, G->dist[dst]);
}

// ��� ���� �� ������ �ִ� ��� ��� ��� 
void printAllPairShortestCost(Graph* G) {
	int i, j;
	
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			if(G->A[i][j] == INF)
				printf("INF\t");
			else
				printf("%2d\t", G->A[i][j]);
		}			
		printf("\n");
	}
}		
