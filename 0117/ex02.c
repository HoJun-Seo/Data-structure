//ex02.c - �Լ��� ��ȯ���� �̿��ϱ�
#include<stdio.h>
int isNum(char* p)
{
	for (int i = 0; *(p + i) != '\0'; i++)
	{
		if (*(p + i) < '0' || *(p + i) > '9') return 0;
	}
	return 1;
}
int isUpper(char t)
{
	if (t >= 'a' && t <= 'z') return 0;
	else if(t >= 'A' && t <= 'Z') return 1;
}

int main(void)
{
	char* str1 = "123";
	char* str2 = "abc";
	char* str3 = "4o6";

	printf("isNum(str1) : %s\n", isNum(str1) ? "true" : "false");
	printf("isNum(str2) : %s\n", isNum(str2) ? "true" : "false");
	printf("isNum(str3) : %s\n", isNum(str3) ? "true" : "false");

	char t1 = 'a';
	char t2 = 'b';
	char t3 = 'A';

	printf("isUpper(t1) : %s\n", isUpper(t1) ? "�빮��" : "�ҹ���");
	printf("isUpper(t2) : %s\n", isUpper(t2) ? "�빮��" : "�ҹ���");
	printf("isUpper(t3) : %s\n", isUpper(t3) ? "�빮��" : "�ҹ���");

	return 0;
}