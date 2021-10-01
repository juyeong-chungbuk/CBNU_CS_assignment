#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int n; //정점
	int **cost; //가중치 이중포인터
}Edge;

int front = 0; //큐의 앞
int rear = 0; //큐의 뒤
int queue[10]; //큐배열

void Add_queue(int n) { //큐에서 값 추가

	if ((rear + 1) % 10 == front) //rear의 다음이 front와 같으면
		printf("큐가 가득 찼음.\n");  //큐가 가득 참

	else {
		rear = (rear + 1) % 10; //rear를 하나 증가 시키고
		queue[rear] = n; //큐에 값 추가
	}
}

int Delete_queue() { //큐에서 값 제거

	int temp = -1;

	if (front == rear) //rear와 front가 같아지면
		printf("큐가 비었음.\n"); //큐가 비었음

	else {
		front = (front + 1) % 10; //front하나 증가
		temp = queue[front]; //temp에 값 넣어서 제거
	}
	return temp; //제거한 값 반환
}

int findmin(Edge *E, int n) //cost가 가장 작은 값 반환
{
	int i, j;
	int min = -1;

	for (i = 0; i < n*n; i++) { //i를 n*n까지 반복하여
		if (min > E->cost[i]) { //min보다 작은 값이 나오면
			min = E->cost[i]; //min을 그 값으로 두고
			return min; //min반환
		}
	}
}


int deldetemin(Edge *E, int n) //cost가 가장 작은 값 제거 후 반환
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
		E->cost[i] = item; //가중치 부여
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
	E->cost[item] = k; //item의 가중치를 k로 변경
}

void Prim(Edge *e, int n) //Prim알고리즘
{
	int a = -1;
	int x = -1;
	int i, j;
	int dele;

	
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				e->cost[i] = 0; //0으로 초기화
			}
		}

		if (e->n == 0) { //큐 시작
			Add_queue(n);
			e->n++; //n증가시켜서
			Prim(e, n); //재귀함수로 반복
		}

		else if (e->n <= 5) { //5보다 작거나 같으면
			for (int i = 0; i < e->n; i++) {
				x = Delete_queue(); //x에 제거한 값 대입
				for (int j = 0; j < e->n; j++) {
					a = findmin(e, 5); //cost가 가장 작은 값 반환
					e->cost[i][j] = a; //가중치 최소cost로 대입


					if (x != -1 && a != -1) //x, a가 모두 -1아니면
						printf(" %d - %d : %d\n", x, a, e->cost[i][j]);
				}
				Add_queue(x); //제거한 x를 큐에 추가
			}
		}


	for (i = 0; i < n*n; i++) {
		dele = delete(e, n, i); //삭제한 값 대입
		printf(" %d ", dele);
	}

}


void main()
{
	int i, j;

	int n = 2;

	int *matrix = (int)malloc(sizeof(int)*(n*n)); //공간할당
	
		for (i = 0; i < n; i++) {
			for (j = 0; j < i + 1; j++) {
				if (i == j)  //[0,0] ... [5,5]와 같이 인덱스가 같으면 가중치 0
					matrix[i*n + j] = 0;
				else {
					matrix[i*n + j] = ( rand() % 12 )+ 1;  //랜덤 수 저장
					matrix[j*n + i] = matrix[i*n + j];
				}
			}
		} //여기까지 행렬만듦.
	
			printf("**matrix**\n");
	
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++)
					printf(" %d ", matrix[i*n + j]);
	
				printf("\n");
			}

	Prim(matrix, 0); // Prim 알고리즘 함수호출

}