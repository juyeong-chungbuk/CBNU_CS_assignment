//Q.10
//#include<stdio.h>
//
//void main()
//{
//	int a, b;
//	int sub = 0;
//	
//	printf("a�� ��:");
//	scanf("%d", &a);
//
//	do {
//		printf("b�� ��:");
//		scanf("%d", &b);
//		if(b<=a)
//		printf("a���� ū ���� �Է��ϼ���!\n");
//	} while (b <= a);
//
//	sub = b - a;
//	printf("b-a�� %d�Դϴ�.\n", sub);
//}

//Q.11
//#include<stdio.h>
//
//void main()
//{
//	int num;
//	int i;
//
//	printf("���� �Է�: ");
//	scanf_s("%d", &num);
//
//	for (i = 1; num > 0; i++)
//		num = num / 10;
//
//	printf("�� ���� %d�ڸ��Դϴ�.\n", i-1);
//}

//�ǽ� 1-7
//#include<stdio.h>
//
//void main()
//{
//	int i, j;
//	 
//	printf("\t\t----����ǥ----\t\n");
//
//	for (i = 1; i <= 9; i++) {
//		printf("%5d",i);
//		for (j = 2; j <= 9; j++) {
//			printf("%5d", i*j);
//		}
//		printf("\n");
//	}
//}

//Q.13
//#include<stdio.h>
//
//void main()
//{
//	int i, j;
//
//	printf("\t\t----����ǥ----\t\t\n");
//
//	for (i = 1; i <= 9; i++) {
//		printf("%5d",i);
//		for (j = 1; j <= 8; j++) {
//			if (i == 1)
//				printf("%5d", i + j);
//			else
//			printf("%5d", i+j+1);
//		}
//		printf("\n");
//	}
//}

//Q.13 ����.
//#include <stdio.h>
//
//int main(void)
//{
//	int i, j;
//
//	printf("   |");
//	for (i = 1; i <= 9; i++)
//		printf("%3d", i);
//
//	printf("\n - + --------------------------- \n");
//
//	for (i = 1; i <= 9; i++) {
//		printf("%2d |", i);
//		for (j = 1; j <= 9; j++)
//			printf("%3d", i + j);
//		putchar('\n');
//	}
//
//	return 0;
//}


//Q.14
//#include<stdio.h>
//
//void main()
//{
//	int num;
//
//	printf("�簢���� ����մϴ�.\n");
//	printf("�Է��� ��: ");
//	scanf("%d", &num);
//
//	for (int i = 0; i < num; i++) {
//		for(int j=0;j<num;j++)
//			printf("*");
//		printf("\n");
//	}
//}

//Q.15
//#include<stdio.h>
//
//void main()
//{
//	int x, y;
//
//	printf("���簢���� ����մϴ�.\n");
//	printf("����: ");
//	scanf("%d", &x);
//	printf("�ʺ�: ");
//	scanf("%d", &y);
//
//	for (int i = 0; i < x; i++) {
//		for (int j = 0; j < y; j++)
//			printf("*");
//		printf("\n");
//	}
//}

//Q.1
#include<stdio.h>

void main()
{

}