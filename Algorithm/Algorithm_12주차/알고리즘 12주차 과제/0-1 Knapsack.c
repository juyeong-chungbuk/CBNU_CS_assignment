#include<stdio.h>
#include<stdbool.h>
int W = 16;
int n = 4;
int w[5] = { 0,2,5,10,5 };
int p[5] = { 0,40,30,50,10 };
int maxprofit = 0;
int bestset[5];
int include[5];
int count = 0;

bool promising(int i, int profit, int weight)
{
	int j, k;
	int totweight = weight;
	int bound = profit;

	if (weight >= W) //16���� Ŀ����
		return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= n) && (totweight + w[j] <= W)) { //j�� 4����, i+1���� ���� ���԰��� 16���� �۰ų� ���� ���
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight)*p[k] / w[k]; //bound �޺κ� ���� ������
		return (bound > maxprofit);
	}

}

void knapsack(int i, int profit, int weight)
{
	if (weight <= W && profit > maxprofit) { //���԰� 16���� ������ ��ġ�� �ִ밡ġ���� Ŀ�� ���
		maxprofit = profit; //�ִ밡ġ�� �ٲ���
		for (int j = 0; j <= n; j++)
			bestset[j] = include[j]; //������ ��
	}
	if (promising(i, profit, weight)) {
		include[i + 1] = 1; count++;  //count�� ���� ����� ������ üũ
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = 0;
		knapsack(i + 1, profit, weight);
	}
}

void main()
{
	knapsack(0, 0, 0);

	printf("�� Node�� �� : %d\n",count);
	printf("max profit : %d\n", maxprofit);
}