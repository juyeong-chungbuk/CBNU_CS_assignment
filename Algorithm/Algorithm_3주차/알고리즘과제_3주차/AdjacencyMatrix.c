#include <stdio.h>
#define N 10

void main() {
	
	int a, b;
	int adj_matrix[N][N] = { 0,0 }; //�迭�� ��� 0���� �ʱ�ȭ

	printf("������ ����, ������ ���� �Է�: ");
	scanf("%d%d", &a, &b); //����, ������ ��

	for (int i = 0; i < b; i++) {
		int s, e;
		scanf("%d%d", &s, &e); //�Է��� �޾Ƽ� adj_matrix[s][e]�� 1�� �����ϸ� ���̴ϱ�, �������� üũ=1�� �ݺ�
		adj_matrix[s][e] = 1; //0�� 1�� �ٲ���
		adj_matrix[e][s] = 1; //��, �� �ٲ� ���� 1
	}

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= a; j++) {
			printf("  %d  ", adj_matrix[i][j]); //���� a����ŭ �ݺ��ؼ� ����ϹǷ� 
			                                   //i��°�� �ִ� ������ ������ ��� ������ Ž���ϴµ� a���� �ð��� �ɸ�
		}
		printf("\n");
	}
}
