#include<stdio.h>

void print(int C[][6]) { //��� �Լ�
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

void optimal_BST(int C[][6]) //��������Ʈ�� �Լ�
{
	int f[6] = { 0,3,2,4,1,0 };

	for (int i = 1; i <= 4; i++) {
		C[i][i - 1] = 0; //�밢�� �����δ� 0
		C[i][i] = f[i]; //(i,i)��° ���� f(i)�� �־���
	}
	

	for (int a = 1; a < 4; a++) {
		for (int i = 1; i <= 4 - a; i++) {
			int j = a + i;
			int sum = 0;

			for (int num = i; num <= j; num++) {
				sum += f[num];
			}

			int k = i;

			C[i][j] = (C[i][k - 1] + C[k + 1][j]) + sum; //k=i�� �� �� �켱 ����.

			for (k = i+1; k <= j; k++) { //k=i+1���� �����ؼ� j�� �� ������ �ݺ�
				if (C[i][j] > (C[i][k-1] + C[k+1][j] + sum)) { //���� C(i,j)���� ���� ���� ������
					C[i][j] = (C[i][k - 1] + C[k+1][j]) + sum; //�ٲ��ֱ�
				}
			}
			
		}
	}

	print(C);
}

void main()
{
	int C[6][6] = { 0 }; //��� ���� 0���� �ʱ�ȭ

	optimal_BST(C);
}