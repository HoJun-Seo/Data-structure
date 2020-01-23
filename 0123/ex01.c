#include<stdio.h>
#include<stdlib.h>
typedef struct member {
	char name[20];
	int age;
	struct member* next; //나와 같은 자료형의 주소를 저장할 수 있는 포인터 변수
}Member;

void insertMember(Member** head) {
	if (*head == 0) {
		*head = (Member*)malloc(sizeof(Member));
		printf("이름 입력 : "); scanf("%s", (*head)->name);
		printf("나이 입력 : "); scanf("%d", &(*head)->age);
		(*head)->next = 0;
	}
	else
		insertMember(&(*head)->next);
}

void showAllMember(Member* head) {
	printf("\n\t===전체 목록 출력===\n\n");
	while (head) {
		printf("head : %p) ", head);
		printf("이름 : %s 나이 : %d 살\n\n", head->name, head->age);
		printf("head->next : %p\n", head->next);
		head = head->next;
	}
	printf("\t===전체 출력 끝===\n\n");
}

int main()
{
	Member* head = 0;
	int menu;

	while (1)
	{
		printf("1. 멤버 추가\n2. 전체 출력\n0. 종료\n\n선택 >>> ");
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