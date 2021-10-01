//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct list {
//	long long data;
//	struct list *next;
//}List;
//
//void add_node(List* head, long long data) {
//
//	List *node = (List*)malloc(sizeof(List));
//	List *node2 = (List*)malloc(sizeof(List));
//	node = head;
//	node->data = data;
//	node2->data = data;
//
//	if (head->next == NULL) { //처음 데이터 넣기
//		head->next = node;
//		node->next = head; //자기자신을 가리키도록
//	}
//
//	else {
//
//		while (node->next != head) {
//			node = node->next;
//		}
//		
//		node->next = node2;
//		node2->next = head;
//	}
//
//}
//
//int explore(List* head, long long data)
//{
//	List *node = (List*)malloc(sizeof(List));
//
//	node = head;
//
//		do {
//			node = node->next;
//			if (node->data == data) {
//				return 0;
//			}
//		} while (node->next != head);
//
//		return 1;
//}
//
//void main()
//{
//	List *head = (List*)malloc(sizeof(List));
//	head->next = NULL;
//
//	FILE *fp;
//	fp = fopen("input.txt", "r"); //읽기모드로 파일열기
//
//	int count = 0; //리스트에 있는 숫자의 개수
//	int morenum = 0; //5000이 넘는 숫자의 개수
//	long long n;
//	int ex;
//
//	while (!feof(fp)) {
//		fscanf(fp, "%lld\n", &n);
//
//		if (head->next == NULL) {
//			add_node(head, n);
//		}
//		else {
//			ex = explore(head, n);
//			if (ex == 1) { //중복값이 없을 경우
//				add_node(head, n);
//				count++;
//			}
//		}
//		if (n > 5000)
//			morenum++;
//
//	}
//
//
//	printf("The total number of nodes: %d\n", count);
//	printf("More than 5000 values: %d\n", morenum);
//
//	
//	free(head);
//	fclose(fp);
//}	
//	//
//	//List *node1;
//	//node1 = head;
//	//while (node1->next != head) {
//	//	node1 = node1->next;
//	//}
//	//node1->next = NULL;
////List* prev;
//	//while (head->next != NULL) {
//	//	prev = head;
//	//	head = head->next;
//	//	free(prev);
//	//}
//
