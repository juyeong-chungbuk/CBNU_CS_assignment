#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct MOVIE_INFORMATION MOVIE; //����ü ������
void get_information(); //����ڷκ��� ��ȭ���� �Է¹��� �Լ�
void print_info(MOVIE **next, MOVIE **list); //��ȭ���� ��� �Լ�
void insert_node(MOVIE **list, MOVIE **previous); //��ȭ���� �߰� �Լ�

struct MOVIE_INFORMATION
{
	char name[20]; //��ȭ ���� �־��� �迭����
	int year; //��ȭ �������� �־��� ���� ����
	struct MOVIE *link; //���� ����
};

MOVIE *head = NULL; //head�� �ʱ�ȭ

void main()
{
	get_information();
}

void get_information()
{
	int x; //switch���� ����� ����
	MOVIE *movie = NULL; //movie������ �ʱ�ȭ
	MOVIE *previous = NULL;  //previous ������ �ʱ�ȭ
	MOVIE *next = NULL; //next������ �ʱ�ȭ

	while (1) //���ѷ���
	{
		printf("------------------------------------\n"); //�޴��� ���
		printf("1. ��ȭ ���� �߰�\n");
		printf("2. ��ȭ ���� ���\n");
		printf("3. ����\n");
		printf("------------------------------------\n");
		printf("��ȣ�� �����Ͻÿ�: ");
		scanf("%d", &x); //����ڷκ��� ��ȣ �Է¹���

		switch (x) { 
		case 1: //x=1�ϰ��
			insert_node(&movie,&previous); //��ȭ ���� �߰��Լ� ȣ��
			break;
		case 2: //x=2�ϰ��
			print_info(&next,&movie); //��ȭ���� ��� �Լ� ȣ��
			break;
		default: //�׿��� ���
			printf("�����մϴ�.\n"); //����޼��� ���
			break;
		}
	}
}

void insert_node(MOVIE **list,MOVIE **previous)
{
	MOVIE movie;
	MOVIE *x; //���� �Ҵ��� ������ ����
	x = (MOVIE *)malloc(sizeof(MOVIE)); //�����Ҵ�����

	printf("��ȭ�� ������ �Է��Ͻÿ�: ");
	scanf("%s", &movie.name); //����ڷκ��� ��ȭ �����Է¹���
	printf("��ȭ�� ���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &movie.year); //����ڷκ��� ��ȭ �������� �Է¹���

	if (*list == NULL) {  //list�� ����Ű�� ���� NULL�� ���                       
		*list = x;     //  list�� ����Ű�� ���� x ù�� ����              
	}
	else {           //�׿��� ���                            
		(*previous)->link = x;    //previous�� ����Ű�� ���� ���� ���ۿ� x ù�� ����                  
	}
	x->link = NULL;     //x�� �������ۿ� NULL�� ����                  
	*previous = x;  //previous�� ����Ű�� ���� x ù�� ����
}

void print_info(MOVIE **next,MOVIE **list)
{
	MOVIE *x; //�ӽ� ������
	x = *list; //x������ ������ list�� ����Ű�� �� ����

	while (x != NULL) { //x�� NULL�� �ƴҰ��
		printf("���� : %s\n", x->name); //��ȭ ���� ���
		printf("���� ���� : %d\n", x->year); //��ȭ �������� ���
		*next = x->link; //next�� ����Ű�� ���� x�� �������� ����
		x = *next; //x�� next�� ����Ű�� �� ����
	}
	next = NULL; //next�� NULL�� �ʱ�ȭ
}