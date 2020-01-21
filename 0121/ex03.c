#include<stdio.h>
#include<stdlib.h>
typedef struct human
{
	char name[21];
	int age;
}Human;

int main()
{
	Human* fr[3];

	printf("sizeof(Human) : %d \n", sizeof(Human)); //구조체 크기 계산 - 기본 자료형의 크기가 가장 큰 것을 기준으로 계산한다.
													//4바이트 를 기준으로 계산하여 끊어준다(24 -> 28 -> 32 -> ........)

	for (int i = 0; i < 3; i++)
	{
		fr[i] = (Human*)malloc(sizeof(Human)); //void 형인 malloc 함수의 자료형을 지정해 줘야 한다.(자료형 안에 뭐가 있는지 알려줌)
		printf("이름 : "); scanf("%s", fr[i]->name);
		printf("나이 : "); scanf("%d", &(fr[i]->age));
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s 님의 나이는 %d 살 입니다.\n", fr[i]->name, fr[i]->age);
	}
}