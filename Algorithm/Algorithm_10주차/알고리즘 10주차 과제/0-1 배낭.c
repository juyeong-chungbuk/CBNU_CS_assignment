#include<stdio.h>

void print(int B[][6], int m[][6])
{
	printf("* B[0..n, ..W] *\n");
	printf("   ");
	for (int j = 0; j <= 5; j++)
		printf(" %d", j);
	printf("\n---------------\n");

	for (int i = 0; i <= 5; i++) {
		printf("%d |", i);
		for (int j = 0; j <= 5; j++) {
			printf(" %d", B[i][j]);
		}
		printf("\n");
	}

	printf("\n* m[0..n, ..W] *\n");
	printf("   ");
	for (int j = 0; j <= 5; j++)
		printf(" %d", j);
	printf("\n---------------\n");

	for (int i = 0; i <= 5; i++) {
		printf("%d |", i);
		for (int j = 0; j <= 5; j++) {
			printf(" %d", m[i][j]);
		}
		printf("\n");
	}
}

void Knapsack(int item[][2])
{
	int B[6][6];
	int m[6][6];

	for (int j = 0; j <= 5; j++) {
		B[0][j] = 0;
		m[0][j] = 0; //맨 윗줄 0으로 초기화
	}
	for (int i = 1; i <= 5; i++) {
		B[i][0] = 0;
		m[i][0] = 0; //맨 왼쪽줄 0으로 초기화

		for (int j = 1; j <= 5; j++) {

			if (item[i][0] <= j) { //w 무게보다 j가 크거나 같아지면

				if (B[i - 1][j - item[i][0]]+item[i][1] > B[i - 1][j]) { //바로 윗줄의 가치값보다 (바로 윗줄에서 j-Wi 를 뺐을 때의 가치 + i번째 가치)가 더 클 경우
					B[i][j] = B[i - 1][j - item[i][0]] + item[i][1]; //더 큰값으로 변경
					m[i][j] = 1; //값이 변했음.
				}

				else { //바로 윗줄의 가치가 더 클 경우
					B[i][j] = B[i - 1][j]; //그대로 가치값 받음
					m[i][j] = 0; //변하지않음.
				}

			}

			else { //w무게보다 j가 작을 경우
				B[i][j] = B[i - 1][j]; //바로 위 가치를 그대로 받음.
				m[i][j] = 0; //가치가 변하지 않음
			}

		}
	}
	print(B, m);
}

void main()
{
	int item[6][2] = { {0,0}, {3,2}, {4,3}, {2,2}, {5,4}, {1,2} };

	Knapsack(item); 
}