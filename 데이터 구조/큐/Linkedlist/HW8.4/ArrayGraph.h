#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 10
#define INF 987654321
#define NONE 9999

// �׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����
typedef struct GraphType {
	int n; 
	int cost[MAX_SIZE][MAX_SIZE];
	int dist[MAX_SIZE];
	int pred[MAX_SIZE];
	int S[MAX_SIZE];
	int A[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph();	// ���� �׷����� �����ϴ� ����
int isEmpty(Graph* G);	// �׷����� �������� �˻�
void insertVertex(Graph* G, int v);	// �׷��� G�� ���� v�� ����
void insertEdge(Graph* G, int u, int v, int weight);	// �׷��� G�� ����(u, v)�� ����
void deleteVertex(Graph* G, int v);	// �׷��� G�� ���� v�� �����ϰ� ����� ��� ���� ����
void deleteEdge(Graph* G, int u, int v);  // �׷��� G�� ���� (u, v)�� ����
void destroyGraph(Graph* G);	// �׷��� G�� ���ҽ� ����
void displayGraph(Graph* G);	// �׷��� G�� ���� ��� ���� ��� 

int nextVertex(Graph* G);	// �ּ� ����� ���� ���� ������ ã�� ���� 
void dijkstra(Graph* G, int v); // Dijkstra Algorithm
int bellmanFord(Graph* G, int v);	// Bellman-Ford Algorithm
void floyd(Graph* G);	// Floyd-Warshall Algorithm
void printShortestPath(Graph* G, int src, int dst);	// �ִܰ�� ���
int printShortestPathCost(Graph* G, int src, int dst);	// �ִܰ�� ��� ���
void printAllPairShortestCost(Graph* G);	// ��� ���� �� ������ �ִ� ��� ��� ��� 
int RELAX(int u, int v);
#endif
