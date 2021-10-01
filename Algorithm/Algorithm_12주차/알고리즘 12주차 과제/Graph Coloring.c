#include<stdio.h>
#include<stdbool.h>
int n = 4;
int m = 3;
bool W[4][4];
int vcolor[3];

void print()
{
	for (int i = 0; i < n; i++) {
		printf("V%d color :", i + 1);
		printf(" %d ", vcolor[i]);
	}
	printf("\n");
}

bool promising(int i)
{
	int j = 1;
	bool swit = true;

	while (j < i&&swit) {
		if (W[i][j] && vcolor[i] == vcolor[j]) {
			swit = false;
		}
		j++;
	}
	return swit;
}

void m_coloring(int i) {

	int color;

	if (promising(i)) {
		if (i == n) {
			print();
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color; //넣을 컬러
				m_coloring(i + 1);
			}
		}
	}

}

void main()
{
	m_coloring(0);
}