//ex04.c - ��ȭ��ȣ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phonebook
{
	char name[20];
	char number[14];
}Contact;

int main(void)
{
	int i = 0, flag = 0;
	char name[20];
	Contact* pb[100] = { 0 }; //�ִ� 100���� ����ó�� ������ �� �ִ� �迭
	int menu;
	while (1)
	{
		printf("1. �űԵ��\n2. �˻�\n3. ��ü���\n4. ����\n0. ����\n\n");
		printf("�޴� ���� >>> ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("\n\n");
			for(i = 0; i < 100; i++){
				if (pb[i] == 0) { //����� ������� ��
					pb[i] = (Contact*)malloc(sizeof(Contact));
					printf("\n����� ����� ������ �Է��ϼ���(�ִ� 100�� �Է� ����)\n");
					printf("�̸� : "); scanf("%s", pb[i]->name);
					printf("��ȣ : "); scanf("%s", pb[i]->number);
					break;
				}
			}
			printf("\n\n");
			break;
		case 2:
			flag = 0;
			printf("\n\n");
			printf("�˻��� ����� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (pb[i] != 0 && strcmp(name, pb[i]->name) == 0){
					printf("�˻� ���\n�̸� : %s ��ȣ : %s\n", pb[i]->name, pb[i]->number);
					flag = 1;
				}
			}
			if(flag == 0) 
				printf("����� �������� �ʽ��ϴ�.\n");
			printf("\n\n");
			break;
		case 3:
			printf("\n\n");
			for (i = 0; i < 100; i++){
				if(pb[i] != 0 && sizeof(pb[i]) > 0){
					printf("�̸� : %s ��ȣ : %s\n", pb[i]->name, pb[i]->number);
				}
			}
			printf("\n\n");
			break;
		case 4:
			printf("���� ��ų ����� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (pb[i] != 0 && strcmp(name, pb[i]->name) == 0)
					free(pb[i]);
			}
			break;
		case 0: printf("���α׷��� �����մϴ�.\n"); return 0;
		default: 
			printf("�߸��� �Է��Դϴ�.\n");

		}
		system("pause");
		system("cls");
	}
}
