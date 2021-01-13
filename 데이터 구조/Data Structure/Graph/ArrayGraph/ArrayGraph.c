#include <stdio.h>
#include <stdlib.h>
#include "ArrayGraph.h"

// 공백 그래프를 생성하는 연산
Graph* createGraph(int type) {
	int i, j;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		for(j=0; j<MAX_SIZE; j++)
			G->adjMatrix[i][j] = 0;
	}
	return G;
}

// 그래프가 공백인지 검사	
int isEmpty(Graph* G) {
	return G->n == 0;
}

// 그래프 G에 정점 v를 삽입
void insertVertex(Graph* G, int v) {
	if((G->n)+1 > MAX_SIZE) {
		printf("[ERROR] 그래프 정점의 개수 초과\n");
		return;
	}
	G->n++;
}

// 그래프 G에 간선(u, v)를 삽입
void insertEdge(Graph* G, int u, int v) {
	// Fill your code
	if (G->type == 0) {
		G->adjMatrix[u][v] = 1;
		G->adjMatrix[v][u] = 1;
	}
	else {
		G->adjMatrix[u][v] = 1;
	}
}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제
void deleteVertex(Graph* G, int v) {
	// Fill your code
	Graph* p = G->adjMatrix[v];
	if (G->type == 0) {//방향
		for (int i = 0;i < G->n;i++) {
			G->adjMatrix[v][i] = 0;
			G->adjMatrix[i][v] = 0;
		}
	}
	else {
		for (int j = 0;j < G->n;j++) {
			G->adjMatrix[v][j] = 0;
			G->adjMatrix[j][v] = 0;
		}
	}
	p = NULL;
}

// 그래프 G에 간선 (u, v)를 삭제
void deleteEdge(Graph* G, int u, int v) {
	// Fill your code
	if (G->type != 0) {
		G->adjMatrix[u][v] = 0;
		
	}
	else {
	 	G->adjMatrix[u][v] = 0;
	    G->adjMatrix[v][u] = 0;
	}
}

// 그래프 G의 리소스 해제
void destroyGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++)
			G->adjMatrix[i][j] = 0;
	}
	G->n = 0;
}

// 그래프 G의 인접 행렬 정보 출력
void displayGraph(Graph* G) {
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++)
			printf("%2d\t", G->adjMatrix[i][j]);
		printf("\n");
	}
}
