#include <stdio.h>
#include <stdlib.h>
#define NUM 10
int parent[NUM]; //�ش� index�� �θ��尡 ��
int num[NUM]; //����ġ

typedef struct edge {
	int x; //����1
	int y; //����2
	int weight; //����ġ
}Edge;

void make_set(int x) //���� element�� �̷���� set�ϳ� ����
{
	parent[x] = x; //�θ���x�� x�� �־ ��� �ϳ� ����
	num[x] = 0; //rank�� 0
}

int find_set(int x) //x�� ���Ե� set�� ����
{
	if (parent[x] != x) { //�θ��尡 ����x���� �ٸ���
		parent[x] = find_set(parent[x]); //��͸� �̿��Ͽ� �θ���� �̵�
	} return parent[x]; //�θ��� ����
}

void union_set(int x, int y) //x�� ���Ե� set�� y�� ���Ե� set��ħ
{
	if (num[x] > num[y]) { //rank�� ū ����
		parent[y] = x; //�θ����
	}
	else {
		parent[x] = y; //rank�� ���� ���� �ڽĳ���
		if (num[x] == num[y]) //rank�� ������ 
			num[y]++; //�� �� �ƹ��ų� ����
	}
}


void sort(Edge *e, int n) //����ġ �����Լ�
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
	Edge S[100], MST[100]; //2��������� 1�������� ǥ���ϱ� ���� �迭
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
		printf("����%d - ����%d ����ġ: %d\n", MST[i].x, MST[i].y, MST[i].weight);
}

void main()
{
	int n;
	int i, j;

	printf("������ ����: "); //������ ���� �Է¹ޱ�
	scanf("%d", &n);

	int *matrix = (int)malloc(sizeof(int)*(n*n)); //�����Ҵ�

	for (i = 0; i < n; i++) {
		for (j = 0; j < i + 1; j++) {
			if (i == j) //[0,0] ... [5,5]�� ���� �ε����� ������ ����ġ 0
				matrix[i*n + j] = 0;
			else {
				matrix[i*n + j] = ( rand() % 12 )+ 1; //���� �� ����
				matrix[j*n + i] = matrix[i*n + j];
			}
		}
	}

		printf("**matrix**\n");

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				printf(" %d ", matrix[i*n + j]); //��� ���

			printf("\n");
		}

	Kruskal(matrix, n); //Kruskal �˰��� �Լ�ȣ��
}