//ex04.c - ��ȭ��ȣ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phonebook
{
	char name[20];
	char number[14];
}Contact;

int main()
{
	int i = 0, count = 0;
	char name[20];
	char c;
	Contact* pb[100] = { 0 }; //�ִ� 100���� ����ó�� ������ �� �ִ� �迭
	int menu;
	while (1)
	{
		printf("1. �űԵ��\n2. �˻�\n3. ��ü���\n4.����\n0. ����\n\n");
		printf("�޴� ���� >>> ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:

			
			if (pb[i] == 0) { //����� ������� ��
				pb[count] = (Contact*)malloc(sizeof(Contact));
				printf("\n����� ����� ������ �Է��ϼ���(�ִ� 100�� �Է� ����)\n");
				printf("�̸� : "); scanf("%s", pb[count]->name);
				printf("��ȣ : "); scanf("%s", pb[count]->number);
				count++;
				break;
			}
			break;
		case 2:
			printf("�˻��� ����� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			for (i = 0; i < count; i++)
			{
				if (strcmp(name, pb[i]->name) == 0)
					printf("�˻� ���\n�̸� : %s ��ȣ : %s\n", pb[i]->name, pb[i]->number);
				else printf("����� �������� �ʽ��ϴ�.\n");
			}
			break;
		case 3:
			for (i = 0; i < count; i++)
				if (pb[i]->name == NULL && pb[i]->number == NULL)
					printf("����� �������� �ʽ��ϴ�.\n");
				printf("�̸� : %s ��ȣ : %s\n", pb[i]->name, pb[i]->number);
			break;
		case 4:
			printf("���� ��ų ����� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			for (i = 0; i < count; i++)
			{
				if (strcmp(name, pb[i]->name) == 0)
					free(pb[i]);
			}
			break;
		case 0: printf("���α׷��� �����մϴ�.\n"); return;
		default: 
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
		system("pause");
		system("cls");
	}
}