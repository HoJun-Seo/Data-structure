#include<stdio.h>

void InputName(char* name)
{
	printf("이름 입력 : ");
	scanf("%s", name);
}

void InputAge(int* age)
{
	printf("나이 입력 : ");
	scanf("%d", age); //변수를 주소로 넘겼기 때문에 & 기호를 사용할 필요가 없어진다.
}

int main(void)
{
	char name[20];
	int age;

	InputName(name);
	InputAge(&age);

	printf("%s 님의 나이는 %d 살입니다. \n", name, age);
}