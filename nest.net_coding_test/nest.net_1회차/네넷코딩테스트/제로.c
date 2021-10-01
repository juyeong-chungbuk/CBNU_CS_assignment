//#include<stdio.h>
//
//void main()
//{
//	int k;
//	scanf("%d", &k);
//	int sum = 0;
//	int n;
//	int *num = (int*)malloc(sizeof(int)*k);
//	int count = 0;
//
//	for (int i = 0; i < k; i++) {
//
//		scanf("%d", &n);
//		
//		if (n != 0) {
//			*num = n;
//			num++;
//			count++;
//		}
//		else {
//			num--;
//			count--;
//		}
//
//	}
//	for(int i=0;i<count;i++){
//		--num;
//		sum += *num;
//	}
//
//	printf("%d", sum);
//}