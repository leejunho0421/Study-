#ifndef __ARRAY_GRAPH_H__
#define _ARRAY_GRAPH_H__

#define MAX_SIZE 10
#define INF 987654321
#define NONE 9999

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의
typedef struct GraphType {
	int n; 
	int cost[MAX_SIZE][MAX_SIZE];
	int dist[MAX_SIZE];
	int pred[MAX_SIZE];
	int S[MAX_SIZE];
	int A[MAX_SIZE][MAX_SIZE];
} Graph;

Graph* createGraph();	// 공백 그래프를 생성하는 연산
int isEmpty(Graph* G);	// 그래프가 공백인지 검사
void insertVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삽입
void insertEdge(Graph* G, int u, int v, int weight);	// 그래프 G에 간선(u, v)를 삽입
void deleteVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제
void deleteEdge(Graph* G, int u, int v);  // 그래프 G에 간선 (u, v)를 삭제
void destroyGraph(Graph* G);	// 그래프 G의 리소스 해제
void displayGraph(Graph* G);	// 그래프 G의 인접 행렬 정보 출력 

int nextVertex(Graph* G);	// 최소 비용을 갖는 다음 정점을 찾는 연산 
void dijkstra(Graph* G, int v); // Dijkstra Algorithm
int bellmanFord(Graph* G, int v);	// Bellman-Ford Algorithm
void floyd(Graph* G);	// Floyd-Warshall Algorithm
void printShortestPath(Graph* G, int src, int dst);	// 최단경로 출력
int printShortestPathCost(Graph* G, int src, int dst);	// 최단경로 비용 출력
void printAllPairShortestCost(Graph* G);	// 모든 정점 쌍 사이의 최단 경로 비용 출력 
int RELAX(int u, int v);
#endif
