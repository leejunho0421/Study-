#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// 공백 그래프를 생성하는 연산
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
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
//중복검사
int a(Graph* G, int u, int v) {

	graphNode* p = G->adjList_H[u];
	for (; p; p = p->link)
		if (p->vertex == v) return 0;
	return 1;

}

// 그래프 G에 간선(u, v)를 삽입
void insertEdge(Graph* G, int u, int v) {
	// Fill your code

	if (a(G, u, v) && a(G, v, u)) {
		graphNode* p = (graphNode*)malloc(sizeof(graphNode));
		p->vertex = v;
		p->link = G->adjList_H[u];
		G->adjList_H[u] = p;

		if (G->type == 0)
		{
			graphNode* q = (graphNode*)malloc(sizeof(graphNode));
			q->vertex = u;
			q->link = G->adjList_H[v];
			G->adjList_H[v] = q;
		}
	}


}

// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제
void deleteVertex(Graph* G, int v) {
	// Fill your code

	graphNode* p;
	graphNode* q;

	for (int i = 0; i < G->n; i++) {
		p = G->adjList_H[i];
		q = G->adjList_H[i];

		for (; p; q->link) {
			if (p->vertex == v) {
				if (p == G->adjList_H[i])
					G->adjList_H[i] = p->link;
				q->link = p->link;
			}
			p = p->link;
		}
	}
	G->adjList_H[v] = NULL;
}

// 그래프 G에 간선 (u, v)를 삭제
void deleteEdge(Graph* G, int u, int v) {
	// Fill your code
	graphNode* p;
	graphNode* q;

	q = G->adjList_H[u];
	p = G->adjList_H[u]; 

	for (; p; q->link) {
		if (p->vertex == v) {
			if (p == G->adjList_H[u]) 
				G->adjList_H[u] = p->link;
			q->link = p->link; 
		}
		p = p->link;
	}

	if (G->type == UNDIRECT)
	{
		q = G->adjList_H[v];
		p = G->adjList_H[v]; 

		for (; p; q->link) {
			if (p->vertex == u) {
				if (p == G->adjList_H[v]) 
					G->adjList_H[v] = p->link;
				q->link = p->link; 
			}
			p = p->link;
		}
	}

}

// 그래프 G의 리소스 해제
void destroyGraph(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		if(G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// 그래프 G의 인접 리스트 정보 출력
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for(i=0; i<G->n; i++) {
		printf("정점 %d의 인접리스트", i);
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

