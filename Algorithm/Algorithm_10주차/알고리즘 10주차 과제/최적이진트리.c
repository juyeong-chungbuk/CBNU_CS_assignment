#include<stdio.h>

void print(int C[][6]) { //출력 함수
	printf("  ");
	for (int j = 1; j <= 4; j++)
		printf(" %d ", j);
	printf("\n-------------\n");

	for (int i = 1; i <= 4; i++) {
		printf("%d |", i);
		for (int j = 1; j <= 4; j++) {
			printf(" %d", C[i][j]);
		}
		printf("\n");
	}
}

void optimal_BST(int C[][6]) //최적이진트리 함수
{
	int f[6] = { 0,3,2,4,1,0 };

	for (int i = 1; i <= 4; i++) {
		C[i][i - 1] = 0; //대각선 밑으로는 0
		C[i][i] = f[i]; //(i,i)번째 값을 f(i)로 넣어줌
	}
	

	for (int a = 1; a < 4; a++) {
		for (int i = 1; i <= 4 - a; i++) {
			int j = a + i;
			int sum = 0;

			for (int num = i; num <= j; num++) {
				sum += f[num];
			}

			int k = i;

			C[i][j] = (C[i][k - 1] + C[k + 1][j]) + sum; //k=i일 때 값 우선 대입.

			for (k = i+1; k <= j; k++) { //k=i+1부터 시작해서 j가 될 때까지 반복
				if (C[i][j] > (C[i][k-1] + C[k+1][j] + sum)) { //현재 C(i,j)보다 작은 값이 있으면
					C[i][j] = (C[i][k - 1] + C[k+1][j]) + sum; //바꿔주기
				}
			}
			
		}
	}

	print(C);
}

void main()
{
	int C[6][6] = { 0 }; //모든 값을 0으로 초기화

	optimal_BST(C);
}