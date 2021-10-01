//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define n 20
//#define m 20
//
//void main()
//{
//	int tile[n][m] = { 0 };
//	tile[10][10] = 1;
//	int number;
//	int count = 0;
//	unsigned int max_moving = 0;
//	
//	while (count < 40 || max_moving <= 100000) {
//		for (int i = 10; count < 40;)
//		{
//			for (int j = 10; count < 40;)
//			{
//				number = rand() % 8;
//
//				switch (number)
//				{
//				case 0:
//					if (tile[i - 1][j] != 1)
//						tile[i - 1][j] = 1;
//					else
//						break;
//				case 1:
//					if (tile[i - 1][j + 1] != 1)
//						tile[i - 1][j + 1] = 1;
//					else
//						break;
//				case 2:
//					if (tile[i][j + 1] != 1)
//						tile[i][j + 1] = 1;
//					else
//						break;
//				case 3:
//					if (tile[i + 1][j + 1] != 1)
//						tile[i + 1][j + 1] = 1;
//					else
//						break;
//				case 4:
//					if (tile[i + 1][j] != 1)
//						tile[i + 1][j] = 1;
//					else
//						break;
//				case 5:
//					if (tile[i + 1][j - 1] != 1)
//						tile[i + 1][j - 1] = 1;
//					else
//						break;
//				case 6:
//					if (tile[i][j - 1] != 1)
//						tile[i][j - 1] = 1;
//					else
//						break;
//				default:
//					if (tile[i - 1][j - 1] != 1)
//						tile[i - 1][j - 1] = 1;
//					else
//						break;
//				}
//				count += 1;
//				max_moving += 1;
//			}
//		}
//	}
//	printf("딱정벌레가 방안의 모든 타일을 한 번씩 지나가는데 걸리는 총 이동수는 얼마인가? %u", max_moving);
//}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 7
#define Y 7

int main() {
	char tile[Y][X] = { 0 };
	int x, y, i, j;
	int count = 0, remain;
	srand((unsigned)time(NULL));

	x = X / 2;
	y = Y / 2;
	tile[y][x] = 1;

	while (1) {
		for (i = 0; i < Y; i++) {
			for (j = 0; j < X; j++) {
				if (tile[i][j] == 1)
					printf("■ ");
				else
					printf("□ ");
			}
			printf("\n");
		}
		printf("\n");

		remain = 0;
		for (i = 0; i < Y; i++)
			for (j = 0; j < X; j++)
				if (tile[i][j] == 1)
					remain++;
		if (remain == Y * X) break;

		switch (rand() % 8) {
		case 0:
			if (y == 0) break;
			tile[y--][x] = 1;
			count++;
			break;
		case 1:
			if (y == 0 || x == X - 1) break;
			tile[y--][x++] = 1;
			count++;
			break;
		case 2:
			if (x == X - 1) break;
			tile[y][x++] = 1;
			count++;
			break;
		case 3:
			if (y == Y - 1 || x == X - 1) break;
			tile[y++][x++] = 1;
			count++;
			break;
		case 4:
			if (y == Y - 1) break;
			tile[y++][x] = 1;
			count++;
			break;
		case 5:
			if (y == Y - 1 || x == 0) break;
			tile[y++][x--] = 1;
			count++;
			break;
		case 6:
			if (x == 0) break;
			tile[y][x--] = 1;
			count++;
			break;
		case 7:
			if (y == 0 || x == 0) break;
			tile[y--][x--] = 1;
			count++;
			break;
		}
	}
	printf("총이동수 : %d\n", count);

	return 0;
}
