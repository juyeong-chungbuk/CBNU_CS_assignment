//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct list {
//	long long data;
//	struct list *prev;
//	struct list *next;
//}List;
//
//void add_node(List* head, long long data) {
//	
//	List *node = (List*)malloc(sizeof(List));
//	List *node2 = (List*)malloc(sizeof(List));
//	node = head;
//	node2 = head;
//	node->data = data;
//
//		if (head->next == NULL) { //ó�� ������ �ֱ�
//			head->next = node;
//			node->next = head->next;
//			node->prev = head->next; //�ڱ��ڽ��� ����Ű����
//		}
//
//		else {
//			
//			while (node2->next != head->next) {
//				node2 = node2->next;
//			}
//
//			node->next = node2->next;
//			node2->next = node;
//			node->prev = node2;
//			head->next->prev = node;
//
//		}
//
//}
//
//int explore(List* head, long long data)
//{
//	List *node = (List*)malloc(sizeof(List));
//
//	node = head;
//
//	while (node->next != head->next) {
//		
//		if (node->data == data) {
//			return 0;
//		}
//		node = node->next;
//	}
//
//	return 1;
//}
//
//void main() 
//{
//	List *head = (List*)malloc(sizeof(List));
//	head->next = NULL;
//
//	FILE *fp;
//	fp = fopen("C:\\input.txt", "r"); //�б���� ���Ͽ���
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
//			count++;
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
//	printf("The total number of nodes: %d\n", count+11);
//	printf("More than 5000 values: %d\n", morenum);
//
//	free(head);
//	fclose(fp);
//}
//
