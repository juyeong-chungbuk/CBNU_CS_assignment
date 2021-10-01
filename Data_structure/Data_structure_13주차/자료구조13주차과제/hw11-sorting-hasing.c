/*
* hw5-sorting.c
*
*  Created on: May 22, 2019
*
*  Homework 5: Sorting & Hashing
*  Department of Computer Science at Chungbuk National University
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

/* �ʿ信 ���� �Լ� �߰� ���� */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function���� ���� */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a���� �� hash table�� �����. */
int hashing(int *a, int **ht);

/* hash table���� key�� ã�� hash table�� index return */
int search(int *ht, int key);


int main()
{
	char command;
	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;

	srand(time(NULL));

	do {
		printf("[-----[���ֿ�] [2019038044]-----]\n");
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);

			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;

		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

int initialize(int** a)
{
	int *temp = NULL;

	/* array�� NULL�� ��� �޸� �Ҵ� */
	if (*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* �Ҵ�� �޸��� �ּҸ� ���� --> main���� �迭�� control �Ҽ� �ֵ��� ��*/
	}
	else
		temp = *a;

	/* �������� �迭�� ������ ���� */
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0;
}

int freeArray(int *a)
{
	if (a != NULL)
		free(a);
	return 0;
}

void printArray(int *a)
{
	if (a == NULL) {
		printf("nothing to print.\n");
		return;
	}
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("a[%02d] ", i);
	printf("\n");
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]);
	printf("\n");
}


int selectionSort(int *a) //��������: �� i������ �ִ� �迭��������� ���Ͽ� ũ������� ���߱�
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		minindex = i;
		min = a[i];
		for (j = i + 1; j < MAX_ARRAY_SIZE; j++)
		{
			if (min > a[j]) //i��° ������ ���� ���� ���� ���
			{
				min = a[j]; //�ּҰ��� �ٲ���
				minindex = j; //�ּ��ε����� j�� ��
			}
		}
		a[minindex] = a[i]; //i��° ���� �ּҰ��� ��ġ ü����
		a[i] = min; //i��° �϶� ���� ���� �ּҰ��� ����
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //a�� �ּҸ� print�Լ��� ���ڷ� �־���
	return 0;
}

int insertionSort(int *a) //��������:j���� ���ҽ��Ѱ��鼭 ū���� ������ �ڷ� �Ű��ְ� �� �̻� ū���� �ȳ��� ��� �׶��� j��°�� �ݺ��� ó���� ���ߴ� a[i]�� �־���
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for (i = 1; i < MAX_ARRAY_SIZE; i++)
	{
		t = a[i];
		j = i;
		while (a[j - 1] > t && j > 0) //i��° ������ i-1�� ���� �� ũ��, j�� 0���� Ŭ��
		{
			a[j] = a[j - 1]; //ū���� �ڷ� ������
			j--; //j�� �ϳ� ����
		}
		a[j] = t; //j��° �ε����� a[i]�� �����ؼ� ũ�� ������� ���߱�
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int bubbleSort(int *a) //��������
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		for (j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			if (a[j - 1] > a[j]) //�տ����� �� Ŭ���
			{
				t = a[j - 1]; //t�� j-1��° �ӽ÷� �� �־��ְ�
				a[j - 1] = a[j]; //j-1��°�� ������ ����
				a[j] = t; //j��°���� �ӽ÷� �־��� t����
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int shellSort(int *a) //������: h��ŭ ������ ���� ���Ͽ� ����
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	for (h = MAX_ARRAY_SIZE / 2; h > 0; h /= 2) //h�� 1/2�� �ٿ����鼭 ��
	{
		for (i = 0; i < h; i++) //h ���ݿ� �ִ� ��ҵ��� ����
		{
			for (j = i + h; j < MAX_ARRAY_SIZE; j += h)
			{
				v = a[j]; //v�� j��° ���� �־���
				k = j; //k�� �ε��� j�� �־���
				while (k > h - 1 && a[k - h] > v) //h��ŭ ������ �ִ� �ε����� ���� ���Ͽ� ���ε����� ���� �� ������� �ݺ�
				{
					a[k] = a[k - h]; //h��ŭ ������ ���� ���� �� ū a[k-h]�� ����
					k -= h; //h��ŭ ����
				}
				a[k] = v; //k��°�� h��ŭ �ڿ� �ִ� ���� �����ϰų� while���� �ȵ��� ���� �� �״�� ����
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int quickSort(int *a, int n) //������: ���ذ��� �߽����� ����, ���������� �����Ͽ� ����
{ 
	int v, t;
	int i, j;

	if (n > 1) //�迭�� ũ�Ⱑ 1���� ũ��
	{
		v = a[n - 1]; //v�� ������ ���� ����
		i = -1;
		j = n - 1; //������ �ε����� ���������� ��

		while (1) //���ѹݺ�
		{
			while (a[++i] < v); //i�� ������Ű�鼭 ������ ������ ���� �� ã��
			while (a[--j] > v); //�������ε������� �ٿ������鼭 ������ ������ ū �� ã��

			if (i >= j) break; //i�� j���� ũ�ų� �������� ����
			t = a[i];
			a[i] = a[j];
			a[j] = t; //������ �κ����հ� ���� �κ������� ü�����ϴ� �ڵ�
		}
		t = a[i]; 
		a[i] = a[n - 1];
		a[n - 1] = t; //�������� ���� j��ġ�� �ٲ�

		quickSort(a, i); //
		quickSort(a + i + 1, n - i - 1);
	}


	return 0;
}

int hashCode(int key) {
	return key % MAX_HASH_TABLE_SIZE; //
}

int hashing(int *a, int **ht) //�ؽ��Լ� ht�� �ؽ����̺� ����Ŵ
{
	int *hashtable = NULL;

	/* hash table�� NULL�� ��� �޸� �Ҵ� */
	if (*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* �Ҵ�� �޸��� �ּҸ� ���� --> main���� �迭�� control �Ҽ� �ֵ��� ��*/
	}
	else {
		hashtable = *ht;	/* hash table�� NULL�� �ƴѰ��, table ��Ȱ��, reset to -1 */
	}

	for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1; //�ؽ����̺��� ��� -1�� �ǵ�����

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1;
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key);
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		if (hashtable[hashcode] == -1)
		{
			hashtable[hashcode] = key; //�ؽ����̺� �迭�� ���� ����
		}
		else {

			index = hashcode;

			while (hashtable[index] != -1) //�ؽ����̺��� -1�̵ɶ����� �ݺ�
			{
				index = (++index) % MAX_HASH_TABLE_SIZE; //�������� ���Խ�Ű�鼭 ���غ�
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key; //-1�� �߰ߵǸ� key����
		}
	}

	return 0;
}

int search(int *ht, int key)
{
	int index = hashCode(key); //�ؽ��ڵ��Լ��� �Է��� key���� �μ��� �־��༭ ��ȯ���� ���� �ε����� key����

	if (ht[index] == key) //key���� �ش� �ε����� ���� ���� ���
		return index; //�ش� �ε��� ��ȯ

	while (ht[++index] != key) //key���� �߰��Ҷ����� �ݺ�
	{
		index = index % MAX_HASH_TABLE_SIZE; //������ ���� ���Խ��Ѱ��鼭
	}
	return index; //�� �߰��ؼ� ���ð�� �ε��� ��ȯ
}
