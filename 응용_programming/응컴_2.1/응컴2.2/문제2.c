#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> //malloc()함수를 선언하는 헤더파일
#define SIZE 100 //길이가 100

void main() //main함수 선언
{
	int n; //문자열의 개수를 저장할 n변수 선언
	char** array = NULL; //문자열 배열 array 선언
	
	printf("문자열의 개수: "); //문자열의 개수를 입력하라는 메세지 출력
	scanf("%d", &n); //사용자로부터 문자열의 개수 입력받음

	if ((array = malloc(n * sizeof(char*))) != NULL){ //nalloc 동적 할당한 array배열의 원소가 NULL이 아닐경우의 조건.

		for (int i = 0; i < n; i++) //for문을 이용해 i를 0부터 n-1까지 n번 반복
			array[i] = (char*)malloc(SIZE);	 //array배열에 100개의 문자를 저장할 수 있는 공간 할당
	}
	printf("%d개의 문자열을 저장할 수 있는 공간이 할당되었습니다.", n); //공간이 할당되었다는 메세지 출력
}

