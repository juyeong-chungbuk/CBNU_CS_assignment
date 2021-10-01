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

	if (weight >= W) //16보다 커지면
		return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= n) && (totweight + w[j] <= W)) { //j가 4까지, i+1부터 더한 무게값이 16보다 작거나 같을 경우
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight)*p[k] / w[k]; //bound 뒷부분 마저 더해줌
		return (bound > maxprofit);
	}

}

void knapsack(int i, int profit, int weight)
{
	if (weight <= W && profit > maxprofit) { //무게가 16보다 작은데 가치가 최대가치보다 커질 경우
		maxprofit = profit; //최대가치를 바꿔줌
		for (int j = 0; j <= n; j++)
			bestset[j] = include[j]; //최적에 들어갈
	}
	if (promising(i, profit, weight)) {
		include[i + 1] = 1; count++;  //count로 들어가는 노드의 개수를 체크
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);

		include[i + 1] = 0;
		knapsack(i + 1, profit, weight);
	}
}

void main()
{
	knapsack(0, 0, 0);

	printf("총 Node의 수 : %d\n",count);
	printf("max profit : %d\n", maxprofit);
}