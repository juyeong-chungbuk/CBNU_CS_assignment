#include<stdio.h>
void Algorithm3(int n, int S[]);
void swap(int *i, int *j);

void main()
{
	int n;
	int *S;

	printf("����: n������ ������ ����Ʈ S�� ���ڸ� ���϶�\n");
	printf("���� ���� n�� �Է��ϼ���: ");
	scanf("%d", &n);

	S = malloc((n+1) * sizeof(int));

	printf("�迭 S�� ������ %d���� ������ �Է��ϼ���: \n", n);
	for (int i = 1; i <= n; i++) {
		S[i] = Array();
	}
	Algorithm3(n, S);
	for (int j = 1; j <= n; j++)
		printf(" %d ", S[j]);
}

void Algorithm3(int n, int S[])
{
	int i, j; //1��

	for (i = 1; i <= n; i++) { //n��
		for (j = i + 1; j <= n; j++) { //n-2�� n-3�� n-4�� ... 1�� => (n-2)(n-1)*1/2
			if (S[j] < S[i])
				swap(&S[i], &S[j]);
		}
	}  //�� 1+n+(n-2)+(n-3)+(n-4)+...+1 = 1+2+3+...+n+1-n+1 = n*(n+1)*1/2 - (n+2)
}

void swap(int *i, int *j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

int Array()
{
	int num;
	scanf("%d", &num);

	return num;
}