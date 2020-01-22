//ex04.c - 전화번호부
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
	Contact* pb[100] = { 0 }; //최대 100명의 연락처를 저장할 수 있는 배열
	int menu;
	while (1)
	{
		printf("1. 신규등록\n2. 검색\n3. 전체출력\n4. 삭제\n0. 종료\n\n");
		printf("메뉴 선택 >>> ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("\n\n");
			for(i = 0; i < 100; i++){
				if (pb[i] == 0) { //대상이 비어있을 시
					pb[i] = (Contact*)malloc(sizeof(Contact));
					printf("\n등록할 사람의 정보를 입력하세요(최대 100명 입력 가능)\n");
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
			printf("검색할 사람의 이름을 입력하세요 : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (pb[i] != 0 && strcmp(name, pb[i]->name) == 0){
					printf("검색 결과\n이름 : %s 번호 : %s\n", pb[i]->name, pb[i]->number);
					flag = 1;
				}
			}
			if(flag == 0) 
				printf("대상이 존재하지 않습니다.\n");
			printf("\n\n");
			break;
		case 3:
			printf("\n\n");
			for (i = 0; i < 100; i++){
				if(pb[i] != 0 && sizeof(pb[i]) > 0){
					printf("이름 : %s 번호 : %s\n", pb[i]->name, pb[i]->number);
				}
			}
			printf("\n\n");
			break;
		case 4:
			printf("삭제 시킬 대상의 이름을 입력하세요 : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (pb[i] != 0 && strcmp(name, pb[i]->name) == 0)
					free(pb[i]);
			}
			break;
		case 0: printf("프로그램을 종료합니다.\n"); return 0;
		default: 
			printf("잘못된 입력입니다.\n");

		}
		system("pause");
		system("cls");
	}
}
