#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int col[5] = { 5,6,10,11,16 };
int W = 21;
int w[5] = { 0 };

bool promising(int i, int weight, int total)
{
	return (weight + total >= W) && (weight == W || weight + col[i + 1] <= W);
}

void print() //출력함수
{
	printf("Sum of Subsets : {");
	for (int i = 0; i < 5; i++) {
		if (w[i] != 0) {
			printf(" %d", w[i]);
		}
	}
	printf(" }\n");
}

void sum_of_subsets(int i, int weight, int total) {
	if (promising(i,weight,total)) { //i번쨰 원소의 조합이 답이 될 수 있는지 판단
		if (weight == W)
			print(); //subset 출력
		else {
			w[i + 1] = col[i + 1];
			sum_of_subsets(i + 1, weight + col[i + 1], total - col[i + 1]);
			w[i + 1] = 0;
			sum_of_subsets(i + 1, weight, total - col[i + 1]); //재귀를 이용하여 weight + col[i + 1]가 21과 같아질 때까지
		}
	}

}

void main()
{
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += col[i]; //전체 합 넣기
	}
	sum_of_subsets(-1, 0, total);
}