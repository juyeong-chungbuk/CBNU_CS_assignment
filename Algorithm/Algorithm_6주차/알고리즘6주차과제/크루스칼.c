#include <stdio.h>
#include <stdlib.h>
#define NUM 10
int parent[NUM]; //해당 index의 부모노드가 들어감
int num[NUM]; //가중치

typedef struct edge {
	int x; //정점1
	int y; //정점2
	int weight; //가중치
}Edge;

void make_set(int x) //단일 element로 이루어진 set하나 생성
{
	parent[x] = x; //부모노드x에 x를 넣어서 노드 하나 생성
	num[x] = 0; //rank는 0
}

int find_set(int x) //x가 포함된 set을 리턴
{
	if (parent[x] != x) { //부모노드가 현재x값과 다르면
		parent[x] = find_set(parent[x]); //재귀를 이용하여 부모노드로 이동
	} return parent[x]; //부모노드 리턴
}

void union_set(int x, int y) //x가 포함된 set과 y과 포함된 set합침
{
	if (num[x] > num[y]) { //rank가 큰 것을
		parent[y] = x; //부모노드로
	}
	else {
		parent[x] = y; //rank가 작은 것을 자식노드로
		if (num[x] == num[y]) //rank가 같으면 
			num[y]++; //둘 중 아무거나 증가
	}
}


void sort(Edge *e, int n) //가중치 정렬함수
{
	Edge tmp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (e[i].weight > e[j].weight) {
				tmp = e[i];
				e[i] = e[j];
				e[j] = tmp;
			}
		}
	}
}

void Kruskal(int *node, int n) 
{
	int i, j;
	Edge S[100], MST[100]; //2차원행렬을 1차원으로 표현하기 위한 배열
	int num = 0;
	int x, y;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			S[num].weight = node[i*n + j];
			S[num].x = i;
			S[num].y = j;
			num++;
		}
	}
	sort(S, n);

	for(i=0;i<n;i++)
		make_set(i);  //makeset

	num = 0;
	for (i = 0; i < n*n; i++) {
		if (S[i].weight != 0) {
			x = find_set(S[i].x); //find
			y = find_set(S[i].y);

			if (x == y)
				break;

			else {
				MST[num] = S[i];
				union_set(x, y, num); //union
				num++;
			}
		}

	}

	printf("\n**MST edge set T**\n");

	for (i = 0; i < n -1; i++)
		printf("정점%d - 정점%d 가중치: %d\n", MST[i].x, MST[i].y, MST[i].weight);
}

void main()
{
	int n;
	int i, j;

	printf("정점의 개수: "); //정점의 개수 입력받기
	scanf("%d", &n);

	int *matrix = (int)malloc(sizeof(int)*(n*n)); //공간할당

	for (i = 0; i < n; i++) {
		for (j = 0; j < i + 1; j++) {
			if (i == j) //[0,0] ... [5,5]와 같이 인덱스가 같으면 가중치 0
				matrix[i*n + j] = 0;
			else {
				matrix[i*n + j] = ( rand() % 12 )+ 1; //랜덤 수 저장
				matrix[j*n + i] = matrix[i*n + j];
			}
		}
	}

		printf("**matrix**\n");

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				printf(" %d ", matrix[i*n + j]); //행렬 출력

			printf("\n");
		}

	Kruskal(matrix, n); //Kruskal 알고리즘 함수호출
}