//#include <stdio.h>
//#include <stdlib.h>
//#define NUM 10
//int parent[NUM]; //해당 index의 부모노드가 들어감
//int num[NUM]; //가중치
//
//typedef struct edge {
//	int x; //정점1
//	int y; //정점2
//	int weight; //가중치
//}Edge;
//
//int findmin(Edge *E, int n)
//{
//	int i, j;
//	int min = -1;
//
//	for (i = 0; i < n*n; i++) {
//			if (min > E[i].weight) {
//				min = E[i].weight;
//				return min;
//			}
//	}
//}
//
//int deldetemin(Edge *E, int n)
//{
//	int i, j;
//	int min = -1;
//
//	for (i = 0; i < n*n; i++) {
//		if (min > E[i].weight) {
//			min = E[i].weight;
//			return min;
//		}
//	}
//}
//
//int insert(Edge *E, int n, int item)
//{
//	int i;
//	for (i = 0; i < n*n; i++) {
//		E[i].weight = item;
//		return item;
//	}
//}
//
//int delete(Edge *E, int n, int itme)
//{
//	int i;
//
//	for (i = 0; i < n*n; i++) {
//		item=
//	}
//}
//
//void decreasekey(Edge *E, int item, int k)
//{
//
//}
//
//void Prim(int *node)
//{
//	int i, j;
//	int num;
//	Edge E[300], S[300]; //E는 2차원행렬을 1차원으로 표현한 배열, S는 MST
//	Edge visited[25], distance[25];
//
//	distance[0].weight = 0;
//	visited[0].weight = 1;
//
//	for (i = 0; i < 5; i++) {
//			distance[i].weight = E[i].weight;
//			visited[i].weight = 0;
//	}
//
//			for (i = 0; i < 5; i++) {
//				for (j = 0; j < 5; j++) {
//					E[num].weight = node[i * 5 + j];
//					E[num].x = i;
//					E[num].y = j;
//					num++;
//				}
//			} //여기까지 1차원행렬에 그래프 집어넣는거임.
//
//			num = 0;
//			S[0].weight = 0;
//			for (i = 0; i < 5; i++) {
//				if (findmin(E, 5) == i)
//					S[i].weight = insert(E, 5, i);
//			}
//}
//
//void main()
//{
//	int n;
//	int i, j;
//
//	printf("정점의 개수: ");
//	scanf("%d", &n);
//
//	int *matrix = (int)malloc(sizeof(int)*(n*n));
//
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < i + 1; j++) {
//			if (i == j)
//				matrix[i*n + j] = 0;
//			else {
//				matrix[i*n + j] = (rand() % 12) + 1;
//				matrix[j*n + i] = matrix[i*n + j];
//			}
//		}
//	} //여기까지 행렬로 만듦.
//
//	printf("**matrix**\n");
//
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++)
//			printf(" %d ", matrix[i*n + j]); //행렬 출력
//
//		printf("\n");
//	}
//
//	Prim(matrix, n); //prim함수 호출
//}