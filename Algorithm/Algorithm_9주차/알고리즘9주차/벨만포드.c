#include <stdio.h>

typedef struct _edge {
	int src; //������
	int dest; //������
	int weight; //����ġ
}Edge;
 
typedef struct _graph {
	int v; //������ ����
	int e; //������ ����
	struct _edge* edge; //����
}Graph;

void BellmanFord(Graph *graph) {
	int v = 8;
	int e = 11;
	int *dist = (int*)malloc(sizeof(int)*v);
	dist[0] = 0; //ù ���� 0���� 0����

	for (int i = 1; i < v; i++)
		dist[i] = 9999; //�ִ��� ū ���ڷ� �ٲ���
	
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < e; j++) {
			if (dist[graph->edge[j].src] + graph->edge[j].weight < dist[graph->edge[j].dest]) {
				dist[graph->edge[j].dest] = dist[graph->edge[j].src] + graph->edge[j].weight;
			} //(graph->edge[j].src �� �ִ� �Ÿ� + ����ġ)�� graph->edge[j].dest�� �ִ� �Ÿ����� ������
		}     //graph->edge[j].dest�� �ִ� �Ÿ��� (graph->edge[j].src �� �ִ� �Ÿ� + ����ġ)�� �ٲ���.
	}

	for (int i = 0; i < v; i++)
			printf("���� : %d  �ִܰŸ� : %d\n", i, dist[i]);

}

void main()
{
	int v = 8; //��������
	int e = 11; //��������
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->v = v;
	graph->e = e;
	graph->edge = (Edge*)malloc(sizeof(Edge)*e); //���� �׷����� ����, ���� �� ����

	graph->edge[0].src = 0; //���� 0����
	graph->edge[0].dest = 1; //���� 1��
	graph->edge[0].weight = 10; //���� ����ġ�� 10

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
	graph->edge[10].weight = 1; //���� ù ���۰� �������� ����ġ�� ����

	BellmanFord(graph); //�������� �Լ� ȣ��
}