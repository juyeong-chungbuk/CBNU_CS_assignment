#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> //malloc()�Լ��� �����ϴ� �������

void main() //main�Լ�
{
	int num_count; //������ ������ ������ ���� ����
	int sum = 0; //�Է��� ������ ���� ���� ���� ����
	int *array;  //������ ������ �迭���� ����

	printf("������ ����: "); //������ ������ �Է��϶�� �޼������
	scanf("%d", &num_count); //����ڷκ��� ������ ���� �Է¹���
	
	array = (int *)malloc(sizeof(int)*num_count); //�迭 ���� �Ҵ� malloc���

	for (int i = 0; i < num_count; i++) //for���� �̿��� ������ ������ŭ �ݺ�
	{
		printf("���� ������ �Է��ϼ���: "); //������ �Է��϶�� �޼��� ���
		scanf("%d", &array[i]); //�ÿ��ڷκ��� ���� �Է¹���

		sum += array[i]; //sum�� �Է��� ���� �� ������
	}

	free(array); //���� �Ҵ� ����
	printf("���� %d�Դϴ�.", sum); //�� �� ����ϴ� �޼���

}