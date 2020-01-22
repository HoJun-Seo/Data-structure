// ex04.c - 전화번호부
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phonebook {
	char name[20];
	char number[14];
}Contact;
int main() {
	Contact* pb[100] = { 0 };// 최대 100명의 연락처를 저장할 수 있는 배열
	int menu, flag = 0;
	char find[20];

	while (1) {
		printf("1. 신규 등록\n2. 검색\n3. 전체 출력\n0. 종료\n\n");
		printf("메뉴 선택 >>> ");
		scanf("%d", &menu);
		switch (menu) {
			case 1: 
				printf("\n\n");
				for (int i = 0; i < 100; i++) {
					if (pb[i] == 0) {
						pb[i] = (Contact*)malloc(sizeof(Contact));
						printf("이름 : "); scanf("%s", pb[i]->name);
						printf("번호 : "); scanf("%s", pb[i]->number);
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
					printf("[%s] : 찾을 수 없습니다.\n", find);
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
			case 0: printf("프로그램을 종료합니다."); return 0;
			default:
				printf("다시 선택해주세요\n");
		}
		system("pause");
		system("cls");
	}

}