#include<stdio.h>
void sort(int score[5][3]);
void swap(int *n, int *m);
void print_score(int score[5][3]);

void main()
{
	int score[5][3] = {
	{30,10,11},
	{40,90,32},
	{70,65,56},
	{70,43,32},
	{80,10,89}
	};

	sort(score[5][3]);
	print_score(score[5][3]);
}

void sort(int score[5][3])
{
	int minindex;

	for (int n = 0; n < 5; n++) {
		minindex = find_min(score[5][3], n);
		for (int m = 0; m < 3; m++)
			swap(&score[minindex][m], &score[n][m]);
	}
}

int find_min(int score[5][3], int n)
{
	int minindex = n;

	for (int k = 0; k < 3; k++)
	{
		for (int m = n+1; m < 5; m++)
		{
			if(score[minindex][k] > score[m][k])
				minindex = m;
			return minindex;
		}
	}
}

void swap(int *n,int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}

void print_score(int score[5][3])
{
	printf("시험#1의 최저 점수: %d , 최대 점수: %d", score[0][0],score[4][0]);
	printf("시험#2의 최저 점수: %d , 최대 점수: %d", score[0][1],score[4][1]);
	printf("시험#3의 최저 점수: %d , 최대 점수: %d", score[0][2],score[4][2]);
}