//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct list {
//	int value;
//	struct list *next;
//}List;
//
//typedef struct head {
//	struct list *next; //list를 가리키는 포인터
//}Head;
//
//typedef struct tail {
//	struct head *next; //head를 가리키는 포인터
//}Tail;
//
//void main()
//{
//	FILE *fp;
//	fp = fopen("C:\\input.txt", "r"); //읽기모드로 파일열기
//
//	//List *root = (List*)malloc(sizeof(List));
//
//	Head *root = (Head*)malloc(sizeof(Head)); //node의 처음부터 비교할 값
//	List *node = (List*)malloc(sizeof(List)); //중복안되는 값만 넣을 포인터
//	root->next = node;
//	node->next = root;
//	
//	int count = 0; //리스트에 들어가는 숫자의 개수
//	int morenum = 0; //5000이 넘어가는 숫자의 개수
//
//	if (fp == NULL) { //파일이 읽히지 않았다면
//		fprintf(stderr, "Can't open file\n"); //파일 열 수 없음.
//		exit(1); //종료
//	}
//	List *allnode = (List*)malloc(sizeof(List)); //모든 수를 넣을 포인터
//
//	while (!feof(fp)) {
//		fscanf(fp, "%d \n", &(allnode->value));
//		allnode = allnode->next;
//	} //파일의 모든 숫자를 allnode에 넣기
//
//
//	while (!feof(fp)) { //한 줄씩 읽기 //allnode를 1,2,3순서대로 넘어가면서 node의 맨처음부터 있는지 검사
//		
//		//fscanf(fp, "%d \n", &(node->value)); //일단 처음값 node에 넣고
//		node->value = allnode->value;
//
//		while (allnode->next != NULL) { //파일의 모든 숫자를 다 읽을때까지
//			
//		}
//						
//						
//						
//						
//		/*node->value = 0;*/
//		fscanf(fp, "%d \n", &(node->value));
//
//		while (root->next != NULL) {
//
//			if (node->value != root->next->value) {
//				
//				fscanf(fp, "%d \n", &(node->value));
//				root = root -> next;
//				count++;
//			}
//			else {
//				node = node->next;
//			}
//
//			root = root->next;
//
//
//			node = node->next;
//			root->next->value = 1;
//			root = root->next;
//			if (node->value > 5000) {
//				morenum++;
//			}
//		}
//
//	} 
//
//	printf("The total number of nodes: %d", count);
//	printf("More than 5000 values: %d", morenum);
//	free(node);
//	fclose(fp);
//}