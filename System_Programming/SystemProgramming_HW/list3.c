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
//	if (head->next == NULL) { //ó�� ������ �ֱ�
//		head->next = node;
//		node->next = head; //�ڱ��ڽ��� ����Ű����
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
//	fp = fopen("input.txt", "r"); //�б���� ���Ͽ���
//
//	int count = 0; //����Ʈ�� �ִ� ������ ����
//	int morenum = 0; //5000�� �Ѵ� ������ ����
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
//			if (ex == 1) { //�ߺ����� ���� ���
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
