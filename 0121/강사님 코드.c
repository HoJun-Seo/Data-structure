// ex04.c - ��ȭ��ȣ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phonebook {
	char name[20];
	char number[14];
}Contact;
int main() {
	Contact* pb[100] = { 0 };// �ִ� 100���� ����ó�� ������ �� �ִ� �迭
	int menu, flag = 0;
	char find[20];

	while (1) {
		printf("1. �ű� ���\n2. �˻�\n3. ��ü ���\n0. ����\n\n");
		printf("�޴� ���� >>> ");
		scanf("%d", &menu);
		switch (menu) {
			case 1: 
				printf("\n\n");
				for (int i = 0; i < 100; i++) {
					if (pb[i] == 0) {
						pb[i] = (Contact*)malloc(sizeof(Contact));
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

				printf(" : ");
				scanf("%s", find);

				for (int i = 0; i < 100; i++) {
					if (pb[i] != 0 && strcmp(pb[i]->name, find) == 0) {
						printf("%d) %s : %s\n", i + 1, pb[i]->name, pb[i]->number);
						flag = 1;
					}
				}
				if (flag == 0)
					printf("[%s] : ã�� �� �����ϴ�.\n", find);
				printf("\n\n");
				break;
			case 3: 
				printf("\n\n");
				for (int i = 0; i < 100; i++) {
					if (pb[i] != 0) {
						printf("%d) %s : %s\n", i + 1, pb[i]->name, pb[i]->number);
					}
				}
				printf("\n\n");
				break;
			case 0: printf("���α׷��� �����մϴ�."); return 0;
			default:
				printf("�ٽ� �������ּ���\n");
		}
		system("pause");
		system("cls");
	}

}