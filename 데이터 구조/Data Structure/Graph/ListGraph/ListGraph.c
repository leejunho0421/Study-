#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

// ���� �׷����� �����ϴ� ����
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
//�ߺ��˻�
int a(Graph* G, int u, int v) {

	graphNode* p = G->adjList_H[u];
	for (; p; p = p->link)
		if (p->vertex == v) return 0;
	return 1;

}

// �׷��� G�� ����(u, v)�� ����
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

// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����
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

// �׷��� G�� ���� (u, v)�� ����
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

