#ifndef __LIST_GRAPH_H__
#define _LIST_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0

// ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct GraphNode {
	int vertex;		// ������ ��Ÿ���� ������ �ʵ� 
	struct GraphNode* link;	// ���� ���� ������ �����ϴ� ��ũ �ʵ� 
} graphNode;
 
// �׷����� ���� ����Ʈ�� ǥ���ϱ� ���� ����ü ����
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: ������, DIRECT: ���� 
	graphNode* adjList_H[MAX_SIZE];	// �׷��� ������ ���� ��� ������ 
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

