//#include<stdio.h>
//int Algorithm2(int n, const int S[]);
//int Array();
//
//void main()
//{
//	int n;
//	int *S;
//	int sum = 0;
//
//	printf("����: n������ ������ ����Ʈ S�� ���ڸ� ���϶�\n");
//	printf("���� ���� n�� �Է��ϼ���: ");
//	scanf("%d", &n);
//
//	S = malloc((n+1) * sizeof(int));
//
//	printf("�迭 S�� ������ %d���� ������ �Է��ϼ���: \n", n);
//	for (int i = 1; i <= n; i++) {
//		S[i] = Array();
//	}
//	sum = Algorithm2(n, S);
//	printf("��� sum = %d", sum);
//}
//
//int Algorithm2(int n, const int S[])
//{
//	int i;
//	int result = 0; //1��
//
//	for (i = 1; i <= n; i++)     //1+n+n��
//		result = result + S[i];  //n��
//	return result;   //1��              -> �� 3n+3��
//}
//
//int Array()
//{
//	int num;
//	scanf("%d", &num);
//
//	return num;
//}