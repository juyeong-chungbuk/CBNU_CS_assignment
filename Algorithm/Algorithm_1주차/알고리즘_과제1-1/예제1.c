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
//	printf("문제: n정수로 구성된 리스트 S에 정수 x가 있는가? \n");
//	printf("양의 정수 n을 입력하세요: ");
//	scanf("%d", &n);
//	S = malloc(n*sizeof(int));
//
//	printf("배열 S에 저장할 %d개의 정수를 입력하세요: ", n);
//
//	for (int i = 0; i < n; i++)
//		S[i] = Array();
//	printf("찾고 싶은 정수를 입력하세요: \n");
//	scanf("%d", &x);
//	Algorithm1(n, S, x, 0);
//}
//
//void Algorithm1(int n, const int S[], int x, int location)
//{
//	location = 1;  //1번
//
//	while (location <= n && S[location] != x)  //n+n번
//		location++;  //n번
//
//	if (location > n) { //1번
//		location = 0; //1번                    -> 총 3n+3번
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