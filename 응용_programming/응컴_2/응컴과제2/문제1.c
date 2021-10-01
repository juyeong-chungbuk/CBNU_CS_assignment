#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> //malloc()함수를 선언하는 헤더파일

void main() //main함수
{
	int num_count; //정수의 개수를 저장할 변수 선언
	int sum = 0; //입력한 정수의 합을 더할 변수 선언
	int *array;  //정수형 포인터 배열변수 선언

	printf("정수의 개수: "); //정수의 개수를 입력하라는 메세지출력
	scanf("%d", &num_count); //사용자로부터 정수의 개수 입력받음
	
	array = (int *)malloc(sizeof(int)*num_count); //배열 동적 할당 malloc사용

	for (int i = 0; i < num_count; i++) //for문을 이용해 정수의 개수만큼 반복
	{
		printf("양의 정수를 입력하세요: "); //정수를 입력하라는 메세지 출력
		scanf("%d", &array[i]); //시용자로부터 정수 입력받음

		sum += array[i]; //sum에 입력한 정수 값 더해줌
	}

	free(array); //동적 할당 해제
	printf("합은 %d입니다.", sum); //합 값 출력하는 메세지

}