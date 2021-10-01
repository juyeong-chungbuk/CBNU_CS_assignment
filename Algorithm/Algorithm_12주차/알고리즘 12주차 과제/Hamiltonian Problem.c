#include<stdio.h>
#include<stdbool.h>

int n = 5;
int W[5][5] = {
	{0,1,0,0,1},
	{1,0,1,1,1},
	{0,1,0,1,0},
	{1,1,0,0,0}
};
int vindex[5];

void print()
{
	for (int j = 0; j <= n - 1; j++) {
		printf("%d %d ", j, vindex[j+1]);
	}
	printf("\n");
}

bool promising(int i) {

	int j = 1;
	bool swit = true;

	if (i == n - 1 && W[vindex[n-1]][vindex[0]]==0) {
		swit = false;
	}
	else if (i > 0 && W[vindex[i - 1]][vindex[i]]==0) {
		swit = false;
	}
	else {
		while (j < i && swit) {
			if (vindex[i] == vindex[j])
				swit = false;
			j++;
		}
	}
	return swit;
}

void hamiltonian(int i)
{
	int j;

	if (promising(i)) {
		if (i == n - 1) {
			print();
		}
		else {
			for (j = 2; j <= n; j++) {
				vindex[i + 1] = j;
				hamiltonian(i + 1);
			}
		} //promising(2)가 false라서 vindex[2]까지만 가고 종료됨. -> print하지 않음
	}

}

void main()
{
	vindex[0] = 1;
	hamiltonian(0);
}