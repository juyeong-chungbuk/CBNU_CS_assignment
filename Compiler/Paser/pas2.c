#include "analyzer.h"


void expr();
void exprx();
void term();
void termx();
void factor();


void main()
{
	printf("�Է�\n");

	c = getchar(stdin); //���ڿ� �Է��ϱ�

	expr(); //expr�Լ� ȣ��

	if (c == '$') { //���� ��Ÿ���� '$'�� ���� ���
		printf("����!\n"); //���� �޼��� ���
	}
	else //'$'�� �ȳ��� ���
		printf("error.\n"); //���� �޼��� ���
}

void expr()
{
	printf("1 "); term(); exprx();  //1��° ��������Ʈ �� term, exprx ���ʷ� ȣ��
}

void exprx()
{
	if (c == '+') //'+'�������� ���
	{ 
		printf("2 "); //2��° ����
		c = getchar(stdin); //c�� ���������� �ѱ��

		term(); exprx(); //term, exprx ���ʷ� ȣ��
	}

	else if (c == '-')  //'-'�������� ���
	{
		printf("3 ");  //3��° ����
		c = getchar(stdin); //c�� ���������� �ѱ��

		term(); exprx(); //term, exprx ���ʷ� ȣ��
	}

	else  //�ԽǷ��� ���
	{ 
		printf("7 "); //7��° ����
	}
}

void term()
{
	printf("4 "); factor(); termx(); //4��° ���� ��� �� factor, termx ���ʷ� ȣ��
}

void termx()
{
	if (c == '*') // * �����ڰ� ���� ���
	{
		printf("5 ");  //5��° ����
		c = getchar(stdin); //c�� ���� ������ �ѱ��

		factor(); termx(); //factor, termx ���ʷ� ȣ��
	}

	else if (c == '/')  // / �����ڰ� ���� ���
	{ 
		printf("6 ");  //6��° ����
		c = getchar(stdin); //c�� ���� ������ �ѱ��

		factor(); termx(); //factor, termx ���ʷ� ȣ��
	}

	else  //�ԽǷ��� ���
	{ 
		printf("8 "); //8��° ����
	}
}

void factor()
{
	if (c == '(')  // '('�� ���� ���
	{
		printf("11 "); //11��° ����

		c = getchar(stdin); //c�� ���������� �ѱ��.

		if (c == ')') {  //'('������ �ٷ� ')'�� ������ ��� ������� �� ����
			printf("error: �߸��� �����Դϴ�. ��ȣ�� Ȯ�����ּ���.\n");
			exit();
		}

		expr(); //exprȣ��

		if (isalnum(c)) {  //��ȣ ���� ��, �ٷ� ���ڳ� ���� ������ �����޼��� ��� �� ����
			printf("error : ')' ���� ���ڸ� Ȯ�����ּ���.\n");
			exit();
		}

		if (c != ')') { //expr���� �� �ݴ� ��ȣ�� �ȳ��� ���
			printf("error: �߸��� �����Դϴ�. ��ȣ�� ������ Ȯ�����ּ���.\n"); //�����޼��� ��� �� ����
			exit();
		}
		c = getchar(stdin); //c�� ���������� �ѱ��.
	}

	else if (isdigit(c))  //���ڰ� ���� ���
	{ 
		printf("9 "); //9��° ����

		while (isdigit(c)) { //���ڰ� �ƴҶ�����
			c = getchar(stdin); //c�� ���� ������ �ѱ��
		}

		if (isalpha(c)) { //���ڴ����� ���ڰ� ������ �����޼��� ��� �� ����
			printf("error : ���ڰ� �ùٸ��� �ԷµǾ����� Ȯ�����ּ���.\n");
			exit();
		}

		if (c == '(') { //���ڳ� ���� ������ ������ ���� ��ȣ������ ���
			printf("error: '(' ���� ���ڸ� Ȯ�����ּ���.\n"); //�����޼��� ��� �� ����
			exit();
		}
	}

	else if(isalnum(c))//���ڰ� ���� ���
	{ 
		printf("10 "); //10��° ����

		while (alnum())  //���ڰ� �ƴҶ����� ���� 2���� ����� �Լ� Ȱ��
			c = getchar(stdin); //c�� ���� ������ �ѱ�

		if (c == '(') { //���ڳ� ���� ������ ������ ���� ��ȣ������ ���
			printf("error: '(' ���� ���ڸ� Ȯ�����ּ���.\n"); //�����޼��� ��� �� ����
			exit();
		}
	}

	else {
		printf("error\n"); //�����޼��� ��� �� ����
		exit();
	}
}

