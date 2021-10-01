//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct list {
//	int data;
//	struct list *prev;
//	struct list *next;
//}List;
//
//void add_node(List* head, List* tail, long long data) {
//
//	List *node = (List*)malloc(sizeof(List));
//
//	if (head->next == tail) { //ó�� ������ �ֱ�
//		node->data = data;
//
//		head->next = node;
//		node->prev = head;
//
//		node->next = tail;
//		tail->prev = node;
//	}
//
//	else {
//		node = head;
//		List* prev = tail->prev;
//		while (node->next != tail) {
//			node = node->next;
//		};
//		node->data = data;
//
//		prev->next = node;
//		node->prev = prev;
//
//		node->next = tail;
//		tail->prev = node;
//	}
//}
//
//int explore(List* head, List* tail, long long data)
//{
//	List *node = malloc(sizeof(List));
//	node = head;
//	while (node->next != tail) {
//		node = node->next;
//		if (node->data == data) {
//			free(node);
//			return -1;
//		}
//	}
//
//	return 1;
//
//}
//
//void main()
//{
//	List *head = (List*)malloc(sizeof(List));
//	List *tail = (List*)malloc(sizeof(List));
//	head->next = tail;
//	tail->prev = head;
//
//	FILE *fp;
//	fp = fopen("D:\\testInput.txt", "r"); //�б���� ���Ͽ���
//
//	int count = 0; //����Ʈ�� �ִ� ������ ����
//	int morenum = 0; //5000�� �Ѵ� ������ ����
//	long long n[10001];
//	int ex, i = 0;
//
//	while (fscanf(fp, "%lld", &n[i]) != EOF) { printf("%lld\n", n[i]); i++; }
//
//	for (int j = 0; j < i; j++) {
//		if (explore(head, tail, n[j]) == 1) { //�ߺ����� ���� ���
//			printf("%lld\n", n[j]);
//			add_node(head, tail, n[j]);
//			count++;
//		}
//		if (n[j] > 5000) {
//			morenum++;
//		}
//	}
//	printf("The total number of nodes: %d\n", count);
//	printf("More than 5000 values: %d\n", morenum);
//
//	List* prev;
//	tail->next = NULL;
//	while (head->next != NULL) {
//		prev = head;
//		head = head->next;
//		free(prev);
//	}
//	free(tail);
//	fclose(fp);
//}