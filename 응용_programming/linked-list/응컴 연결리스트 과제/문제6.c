//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef struct NUMBERLOG NLG; //변수를 선언해줄 구조체선언
//void get_information(); //메뉴얼을 출력할 함수
//void search(NLG **list, NLG **info); //번호를 탐색할 함수
//void put_info(NLG **temp, NLG **previous); //전화번호부에 정보를 입력할 함수
//
//struct NUMBERLOG //구조체
//{
//	char name[20]; //이름을 입력할 배열 선언
//	char phone_num[20]; //번호를 입력할 배열 선언
//	struct NUMBERLOG *next; //다음 버퍼
//};
//
//NLG *head = NULL; //헤드값 초기화
//
//void main()
//{
//	get_information();
//}
//
//void get_information()
//{
//	int x; //switch문에서 case에 대응할 변수
//	int k; //for문에 이용할 변수
//	NLG number; //구조체 number로 사용
//	NLG *info = NULL; //정보 포인터 변수
//	NLG *previous = NULL; //이전값 포인터 변수
//	NLG *list = NULL; //다음 값 포인터 변수
//	int count = 0; //for문에서 count까지 돌리기 위한 변수
//	
//	while (1) //무한루프
//	{
//		printf("연결리스트를 이용한 전화 번호부 메뉴\n"); //안내메세지 출력
//		printf("------------------------------------\n");
//		printf("1. 초기화\n");
//		printf("2. 전화 번호 추가\n");
//		printf("3. 전화 번호 탐색\n");
//		printf("4. 종료\n");
//		printf("------------------------------------\n");
//		printf("번호를 입력하세요: ");
//		scanf("%d", &x); //사용자로부터 case값 입력받기
//		switch (x){
//		case 1: //x=1일 경우
//			if (count==0) { //count=0일 경우
//				printf("이름: ");
//				scanf("%s", &number.name); //사용자로부터 이름 입력받음
//				printf("번호: ");
//				scanf("%s", &number.phone_num); //사용자로부터 번호 입력받음
//				printf("추가되었습니다.\n");
//			}
//		else { //count!=0일 경우
//				for (k= 0; k < count; k++) //for문을 통해 k를 0부터 count-1까지 반복
//				{
//					number.name[k] = NULL; //이름배열 초기화
//					number.phone_num[k] = NULL; //번호배열 초기화
//				}
//				printf("전화 번호부가 초기화되었습니다.\n"); //초기화 메세지 출력
//				printf("\n");
//				count = 0; //count값 초기화
//			}
//			break;
//
//		case 2: //x=2일 경우
//			put_info(&head,&previous); //정보를 입력할 함수 호출
//			count++; //몇개의 정보를 입력했는지 확인
//			break;
//
//		case 3: //x=3일 경우
//			search(&list,&info); //탐색함수 호출
//			break;
//
//		default : //그 외의 경우
//			printf("종료합니다.\n"); //종료메세지 출력
//			break;
//		}
//	}
//}
//
//void put_info(NLG **temp, NLG **previous)
//{
//	NLG number;
//	NLG *x; //공간할당해줄 포인터
//	x = (NLG *)malloc(sizeof(NLG)); //포인터에 공간할당
//
//	printf("이름: ");
//	scanf("%s", &number.name); //사용자로부터 이름 입력받음
//	printf("번호: ");
//	scanf("%s", &number.phone_num); //사용자로부터 번호 입력받음
//
//	if (*temp == NULL) { //temp==NULL일 경우
//		*temp = x; //temp에 x의 첫값으로 넣어줌
//	}
//	else //그 외의 경우
//	{
//		(*previous)->next = x; //이전값의 다음 버퍼에 x의 첫값을 넣어줌
//	}
//	x->next =NULL; //x의 다음 버퍼를 NULL로 초기화
//	*previous = x; //이전값에 x의 첫값 대입
//	printf("추가되었습니다.\n");
//}
//
//void search(NLG **list, NLG **info)
//{
//	char input[20]; //탐색할 이름 넣어줄 배열 선언
//	gets_s(input, sizeof(char)*20); //공간 할당
//	NLG *x; //공간할당해줄 포인터
//	x = (NLG *)malloc(sizeof(NLG)); //포인터에 공간할당
//
//	printf("찾을 사람의 이름을 입력하시오: ");
//	scanf("%s", input); //사용자로부터 탐색할 이름 입력 받음
//	x = *info; //x에 정보포인터 대입
//
//	while (x != NULL) { //x가 NULL이 아닐경우 반복
//		if (!(strcmp(x->name, input))){ //탐색할 이름과 일치할 경우
//			printf("전화 번호는 %s입니다.\n", x->phone_num); //해당 전화번호 출력
//		}
//		*list = x->next; //list가 가리키는 값이 x의 다음 버퍼를 가리키도록함
//		x = *list; //x는 list가 가리키는 값임
//	}
//	list = NULL; //list를 초기화 해줌
//}