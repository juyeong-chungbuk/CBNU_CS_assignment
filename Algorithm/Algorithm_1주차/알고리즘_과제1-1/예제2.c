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
//	printf("문제: n정수로 구성된 리스트 S에 숫자를 더하라\n");
//	printf("양의 정수 n을 입력하세요: ");
//	scanf("%d", &n);
//
//	S = malloc((n+1) * sizeof(int));
//
//	printf("배열 S에 저장할 %d개의 정수를 입력하세요: \n", n);
//	for (int i = 1; i <= n; i++) {
//		S[i] = Array();
//	}
//	sum = Algorithm2(n, S);
//	printf("결과 sum = %d", sum);
//}
//
//int Algorithm2(int n, const int S[])
//{
//	int i;
//	int result = 0; //1번
//
//	for (i = 1; i <= n; i++)     //1+n+n번
//		result = result + S[i];  //n번
//	return result;   //1번              -> 총 3n+3번
//}
//
//int Array()
//{
//	int num;
//	scanf("%d", &num);
//
//	return num;
//}