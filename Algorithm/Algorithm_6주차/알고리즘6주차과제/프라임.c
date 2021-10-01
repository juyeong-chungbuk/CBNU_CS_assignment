#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int n; //����
	int **cost; //����ġ ����������
}Edge;

int front = 0; //ť�� ��
int rear = 0; //ť�� ��
int queue[10]; //ť�迭

void Add_queue(int n) { //ť���� �� �߰�

	if ((rear + 1) % 10 == front) //rear�� ������ front�� ������
		printf("ť�� ���� á��.\n");  //ť�� ���� ��

	else {
		rear = (rear + 1) % 10; //rear�� �ϳ� ���� ��Ű��
		queue[rear] = n; //ť�� �� �߰�
	}
}

int Delete_queue() { //ť���� �� ����

	int temp = -1;

	if (front == rear) //rear�� front�� ��������
		printf("ť�� �����.\n"); //ť�� �����

	else {
		front = (front + 1) % 10; //front�ϳ� ����
		temp = queue[front]; //temp�� �� �־ ����
	}
	return temp; //������ �� ��ȯ
}

int findmin(Edge *E, int n) //cost�� ���� ���� �� ��ȯ
{
	int i, j;
	int min = -1;

	for (i = 0; i < n*n; i++) { //i�� n*n���� �ݺ��Ͽ�
		if (min > E->cost[i]) { //min���� ���� ���� ������
			min = E->cost[i]; //min�� �� ������ �ΰ�
			return min; //min��ȯ
		}
	}
}


int deldetemin(Edge *E, int n) //cost�� ���� ���� �� ���� �� ��ȯ
{
	int i, j;
	int min = -1;

	for (i = 0; i < n*n; i++) {
		if (min > E->cost[i]) {
			min = E->cost[i];
			return min;
		}
	}
}

int insert(Edge *E, int n, int item) //edge insert
{
	int i;
	for (i = 0; i < n*n; i++) {
		E->cost[i] = item; //����ġ �ο�
		return item;
	}
}

int delete(Edge *E, int n, int item)
{
	int i;

	for (i = 0; i < n*n; i++) {
		item = E->cost[i];
		return item;
	}
}

void decreasekey(Edge *E, int item, int k)
{
	E->cost[item] = k; //item�� ����ġ�� k�� ����
}

void Prim(Edge *e, int n) //Prim�˰���
{
	int a = -1;
	int x = -1;
	int i, j;
	int dele;

	
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				e->cost[i] = 0; //0���� �ʱ�ȭ
			}
		}

		if (e->n == 0) { //ť ����
			Add_queue(n);
			e->n++; //n�������Ѽ�
			Prim(e, n); //����Լ��� �ݺ�
		}

		else if (e->n <= 5) { //5���� �۰ų� ������
			for (int i = 0; i < e->n; i++) {
				x = Delete_queue(); //x�� ������ �� ����
				for (int j = 0; j < e->n; j++) {
					a = findmin(e, 5); //cost�� ���� ���� �� ��ȯ
					e->cost[i][j] = a; //����ġ �ּ�cost�� ����


					if (x != -1 && a != -1) //x, a�� ��� -1�ƴϸ�
						printf(" %d - %d : %d\n", x, a, e->cost[i][j]);
				}
				Add_queue(x); //������ x�� ť�� �߰�
			}
		}


	for (i = 0; i < n*n; i++) {
		dele = delete(e, n, i); //������ �� ����
		printf(" %d ", dele);
	}

}


void main()
{
	int i, j;

	int n = 2;

	int *matrix = (int)malloc(sizeof(int)*(n*n)); //�����Ҵ�
	
		for (i = 0; i < n; i++) {
			for (j = 0; j < i + 1; j++) {
				if (i == j)  //[0,0] ... [5,5]�� ���� �ε����� ������ ����ġ 0
					matrix[i*n + j] = 0;
				else {
					matrix[i*n + j] = ( rand() % 12 )+ 1;  //���� �� ����
					matrix[j*n + i] = matrix[i*n + j];
				}
			}
		} //������� ��ĸ���.
	
			printf("**matrix**\n");
	
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++)
					printf(" %d ", matrix[i*n + j]);
	
				printf("\n");
			}

	Prim(matrix, 0); // Prim �˰��� �Լ�ȣ��

}