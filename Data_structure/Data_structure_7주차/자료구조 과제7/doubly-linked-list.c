/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */

#include<stdio.h>
#include<stdlib.h>
 /* �ʿ��� ������� �߰� if necessary */


typedef struct Node {
	int data;
	struct Node* llink;
	struct Node* rlink;
} listNode;


typedef struct Head {
	struct Node* first;
}headNode;

/* �Լ� ����Ʈ */

/* note: initialize�� ���������͸� �Ű������� ����
		 singly-linked-list�� initialize�� �������� ���� �Ұ� */
int initialize(headNode** h);

/* note: freeList�� �̱������͸� �Ű������� ����
		- initialize�� �� �ٸ��� ���� �Ұ�
		 - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode = NULL;

	do {
		printf("[----[2019038044] [���ֿ�]----]\n");
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) { 
	if (*h != NULL) //��尡 ������� �ʴٸ�
		freeList(*h); //��������

	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;
}

int freeList(headNode* h) { //��� ��带 ����
	listNode* node = h;

	listNode* prev = NULL;
	while (node != NULL) {
		prev = node; //���� ��带 ���������� ���� ��
		node = node->rlink; //��带 �������� �ѱ�
		free(prev); //������忴�� ���� ����
	}
	free(h); //��嵵 ����
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while (p != NULL) {
		printf("[ [%d]=%d ] ", i, p->data);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}


/**
 * list�� �������� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) { 

	listNode* node = h->first;
	listNode* temp = (listNode*)malloc(sizeof(*temp));
	temp->data = key;
	temp->rlink = NULL;
	temp->llink = NULL;

	if (h->first == NULL) { //����Ʈ�� ����� ���
		h->first = temp; //temp�� ���� ����
		node->rlink = NULL; //����� ������ NULL��
		node->llink = NULL; //����� ������ NULL��
		return 0;
	}

		while (node->rlink != NULL) { //����� ������ NULL�� �Ǳ� ������ �ݺ�
			node = node->rlink;
		}
		node->rlink = temp; //node�� ������ ���ο� ����
		temp->llink = node; //���ο� �����  ������ node��
		return 0;
}


/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(*node));
	listNode* temp = (listNode*)malloc(sizeof(*temp));
	node = h->first;
	temp->data = key;

	temp->rlink = node; //����� ������ ����node�� ������ ���� ����
	node->llink = temp; //����node�� ������ temp�� ����
	h->first = temp; //temp�� ���� ����

	return 0;
}

/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) { //��
	
	listNode* temp = (listNode*)malloc(sizeof(listNode));
	temp->data = key;
	temp->rlink = NULL;
	temp->llink = NULL;
	

	if (h->first == NULL) { //����Ʈ�� ����� ���
		h->first = temp; //temp�� ���� ����
		temp->rlink = NULL; //temp�� ������ ������ NULL�� �ʱ�ȭ
		temp->llink = NULL; 
		return 0;
	}
	listNode* node = h->first;

		while (node != NULL) { //node�� NULL�� �ɶ����� �ݺ�
				if (node->data >= key) { //node���� �տ� �������
					if (node == h->first) { //node�� ����� ���
						h->first = temp; //temp�� ���� ����
						temp->rlink = node; //temp�� ������ ����node�� ����Ű�� ������ ����
						node->llink = temp; //node�� ����Ű�� ���� ������ temp�� ����
					}
					else { //node�� �߰�����̰ų� ������ ����� ���
						temp->llink = node->llink; //����node�� ����Ű�� ���� ������ temp�� �������� �������
						temp->rlink = node; //temp�� ������ ����node�� ����Ű�� ������ ����
						node->llink->rlink = temp; //����node��尡 ����Ű�� ������ ����Ű�� ������ temp�� ����
						node->llink = temp; //node�� ������ temp�� ����
					} //ȭ��ǥ 4�� �ϼ�
					return 0;
				}
				
			node = node->rlink; //��带 �������� �Ѱ���
		}
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
	listNode* node = h->first;
	if (h->first == NULL) { //����Ʈ�� ����� ���
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return 0;
	}

	if (node->rlink == NULL) { //node�� ����� ���
		h->first = NULL; //��带 NULL�� �������
		free(node); //��� ����
		return 0;
	}
		while (node->rlink != NULL) { //node�� ��������带 ����ų������ �ݺ�
			node = node->rlink;
		}
		node->llink->rlink = NULL; //node�� ����Ű�� ȭ��ǥ ����
		node->llink = NULL; //node�� ����Ű�� ������ ���ϴ� ȭ��ǥ ����
		free(node); //������ ��� ����
	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) { 
	listNode* node = h->first;
	
	if (h->first == NULL) { //����Ʈ�� ����� ���
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return 0;
	}
		
	h->first = node->rlink; //�ι�° ��带 ���� ����
	node->rlink->llink = NULL; //�ι�° ��尡 ����Ű�� ������ NULL�� �����
	node->rlink = NULL; //����� ������ NULL�� �����
	free(node); //��� ����
	return 0;
}

/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) { 
	listNode* node = h->first;
	listNode* temp = (listNode*)malloc(sizeof(*temp));
	temp->data = key;

	if (h->first == NULL) { //����Ʈ�� ����� ���
		printf("����Ʈ�� ����ֽ��ϴ�.\n");
		return 0;
	}

		while (node->data != key) { //node�� ���� key�� ������ ������ �ݺ�
			node = node->rlink;
		} //�������� while�� ������

		if (node->llink == NULL) { //ù��° ����� ���
			node->rlink->llink = NULL; //ù��° ��带 ����Ű�� ȭ��ǥ ����
			h->first = node->rlink; //�ι�°��带 ���� ����
			node->rlink = NULL; //ù��° ��尡 ����Ű�� ȭ��ǥ ����
			free(node); //ù��° ��� ����
		}
		else if(node->rlink==NULL) { //������ ����� ���
			node->llink->rlink = NULL; //���ڸ� ��带 ����Ű�� ȭ��ǥ ����
			node->llink = NULL; //������ ��尡����Ű�� ȭ��ǥ ����
			free(node); //������ ��� ����
		}

		else { //�߰������ ���
			node->llink->rlink = node->rlink; //node�� ������ ����Ű�� ȭ��ǥ�� ���� node�� �������� ���ϰ�
			node->rlink->llink = node->llink; //node�� ������ ����Ű�� ȭ��ǥ�� ���� node�� �������� ���ϰ�
			free(node); //�ش� �߰���� ����
		}
	return 1;
}

/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
	listNode* head = h->first; //��带 ����Ű�� ������
	listNode* middle = NULL; //������ ����� �� ������
	listNode* tail = NULL; //�ӽ����� ������

	while (head != NULL) {
		tail = middle; //middle���� �ӽ�����
		middle = head; //middle�� ��带 ����
		head = head->rlink; //��带 �������� �Ѱ���
		middle->rlink = tail; //middle�� �ӽ������� tail�� ����
	}
	h->first = middle; //��������带 ���� �ű�
	return 0;
}