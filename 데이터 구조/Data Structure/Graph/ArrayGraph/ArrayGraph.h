#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0

// �׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: ������, DIRECT: ���� 
	int adjMatrix[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph(int type);	// ���� �׷����� �����ϴ� ����
int isEmpty(Graph* G);	// �׷����� �������� �˻�
void insertVertex(Graph* G, int v);	// �׷��� G�� ���� v�� ����
void insertEdge(Graph* G, int u, int v);	// �׷��� G�� ����(u, v)�� ����
void deleteVertex(Graph* G, int v);	// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����
void deleteEdge(Graph* G, int u, int v);  // �׷��� G�� ���� (u, v)�� ����
void destroyGraph(Graph* G);	// �׷��� G�� ���ҽ� ����
void displayGraph(Graph* G);	// �׷��� G�� ���� ��� ���� ��� 
 
#endif
