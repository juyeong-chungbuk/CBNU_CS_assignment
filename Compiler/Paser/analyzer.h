#ifndef PAS
#define PAS

#include <stdio.h>
#include <ctype.h>

int alnum(); //����
void digit(); //����
void op(); //������
void open_bracket(); //���� ��ȣ
void close_bracket(); //�ݴ� ��ȣ

char c;  //�ѱ��ھ� ���� ������ ����

static int i = 0;
static int lineno = 1; //���� �� �Ѿ�ٴ°�
static int count = 0;
static int count2 = 0;
static int all_count = 0;

#endif
