#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> //malloc()�Լ��� �����ϴ� �������
#define SIZE 100 //���̰� 100

void main() //main�Լ� ����
{
	int n; //���ڿ��� ������ ������ n���� ����
	char** array = NULL; //���ڿ� �迭 array ����
	
	printf("���ڿ��� ����: "); //���ڿ��� ������ �Է��϶�� �޼��� ���
	scanf("%d", &n); //����ڷκ��� ���ڿ��� ���� �Է¹���

	if ((array = malloc(n * sizeof(char*))) != NULL){ //nalloc ���� �Ҵ��� array�迭�� ���Ұ� NULL�� �ƴҰ���� ����.

		for (int i = 0; i < n; i++) //for���� �̿��� i�� 0���� n-1���� n�� �ݺ�
			array[i] = (char*)malloc(SIZE);	 //array�迭�� 100���� ���ڸ� ������ �� �ִ� ���� �Ҵ�
	}
	printf("%d���� ���ڿ��� ������ �� �ִ� ������ �Ҵ�Ǿ����ϴ�.", n); //������ �Ҵ�Ǿ��ٴ� �޼��� ���
}

