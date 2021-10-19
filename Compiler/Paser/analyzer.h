#ifndef PAS
#define PAS

#include <stdio.h>
#include <ctype.h>

int alnum(); //문자
void digit(); //숫자
void op(); //연산자
void open_bracket(); //여는 괄호
void close_bracket(); //닫는 괄호

char c;  //한글자씩 문자 대입할 변수

static int i = 0;
static int lineno = 1; //다음 줄 넘어갔다는거
static int count = 0;
static int count2 = 0;
static int all_count = 0;

#endif
