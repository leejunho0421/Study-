#ifndef __LIST_GRAPH_H__
#define _LIST_GRAPH_H__

#define MAX_SIZE 100
#define DIRECT 1
#define UNDIRECT 0

// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct GraphNode {
	int vertex;		// 정점을 나타내는 데이터 필드 
	struct GraphNode* link;	// 다음 인접 정점을 연결하는 링크 필드 
} graphNode;
 
// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct GraphType {
	int n;
	int type;	// UNDIRECT: 무방향, DIRECT: 방향 
	graphNode* adjList_H[MAX_SIZE];	// 그래프 정점에 대한 헤드 포인터 
} Graph;

Graph* createGraph(int type);	// 공백 그래프를 생성하는 연산
int isEmpty(Graph* G);	// 그래프가 공백인지 검사
void insertVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삽입
void insertEdge(Graph* G, int u, int v);	// 그래프 G에 간선(u, v)를 삽입
void deleteVertex(Graph* G, int v);	// 그래프 G에 정점 v를 삭제하고 연결된 모든 간선 삭제
void deleteEdge(Graph* G, int u, int v);  // 그래프 G에 간선 (u, v)를 삭제
void destroyGraph(Graph* G);	// 그래프 G의 리소스 해제
void displayGraph(Graph* G);	// 그래프 G의 인접 행렬 정보 출력 
 
#endif

