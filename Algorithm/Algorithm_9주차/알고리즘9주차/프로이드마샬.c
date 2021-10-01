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

void Floyd(int graph[][4]) {

	int v = 4;
	int dist[4][4];

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			dist[i][j] = graph[i][j];
		}
	}
	

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			for (int k = 0; k < v; k++) {
				if (dist[j][i] + dist[i][k] < dist[j][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
			
		}
	}

	printf("    %d", 0);
	for (int i = 1; i < v; i++)
		printf("  %d", i);

	printf("\n");
	printf("---------------\n");

	for (int i = 0; i < v; i++) {
		printf("%d l", i);
		for (int j = 0; j < v; j++) {
			if (dist[i][j] == 9999)
				printf("infinite");
			else
				printf(" %d ", dist[i][j]);
		}
		printf("\n");
	}
		
}

void main()
{
	int graph[4][4] = { {0,3,9999,5},{2,0,9999,4},{9999,1,0,9999},{9999,9999,2,0} };

	Floyd(graph); //프로이드 함수 호출
}