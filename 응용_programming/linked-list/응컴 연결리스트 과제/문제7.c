#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct MOVIE_INFORMATION MOVIE; //구조체 재정의
void get_information(); //사용자로부터 영화정보 입력받을 함수
void print_info(MOVIE **next, MOVIE **list); //영화정보 출력 함수
void insert_node(MOVIE **list, MOVIE **previous); //영화정보 추가 함수

struct MOVIE_INFORMATION
{
	char name[20]; //영화 제목 넣어줄 배열선언
	int year; //영화 개봉연도 넣어줄 변수 선언
	struct MOVIE *link; //다음 버퍼
};

MOVIE *head = NULL; //head값 초기화

void main()
{
	get_information();
}

void get_information()
{
	int x; //switch문에 사용할 변수
	MOVIE *movie = NULL; //movie포인터 초기화
	MOVIE *previous = NULL;  //previous 포인터 초기화
	MOVIE *next = NULL; //next포인터 초기화

	while (1) //무한루프
	{
		printf("------------------------------------\n"); //메뉴얼 출력
		printf("1. 영화 정보 추가\n");
		printf("2. 영화 정보 출력\n");
		printf("3. 종료\n");
		printf("------------------------------------\n");
		printf("번호를 선택하시오: ");
		scanf("%d", &x); //사용자로부터 번호 입력받음

		switch (x) { 
		case 1: //x=1일경우
			insert_node(&movie,&previous); //영화 정보 추가함수 호출
			break;
		case 2: //x=2일경우
			print_info(&next,&movie); //영화정보 출력 함수 호출
			break;
		default: //그외의 경우
			printf("종료합니다.\n"); //종료메세지 출력
			break;
		}
	}
}

void insert_node(MOVIE **list,MOVIE **previous)
{
	MOVIE movie;
	MOVIE *x; //공간 할당할 포이터 변수
	x = (MOVIE *)malloc(sizeof(MOVIE)); //공간할당해줌

	printf("영화의 제목을 입력하시오: ");
	scanf("%s", &movie.name); //사용자로부터 영화 제목입력받음
	printf("영화의 개봉 연도를 입력하시오: ");
	scanf("%d", &movie.year); //사용자로부터 영화 개봉연도 입력받음

	if (*list == NULL) {  //list가 가리키는 값이 NULL일 경우                       
		*list = x;     //  list가 가리키는 값에 x 첫값 대입              
	}
	else {           //그외의 경우                            
		(*previous)->link = x;    //previous가 가리키는 값의 다음 버퍼에 x 첫값 대입                  
	}
	x->link = NULL;     //x의 다음버퍼에 NULL값 대입                  
	*previous = x;  //previous가 가리키는 값에 x 첫값 대입
}

void print_info(MOVIE **next,MOVIE **list)
{
	MOVIE *x; //임시 포인터
	x = *list; //x포인터 변수에 list가 가리키는 값 대입

	while (x != NULL) { //x가 NULL이 아닐경우
		printf("제목 : %s\n", x->name); //영화 제목 출력
		printf("개봉 연도 : %d\n", x->year); //영화 개봉연도 출력
		*next = x->link; //next가 가리키는 값에 x의 다음버퍼 대입
		x = *next; //x에 next가 가리키는 값 대입
	}
	next = NULL; //next값 NULL로 초기화
}