#include<stdio.h>

typedef struct X {
	int a[20];
}x;

void main()
{
	int n;
	scanf("%d", &n); //���ǰ���
	int count = 0; //�ű� Ƚ��
	int *str[2];

	x x[3];

	for (int i = 1; i <= n; i++) {
		x[0].a[i] = i;
		x[1].a[i] = 20;
		x[2].a[i] = 20;
	}

	while (!x[2].a[n]) {
		for (int i = 1; i <= n; i++) {
			if (x[0].a[i] < x[2].a[i]) { //1���� 3����
				if (x[0].a[i] < x[1].a[i]) { //1���� 2��
					x[1].a[i+1] = x[0].a[i];
					count++;
					*str[0] = 1;
					*str[1] = 2;
				}
				x[2].a[i+1] = x[0].a[i];
				count++;
				*str[0] = 1;
				*str[1] = 3;
			}

			else if (x[2].a[i] < x[1].a[i]) { //3���� 2��
				if (x[2].a[i] < x[0].a[i]) { //3���� 1��
					x[2].a[i+1] = x[0].a[i];
					count++;
					*str[0] = 3;
					*str[1] = 1;
				}
				x[1].a[i+1] = x[2].a[i];
				count++;
				*str[0] = 3;
				*str[1] = 2;
			}

			else if (x[1].a[i] < x[0].a[i]) { //2���� 1��
				if (x[1].a[i] < x[2].a[i]) { //2���� 3����
					x[2].a[i+1] = x[1].a[i];
					count++;
					*str[0] = 2;
					*str[1] = 3;
				}
				x[0].a[i+1] = x[1].a[i];
				count++;
				*str[0] = 2;
				*str[1] = 1;
			}
		}
	}
	printf("%d\n", count);

	for (int i = 0; i < 7; i++) {
		printf("%d %d", *str[0], *str[1]);
		str[0]++;
		str[1]++;
	}
}