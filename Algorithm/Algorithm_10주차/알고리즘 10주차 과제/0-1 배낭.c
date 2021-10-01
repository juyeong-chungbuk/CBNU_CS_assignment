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
		m[0][j] = 0; //�� ���� 0���� �ʱ�ȭ
	}
	for (int i = 1; i <= 5; i++) {
		B[i][0] = 0;
		m[i][0] = 0; //�� ������ 0���� �ʱ�ȭ

		for (int j = 1; j <= 5; j++) {

			if (item[i][0] <= j) { //w ���Ժ��� j�� ũ�ų� ��������

				if (B[i - 1][j - item[i][0]]+item[i][1] > B[i - 1][j]) { //�ٷ� ������ ��ġ������ (�ٷ� ���ٿ��� j-Wi �� ���� ���� ��ġ + i��° ��ġ)�� �� Ŭ ���
					B[i][j] = B[i - 1][j - item[i][0]] + item[i][1]; //�� ū������ ����
					m[i][j] = 1; //���� ������.
				}

				else { //�ٷ� ������ ��ġ�� �� Ŭ ���
					B[i][j] = B[i - 1][j]; //�״�� ��ġ�� ����
					m[i][j] = 0; //����������.
				}

			}

			else { //w���Ժ��� j�� ���� ���
				B[i][j] = B[i - 1][j]; //�ٷ� �� ��ġ�� �״�� ����.
				m[i][j] = 0; //��ġ�� ������ ����
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