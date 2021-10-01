#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int recursive(int n,int  k);
int factorial(int n);

void main()
{
	int k, n;
	int result = 0;

	printf("nCk 에서 n,k 값을 입력하세요: ");
	scanf_s("%d %d", &n,&k);

		if (k > 0 && k < n)
			result += recursive(n - 1, k - 1) + recursive(n - 1, k);
		else
			result += recursive(1, 1);

	printf("%d",result);
}

int factorial(int n)
{
	if (n == 1|| n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int recursive(int n, int k)
{
	return factorial(n) / (factorial(n - k)*factorial(k));
}