#include<stdio.h>
void modify(char* str)
{
	//�迭�� ǥ������� �������� ���� �����ͽ� ǥ������� �����Ͽ� ���� �����Ұ�
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