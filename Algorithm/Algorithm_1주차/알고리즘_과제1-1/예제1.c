//#include<stdio.h>
//int Array();
//void Algorithm1(int n, const int S[], int x, int location);
//
//void main()
//{
//	int n;
//	int *S;
//	int x;
//	int location = 0;
//
//	printf("����: n������ ������ ����Ʈ S�� ���� x�� �ִ°�? \n");
//	printf("���� ���� n�� �Է��ϼ���: ");
//	scanf("%d", &n);
//	S = malloc(n*sizeof(int));
//
//	printf("�迭 S�� ������ %d���� ������ �Է��ϼ���: ", n);
//
//	for (int i = 0; i < n; i++)
//		S[i] = Array();
//	printf("ã�� ���� ������ �Է��ϼ���: \n");
//	scanf("%d", &x);
//	Algorithm1(n, S, x, 0);
//}
//
//void Algorithm1(int n, const int S[], int x, int location)
//{
//	location = 1;  //1��
//
//	while (location <= n && S[location] != x)  //n+n��
//		location++;  //n��
//
//	if (location > n) { //1��
//		location = 0; //1��                    -> �� 3n+3��
//		printf("%d", location);
//		return;
//	}
//	printf("%d", x);
//}
//
//int Array()
//{
//	int num;
//	scanf("%d", &num);
//
//	return num;
//}