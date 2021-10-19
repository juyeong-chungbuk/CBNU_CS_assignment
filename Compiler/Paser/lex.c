#include "analyzer.h"

int alnum() //문자
{
	while (isalnum(c)) {
		c = getchar(stdin);
	}
	return 0;
}

void digit() //숫자
{
	c = getchar(stdin);
	if (!isdigit(c) && (c != '+' && c != '-' && c != '/' && c != '*'&& c != '$')) { //숫자다음에 숫자가 아닌 값이 나오는 경우(연산자제외)
		printf("error: 잘못된 문법입니다.\n");
		exit();
	}

	if (c == '(') { //숫자다음에 연산자 없이 괄호나오는 경우
		printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
		exit();
	}

	while (isdigit(c)) {
		c = getchar(stdin);
	}

	if (isalpha(c)) { //숫자가 여러개 나오고 문자가 나오면 오류
		printf("error: 잘못된 문법입니다.\n");
		exit();
	}

	ungetc(c, stdin);
	all_count++;
	printf("NUM ");
}

void op() //연산자
{
	if (all_count == 0) { //연산자가 입력 맨 처음에 나오는 경우
		printf("error: 잘못된 연산자 문법입니다.\n");
		exit();
	}

	if (c == '$') {
		printf("%c\n", c);
		if (count != count2) { //괄호의 개수가 안맞을 경우
			printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
			exit();
		}
		all_count = 0;
	}

	printf("%c ", c);

	c = getchar(stdin);
	if ((c == '+' || c == '-' || c == '/' || c == '*')) { //연산자가 두번 연속 나오면 오류
		printf("error: 잘못된 문법입니다.\n");
		exit();
	}
	ungetc(c, stdin);
	all_count++;
}

void open_bracket() //여는 괄호
{
	printf("%c", c);
	count++;

	c = getchar(stdin);
	if (c == ')') {  //()안에 아무것도 없는 경우
		printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
		exit();
	}
	ungetc(c, stdin);
}

void close_bracket() //닫는 괄호
{
	printf("%c", c);
	count2++;
}