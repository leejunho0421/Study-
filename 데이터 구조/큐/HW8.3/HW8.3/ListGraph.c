#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"

// 공백 그래프를 생성하는 연산
Graph* createGraph(int type) {
	int i;
	Graph* G = (Graph*)malloc(sizeof(Graph));	
	G->n = 0;
	G->type = type;
	for(i=0; i<MAX_SIZE; i++) {
		G->adjList_H[i] = NULL;
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
	return G;
}

// 그래프가 공백인지 검사	
int isEmptyGraph(Graph* G) {
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
int a(Graph* G, int u, int v) {

	graphNode* p = G->adjList_H[u];
	for (; p; p = p->link)
		if (p->vertex == v) return 0;
	return 1;

}
// 그래프 G에 간선(u, v)를 삽입
void insertEdge(Graph* G, int u, int v) {
	// Fill your code (HW8.2) 
	
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

// visited[], pred[] 초기화 
void initSearch(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// 깊이 우선 탐색 iterative version
void dfs_iter(Graph* G, int v) {
	// Fill your code (HW8.3)
	int i = 0;
	graphNode* w;
	Stack* S = createStack();
	G->visited[v] = TRUE;
	push(S, v);
	visit(v);

	while (!isEmpty(S)) {
		v = pop(S);
		w = G->adjList_H[v];
		for (i = 0;i < MAX_SIZE;i++) {
			while (G->adjList_H[i] == 0) {
				if (G->visited[w->vertex] == FALSE) {
					push(S, v);
					G->visited[w->vertex] = TRUE;
					visit(w->vertex);
					v = w->vertex;
					w = G->adjList_H[v];
				}
				else w = w->link;
			}
		}
	}
}	

// 깊이 우선 탐색 recursive version
void dfs_recur(Graph* G, int v)	{
	// Fill your code (HW8.3)
	graphNode* w;
	visit(v);
	G->visited[v] = TRUE;
	for (w = 0;w < MAX_SIZE;w++) {
		if (G->visited[w->vertex] == FALSE) {
			G->pred[w->vertex] = G->adjList_H[v];
			dfs_recur(G, w);
		}
	}
}

// 너비 우선 탐색
void bfs(Graph* G, int v) {
	// Fill your code (HW8.3) 
	Queue* Q = createQ();
	graphNode* w;
	G->visited[v] = TRUE;
	enqueue(Q, v);
	visit(v);
	while (!isEmptyQ(Q)) {
		v = dequeue(Q);
		for (w = 0;w < MAX_SIZE;w++) {
			if (G->visited[w->vertex] == FALSE) {
				enqueue(Q, w->vertex);
				G->visited[w->vertex] = TRUE;
				visit(w->vertex);
			}
		}
	}

}		
