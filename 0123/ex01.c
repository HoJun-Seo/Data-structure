#include<stdio.h>
#include<stdlib.h>
typedef struct member {
	char name[20];
	int age;
	struct member* next; //���� ���� �ڷ����� �ּҸ� ������ �� �ִ� ������ ����
}Member;

void insertMember(Member** head) {
	if (*head == 0) {
		*head = (Member*)malloc(sizeof(Member));
		printf("�̸� �Է� : "); scanf("%s", (*head)->name);
		printf("���� �Է� : "); scanf("%d", &(*head)->age);
		(*head)->next = 0;
	}
	else
		insertMember(&(*head)->next);
}

void showAllMember(Member* head) {
	printf("\n\t===��ü ��� ���===\n\n");
	while (head) {
		printf("head : %p) ", head);
		printf("�̸� : %s ���� : %d ��\n\n", head->name, head->age);
		printf("head->next : %p\n", head->next);
		head = head->next;
	}
	printf("\t===��ü ��� ��===\n\n");
}

int main()
{
	Member* head = 0;
	int menu;

	while (1)
	{
		printf("1. ��� �߰�\n2. ��ü ���\n0. ����\n\n���� >>> ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1: insertMember(&head); break;
		case 2: showAllMember(head); break;
		case 0: return;
		}
		system("pause");
		system("cls");
	}
}