#include<stdio.h>

void InputName(char* name)
{
	printf("�̸� �Է� : ");
	scanf("%s", name);
}

void InputAge(int* age)
{
	printf("���� �Է� : ");
	scanf("%d", age); //������ �ּҷ� �Ѱ�� ������ & ��ȣ�� ����� �ʿ䰡 ��������.
}

int main(void)
{
	char name[20];
	int age;

	InputName(name);
	InputAge(&age);

	printf("%s ���� ���̴� %d ���Դϴ�. \n", name, age);
}