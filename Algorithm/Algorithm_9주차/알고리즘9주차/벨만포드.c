#include <stdio.h>

typedef struct _edge {
	int src; //시작점
	int dest; //도착점
	int weight; //가중치
}Edge;
 
typedef struct _graph {
	int v; //정점의 개수
	int e; //간선의 개수
	struct _edge* edge; //간선
}Graph;

void BellmanFord(Graph *graph) {
	int v = 8;
	int e = 11;
	int *dist = (int*)malloc(sizeof(int)*v);
	dist[0] = 0; //첫 시작 0노드는 0으로

	for (int i = 1; i < v; i++)
		dist[i] = 9999; //최대한 큰 숫자로 바꿔줌
	
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < e; j++) {
			if (dist[graph->edge[j].src] + graph->edge[j].weight < dist[graph->edge[j].dest]) {
				dist[graph->edge[j].dest] = dist[graph->edge[j].src] + graph->edge[j].weight;
			} //(graph->edge[j].src 의 최단 거리 + 가중치)가 graph->edge[j].dest의 최단 거리보다 작으면
		}     //graph->edge[j].dest의 최단 거리를 (graph->edge[j].src 의 최단 거리 + 가중치)로 바꿔줌.
	}

	for (int i = 0; i < v; i++)
			printf("정점 : %d  최단거리 : %d\n", i, dist[i]);

}

void main()
{
	int v = 8; //정점개수
	int e = 11; //간선개수
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->v = v;
	graph->e = e;
	graph->edge = (Edge*)malloc(sizeof(Edge)*e); //각각 그래프의 정점, 간선 값 설정

	graph->edge[0].src = 0; //정점 0에서
	graph->edge[0].dest = 1; //정점 1로
	graph->edge[0].weight = 10; //가는 가중치는 10

	graph->edge[1].src = 0;
	graph->edge[1].dest = 7;
	graph->edge[1].weight = 8;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 5;
	graph->edge[2].weight = 2;

	graph->edge[3].src = 2;
	graph->edge[3].dest = 1;
	graph->edge[3].weight = 1;

	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 1;

	graph->edge[5].src = 3;
	graph->edge[5].dest = 4;
	graph->edge[5].weight = 3;

	graph->edge[6].src = 4;
	graph->edge[6].dest = 5;
	graph->edge[6].weight = -1;

	graph->edge[7].src = 5;
	graph->edge[7].dest = 2;
	graph->edge[7].weight = -2;

	graph->edge[8].src = 6;
	graph->edge[8].dest = 1;
	graph->edge[8].weight = -4;

	graph->edge[9].src = 6;
	graph->edge[9].dest = 5;
	graph->edge[9].weight = -1;

	graph->edge[10].src = 7;
	graph->edge[10].dest = 6;
	graph->edge[10].weight = 1; //직접 첫 시작과 도착점의 가중치를 설정

	BellmanFord(graph); //벨만포드 함수 호출
}