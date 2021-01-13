#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"

// ���� �׷����� �����ϴ� ����
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

// �׷����� �������� �˻�	
int isEmptyGraph(Graph* G) {
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
int a(Graph* G, int u, int v) {

	graphNode* p = G->adjList_H[u];
	for (; p; p = p->link)
		if (p->vertex == v) return 0;
	return 1;

}
// �׷��� G�� ����(u, v)�� ����
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

// �׷��� G�� ���ҽ� ����
void destroyGraph(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		if(G->adjList_H[i] != NULL)
			free(G->adjList_H[i]);
	}
	free(G);
}

// �׷��� G�� ���� ����Ʈ ���� ���
void displayGraph(Graph* G) {
	int i;
	graphNode* p;
	for(i=0; i<G->n; i++) {
		printf("���� %d�� ��������Ʈ", i);
		p = G->adjList_H[i];
		while(p) {
			printf(" -> %d ", p->vertex);
			p = p->link;
		}			
		printf("\n");
	}
}

// visited[], pred[] �ʱ�ȭ 
void initSearch(Graph* G) {
	int i;
	for(i=0; i<G->n; i++) {
		G->visited[i] = FALSE;
		G->pred[i] = -1;
	}
}

// ���� �켱 Ž�� iterative version
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

// ���� �켱 Ž�� recursive version
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

// �ʺ� �켱 Ž��
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
