#include<stdio.h>
void Algorithm3(int n, int S[]);
void swap(int *i, int *j);

void main()
{
	int n;
	int *S;

	printf("문제: n정수로 구성된 리스트 S에 숫자를 더하라\n");
	printf("양의 정수 n을 입력하세요: ");
	scanf("%d", &n);

	S = malloc((n+1) * sizeof(int));

	printf("배열 S에 저장할 %d개의 정수를 입력하세요: \n", n);
	for (int i = 1; i <= n; i++) {
		S[i] = Array();
	}
	Algorithm3(n, S);
	for (int j = 1; j <= n; j++)
		printf(" %d ", S[j]);
}

void Algorithm3(int n, int S[])
{
	int i, j; //1번

	for (i = 1; i <= n; i++) { //n번
		for (j = i + 1; j <= n; j++) { //n-2번 n-3번 n-4번 ... 1번 => (n-2)(n-1)*1/2
			if (S[j] < S[i])
				swap(&S[i], &S[j]);
		}
	}  //총 1+n+(n-2)+(n-3)+(n-4)+...+1 = 1+2+3+...+n+1-n+1 = n*(n+1)*1/2 - (n+2)
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