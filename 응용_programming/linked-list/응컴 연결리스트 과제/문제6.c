//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct NUMBERLOG NLG; //������ �������� ����ü����
//void get_information(); //�޴����� ����� �Լ�
//void search(NLG **list, NLG **info); //��ȣ�� Ž���� �Լ�
//void put_info(NLG **temp, NLG **previous); //��ȭ��ȣ�ο� ������ �Է��� �Լ�
//
//struct NUMBERLOG //����ü
//{
//	char name[20]; //�̸��� �Է��� �迭 ����
//	char phone_num[20]; //��ȣ�� �Է��� �迭 ����
//	struct NUMBERLOG *next; //���� ����
//};
//
//NLG *head = NULL; //��尪 �ʱ�ȭ
//
//void main()
//{
//	get_information();
//}
//
//void get_information()
//{
//	int x; //switch������ case�� ������ ����
//	int k; //for���� �̿��� ����
//	NLG number; //����ü number�� ���
//	NLG *info = NULL; //���� ������ ����
//	NLG *previous = NULL; //������ ������ ����
//	NLG *list = NULL; //���� �� ������ ����
//	int count = 0; //for������ count���� ������ ���� ����
//	
//	while (1) //���ѷ���
//	{
//		printf("���Ḯ��Ʈ�� �̿��� ��ȭ ��ȣ�� �޴�\n"); //�ȳ��޼��� ���
//		printf("------------------------------------\n");
//		printf("1. �ʱ�ȭ\n");
//		printf("2. ��ȭ ��ȣ �߰�\n");
//		printf("3. ��ȭ ��ȣ Ž��\n");
//		printf("4. ����\n");
//		printf("------------------------------------\n");
//		printf("��ȣ�� �Է��ϼ���: ");
//		scanf("%d", &x); //����ڷκ��� case�� �Է¹ޱ�
//		switch (x){
//		case 1: //x=1�� ���
//			if (count==0) { //count=0�� ���
//				printf("�̸�: ");
//				scanf("%s", &number.name); //����ڷκ��� �̸� �Է¹���
//				printf("��ȣ: ");
//				scanf("%s", &number.phone_num); //����ڷκ��� ��ȣ �Է¹���
//				printf("�߰��Ǿ����ϴ�.\n");
//			}
//		else { //count!=0�� ���
//				for (k= 0; k < count; k++) //for���� ���� k�� 0���� count-1���� �ݺ�
//				{
//					number.name[k] = NULL; //�̸��迭 �ʱ�ȭ
//					number.phone_num[k] = NULL; //��ȣ�迭 �ʱ�ȭ
//				}
//				printf("��ȭ ��ȣ�ΰ� �ʱ�ȭ�Ǿ����ϴ�.\n"); //�ʱ�ȭ �޼��� ���
//				printf("\n");
//				count = 0; //count�� �ʱ�ȭ
//			}
//			break;
//
//		case 2: //x=2�� ���
//			put_info(&head,&previous); //������ �Է��� �Լ� ȣ��
//			count++; //��� ������ �Է��ߴ��� Ȯ��
//			break;
//
//		case 3: //x=3�� ���
//			search(&list,&info); //Ž���Լ� ȣ��
//			break;
//
//		default : //�� ���� ���
//			printf("�����մϴ�.\n"); //����޼��� ���
//			break;
//		}
//	}
//}
//
//void put_info(NLG **temp, NLG **previous)
//{
//	NLG number;
//	NLG *x; //�����Ҵ����� ������
//	x = (NLG *)malloc(sizeof(NLG)); //�����Ϳ� �����Ҵ�
//
//	printf("�̸�: ");
//	scanf("%s", &number.name); //����ڷκ��� �̸� �Է¹���
//	printf("��ȣ: ");
//	scanf("%s", &number.phone_num); //����ڷκ��� ��ȣ �Է¹���
//
//	if (*temp == NULL) { //temp==NULL�� ���
//		*temp = x; //temp�� x�� ù������ �־���
//	}
//	else //�� ���� ���
//	{
//		(*previous)->next = x; //�������� ���� ���ۿ� x�� ù���� �־���
//	}
//	x->next =NULL; //x�� ���� ���۸� NULL�� �ʱ�ȭ
//	*previous = x; //�������� x�� ù�� ����
//	printf("�߰��Ǿ����ϴ�.\n");
//}
//
//void search(NLG **list, NLG **info)
//{
//	char input[20]; //Ž���� �̸� �־��� �迭 ����
//	gets_s(input, sizeof(char)*20); //���� �Ҵ�
//	NLG *x; //�����Ҵ����� ������
//	x = (NLG *)malloc(sizeof(NLG)); //�����Ϳ� �����Ҵ�
//
//	printf("ã�� ����� �̸��� �Է��Ͻÿ�: ");
//	scanf("%s", input); //����ڷκ��� Ž���� �̸� �Է� ����
//	x = *info; //x�� ���������� ����
//
//	while (x != NULL) { //x�� NULL�� �ƴҰ�� �ݺ�
//		if (!(strcmp(x->name, input))){ //Ž���� �̸��� ��ġ�� ���
//			printf("��ȭ ��ȣ�� %s�Դϴ�.\n", x->phone_num); //�ش� ��ȭ��ȣ ���
//		}
//		*list = x->next; //list�� ����Ű�� ���� x�� ���� ���۸� ����Ű������
//		x = *list; //x�� list�� ����Ű�� ����
//	}
//	list = NULL; //list�� �ʱ�ȭ ����
//}