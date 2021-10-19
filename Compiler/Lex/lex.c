#include <stdio.h>
#include <ctype.h>
void expr(char a);
void exprx(char a);
void term(char a);
void termx(char a);
void factor(char a);

void main()
{
	char c;
	int i = 0;
	int lineno = 1; //다음 줄 넘어갔다는거
	int count = 0;
	int count2 = 0;
	int all_count = 0;

	printf("입력\n");

	while (1) {

		c = getchar(stdin);

		if (c == ' ' || c == '\t') { //공백 혹은 탭
			/*그냥 무시*/
		}

		else if (c == '\n') //개행문자
		{
			lineno++; //줄 바뀜
		}
		           
		else if (c == '(') { //괄호가 나올 경우
			printf("%c", c);
			count++;

			c = getchar(stdin);
			if (c == ')') {  //()안에 아무것도 없는 경우
				printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
				break;
			}
			ungetc(c, stdin);
		}
		          
		else if (c == ')') {
			printf("%c", c);
			count2++;
		}

		else if (isdigit(c)) //숫자일 경우
		{
			c = getchar(stdin);
			if (!isdigit(c)&& (c != '+' && c != '-' && c != '/' && c != '*'&& c != '$')) { //숫자다음에 숫자가 아닌 값이 나오는 경우(연산자제외)
				printf("error: 잘못된 문법입니다.\n");
				break;
			}

			if (c == '(') { //숫자다음에 연산자 없이 괄호나오는 경우
				printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
				break;
			}

			while (isdigit(c)) {
				c = getchar(stdin);
			}

			if (isalpha(c)) { //숫자가 여러개 나오고 문자가 나오면 오류
				printf("error: 잘못된 문법입니다.\n");
				break;
			}

			ungetc(c, stdin);
			all_count++;
			printf("NUM ");

		}

		else if (c == '+' || c == '-' || c == '/' || c == '*' || c == '$') //연산자일 경우, $일 경우
		{
			if (all_count == 0) { //연산자가 입력 맨 처음에 나오는 경우
				printf("error: 잘못된 연산자 문법입니다.\n");
				break;
			}
			
			if (c == '$') {
				printf("%c\n", c);
				if (count != count2) { //괄호의 개수가 안맞을 경우
					printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
					break;
				}
				all_count = 0;
				printf("%d", strlen(stdin));
				expr(c);
				continue;
			}

			printf("%c ", c);

			c = getchar(stdin);
			if ((c == '+' || c == '-' || c == '/' || c == '*')) { //연산자가 두번 연속 나오면 오류
				printf("error: 잘못된 문법입니다.\n");
				break;
			}
			ungetc(c, stdin);
			all_count++;
		}

		else if(c=='>'||c=='<'||c=='=') //ralation일 경우
		{
			if (c == '=') {
				all_count++;
				continue;
			}
			all_count++;
			printf("Relation ");
		}

		else if (!isdigit(c)) { //ID일 경우

			c = getchar(stdin);

			if (c == '(') { //문자 다음에 바로 괄호가 나오는 경우
				printf("error: 잘못된 문법입니다. 괄호를 확인해주세요.\n");
				break;
			}

			while (isalnum(c)) {
				c = getchar(stdin);
			}
			ungetc(c, stdin);
			all_count++;
			printf("ID ");
		}

		else { //그 외의 다른 기호가 들어갈 경우
			printf("error: 잘못된 문법입니다.\n");
			break;
		}
	}
}

void expr(char a)
{

	term(a); exprx(a);
}

void exprx(char a)
{
	if (a == '+') {
		term(a); exprx(a);
	}
	else if (a == '=') {
		term(a); exprx(a);
	}
	else;
}

void term(char a)
{

}

void termx(char a)
{

}

void factor(char a)
{

}