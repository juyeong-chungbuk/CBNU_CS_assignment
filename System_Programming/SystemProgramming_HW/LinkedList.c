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
//	struct list *next; //list�� ����Ű�� ������
//}Head;
//
//typedef struct tail {
//	struct head *next; //head�� ����Ű�� ������
//}Tail;
//
//void main()
//{
//	FILE *fp;
//	fp = fopen("C:\\input.txt", "r"); //�б���� ���Ͽ���
//
//	//List *root = (List*)malloc(sizeof(List));
//
//	Head *root = (Head*)malloc(sizeof(Head)); //node�� ó������ ���� ��
//	List *node = (List*)malloc(sizeof(List)); //�ߺ��ȵǴ� ���� ���� ������
//	root->next = node;
//	node->next = root;
//	
//	int count = 0; //����Ʈ�� ���� ������ ����
//	int morenum = 0; //5000�� �Ѿ�� ������ ����
//
//	if (fp == NULL) { //������ ������ �ʾҴٸ�
//		fprintf(stderr, "Can't open file\n"); //���� �� �� ����.
//		exit(1); //����
//	}
//	List *allnode = (List*)malloc(sizeof(List)); //��� ���� ���� ������
//
//	while (!feof(fp)) {
//		fscanf(fp, "%d \n", &(allnode->value));
//		allnode = allnode->next;
//	} //������ ��� ���ڸ� allnode�� �ֱ�
//
//
//	while (!feof(fp)) { //�� �پ� �б� //allnode�� 1,2,3������� �Ѿ�鼭 node�� ��ó������ �ִ��� �˻�
//		
//		//fscanf(fp, "%d \n", &(node->value)); //�ϴ� ó���� node�� �ְ�
//		node->value = allnode->value;
//
//		while (allnode->next != NULL) { //������ ��� ���ڸ� �� ����������
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