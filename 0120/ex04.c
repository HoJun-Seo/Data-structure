#include<stdio.h>
void modify(char* str)
{
	//배열식 표기법으로 접근하지 말고 포인터식 표기법으로 접근하여 내용 수정할것
	int i = 0;
	for (i = 15; i > 10; i--)
	{
		*(str + i) = *(str + (i - 1));
	}
	*(str + 10) = 'l';
}
int main(void)
{
	char str[100] = "Hello, word !!";

	modify(str);
	printf("%s", str); //Hello, world !!
}