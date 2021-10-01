//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct list {
//	long long data;
//	struct list *next;
//}List;
//int count = 0;
//int morenum = 0;
//List *head = NULL, *tail = NULL;
//
//void add_node(long long data) {
//
//	List *node = (List*)malloc(sizeof(List));
//	node->data = data;
//	node->next = NULL;
//
//	if (head == NULL) {
//		head = tail = node;
//		count++;
//	}
//	else {
//		tail->next = node;
//		tail = node;
//		count++;
//	}
//}
//
//int explore(long long data)
//{
//	List *node = head;
//
//	if (node == NULL) {
//		return 1;
//	}
//
//	while (node != NULL) {
//		if (node->data == data) {
//			return 0;
//		}
//		node = node->next;
//	}
//	return 1;
//	
//}
//
//void main()
//{
//	long long n;
//	int ex;
//
//	FILE *fp = fopen("input.txt", "r"); //읽기모드로 파일열기
//
//	while (!feof(fp)) {
//		fscanf(fp, "%lld\n", &n);
//
//		if (head == NULL) {
//			add_node(n);
//		}
//		else {
//			ex = explore(n);
//
//			if (ex == 1) {
//				add_node(n);
//			}
//		}
//
//		if (n > 5000)
//			morenum++;
//	}
//
//	printf("The total number of nodes: %d\n", count);
//	printf("More than 5000 values: %d\n", morenum);
//
//	fclose(fp);
//}