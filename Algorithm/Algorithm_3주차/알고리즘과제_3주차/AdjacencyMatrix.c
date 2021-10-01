#include <stdio.h>
#define N 10

void main() {
	
	int a, b;
	int adj_matrix[N][N] = { 0,0 }; //배열을 모두 0으로 초기화

	printf("정점의 개수, 간선의 개수 입력: ");
	scanf("%d%d", &a, &b); //정점, 간선의 수

	for (int i = 0; i < b; i++) {
		int s, e;
		scanf("%d%d", &s, &e); //입력을 받아서 adj_matrix[s][e]에 1을 대입하면 끝이니까, 인접한지 체크=1번 반복
		adj_matrix[s][e] = 1; //0을 1로 바꿔줌
		adj_matrix[e][s] = 1; //행, 열 바꾼 값도 1
	}

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= a; j++) {
			printf("  %d  ", adj_matrix[i][j]); //각각 a번만큼 반복해서 출력하므로 
			                                   //i번째에 있는 정점과 인접한 모든 정점을 탐색하는데 a번의 시간이 걸림
		}
		printf("\n");
	}
}
