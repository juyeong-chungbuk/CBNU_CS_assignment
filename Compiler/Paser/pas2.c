#include "analyzer.h"


void expr();
void exprx();
void term();
void termx();
void factor();


void main()
{
	printf("입력\n");

	c = getchar(stdin); //문자열 입력하기

	expr(); //expr함수 호출

	if (c == '$') { //끝을 나타내는 '$'가 나올 경우
		printf("성공!\n"); //성공 메세지 출력
	}
	else //'$'가 안나올 경우
		printf("error.\n"); //에러 메세지 출력
}

void expr()
{
	printf("1 "); term(); exprx();  //1번째 문법프린트 후 term, exprx 차례로 호출
}

void exprx()
{
	if (c == '+') //'+'연산자일 경우
	{ 
		printf("2 "); //2번째 문법
		c = getchar(stdin); //c를 다음값으로 넘기고

		term(); exprx(); //term, exprx 차례로 호출
	}

	else if (c == '-')  //'-'연산자일 경우
	{
		printf("3 ");  //3번째 문법
		c = getchar(stdin); //c를 다음값으로 넘기고

		term(); exprx(); //term, exprx 차례로 호출
	}

	else  //입실론일 경우
	{ 
		printf("7 "); //7번째 문법
	}
}

void term()
{
	printf("4 "); factor(); termx(); //4번째 문법 출력 후 factor, termx 차례로 호출
}

void termx()
{
	if (c == '*') // * 연산자가 나올 경우
	{
		printf("5 ");  //5번째 문법
		c = getchar(stdin); //c를 다음 값으로 넘기고

		factor(); termx(); //factor, termx 차례로 호출
	}

	else if (c == '/')  // / 연산자가 나올 경우
	{ 
		printf("6 ");  //6번째 문법
		c = getchar(stdin); //c를 다음 값으로 넘기고

		factor(); termx(); //factor, termx 차례로 호출
	}

	else  //입실론일 경우
	{ 
		printf("8 "); //8번째 문법
	}
}

void factor()
{
	if (c == '(')  // '('가 나올 경우
	{
		printf("11 "); //11번째 문법

		c = getchar(stdin); //c를 다음값으로 넘긴다.

		if (c == ')') {  //'('다음에 바로 ')'가 나오는 경우 에러출력 후 종료
			printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
			exit();
		}

		expr(); //expr호출

		if (isalnum(c)) {  //괄호 닫힌 후, 바로 문자나 숫자 나오면 에러메세지 출력 후 종료
			printf("error : ')' 다음 문자를 확인해주세요.\n");
			exit();
		}

		if (c != ')') { //expr수행 후 닫는 괄호가 안나올 경우
			printf("error: 잘못된 문법입니다. 괄호의 개수를 확인해주세요.\n"); //에러메세지 출력 후 종료
			exit();
		}
		c = getchar(stdin); //c를 다음값으로 넘긴다.
	}

	else if (isdigit(c))  //숫자가 나올 경우
	{ 
		printf("9 "); //9번째 문법

		while (isdigit(c)) { //숫자가 아닐때까지
			c = getchar(stdin); //c를 다음 값으로 넘긴다
		}

		if (isalpha(c)) { //숫자다음에 문자가 나오면 에러메세지 출력 후 종료
			printf("error : 숫자가 올바르게 입력되었는지 확인해주세요.\n");
			exit();
		}

		if (c == '(') { //숫자나 문자 다음에 연산자 없이 괄호나오는 경우
			printf("error: '(' 이전 문자를 확인해주세요.\n"); //에러메세지 출력 후 종료
			exit();
		}
	}

	else if(isalnum(c))//문자가 나올 경우
	{ 
		printf("10 "); //10번째 문법

		while (alnum())  //문자가 아닐때까지 과제 2에서 사용한 함수 활용
			c = getchar(stdin); //c를 다음 값으로 넘김

		if (c == '(') { //숫자나 문자 다음에 연산자 없이 괄호나오는 경우
			printf("error: '(' 이전 문자를 확인해주세요.\n"); //에러메세지 출력 후 종료
			exit();
		}
	}

	else {
		printf("error\n"); //에러메세지 출력 후 종료
		exit();
	}
}

