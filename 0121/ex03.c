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

	printf("sizeof(Human) : %d \n", sizeof(Human)); //����ü ũ�� ��� - �⺻ �ڷ����� ũ�Ⱑ ���� ū ���� �������� ����Ѵ�.
													//4����Ʈ �� �������� ����Ͽ� �����ش�(24 -> 28 -> 32 -> ........)

	for (int i = 0; i < 3; i++)
	{
		fr[i] = (Human*)malloc(sizeof(Human)); //void ���� malloc �Լ��� �ڷ����� ������ ��� �Ѵ�.(�ڷ��� �ȿ� ���� �ִ��� �˷���)
		printf("�̸� : "); scanf("%s", fr[i]->name);
		printf("���� : "); scanf("%d", &(fr[i]->age));
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s ���� ���̴� %d �� �Դϴ�.\n", fr[i]->name, fr[i]->age);
	}
}