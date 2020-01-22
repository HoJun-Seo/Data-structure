#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	char name[20];
	int math, kor, eng, sum, rank;
	double avg;
}STUDENT;
void score(STUDENT* arr) {
	printf("이름 : %s 국어 : %d 영어 : %d 수학 : %d \n", arr->name, arr->kor, arr->eng, arr->math);
	printf("합계 : %d 평균 : %lf\n", arr->sum, arr->avg);
}
void ListAll(STUDENT** arr)
{
	printf("\n\n");
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] != 0 && sizeof(arr[i]) > 0) {
			printf("이름 : %s\n", arr[i]->name);
			printf("국어 : %d 영어 : %d 수학 : %d \n", arr[i]->kor, arr[i]->eng, arr[i]->math);
			printf("합계 : %d 평균 : %lf\n", arr[i]->sum, arr[i]->avg);
			printf("등수 : %d\n", arr[i]->rank);
		}
	}
	printf("\n\n");
}
void orderBySumDesc(STUDENT** arr) {
	// 총점 기준 내림차순 정렬
	for (int i = 0; i < 100 && arr[i] != 0; i++) {
		for (int j = i; j < 100 && arr[j] != 0; j++) {
			if (arr[i]->sum < arr[j]->sum) {
				STUDENT* tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void Rank(STUDENT** arr) {
	int i = 0;
	arr[i]->rank = 0;
	for (i = 0; i < 100 && arr[i] != 0; i++)
	{
		arr[i]->rank = 1;
		for (int j = 0; j < 100 && arr[j] != 0; j++) {
			if (arr[i]->sum < arr[i]->sum) { //나 보다 더 높은 점수가 있으면
				arr[i]->rank += 1; //내 등수의 숫자가 증가(순위가 떨어짐)
			}
		}
	}
}



int main(void)
{
	int i = 0, j = 0;
	int menu, flag = 0;
	int upt;
	char name[20];
	STUDENT* arr[100] = { 0 };
	while (1) {
		printf("학생 정보 등록 및 성적 관리 프로그램입니다.\n");
		printf("1. 신규 등록\n2. 검색\n3. 정보 수정\n4. 정보 삭제\n5. 점수 내림차순 정렬\n6. 등수 오름차순 정렬\n0. 종료\n");
		printf("메뉴 선택 >>> "); scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("\n\n");
			for (i = 0; i < 100; i++)
			{
				if (arr[i] == 0) {
					arr[i] = (STUDENT*)malloc(sizeof(STUDENT));
					printf("등록할 사람의 정보를 입력하세요(최대 100명 입력 가능)\n");
					printf("이름 : "); scanf("%s", arr[i]->name);
					printf("국어 : "); scanf("%d", &arr[i]->kor);
					printf("영어 : "); scanf("%d", &arr[i]->eng);
					printf("수학 : "); scanf("%d", &arr[i]->math);
					arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
					arr[i]->avg = arr[i]->sum / 3;
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
				if (arr[i] != 0 && strcmp(name, arr[i]->name) == 0) {
					flag = 1;
					printf("검색결과\n");
					score(arr[i]);
				}
			}
			if (flag == 0)
				printf("대상이 존재하지 않습니다.\n");
			printf("\n\n");
			break;
		case 3:
			flag = 0;
			printf("\n\n");
			printf("정보를 수정할 사람의 이름을 입력하세요 : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (arr[i] != 0 && strcmp(name, arr[i]->name) == 0) {
					flag = 1;
					printf("1. 국어\n2. 영어\n3. 수학\n");
					printf("수정할 과목을 선택하세요 : ");
					scanf("%d", &upt);
					switch (upt) {
					case 1 :
						printf("국어 점수 수정 : ");
						scanf("%d", &arr[i]->kor);
						arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
						arr[i]->avg = arr[i]->sum / 3;
						break;
					case 2:
						printf("영어 점수 수정 : ");
						scanf("%d", &arr[i]->eng);
						arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
						arr[i]->avg = arr[i]->sum / 3;
						break;
					case 3:
						printf("수학 점수 수정 : ");
						scanf("%d", &arr[i]->math);
						arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
						arr[i]->avg = arr[i]->sum / 3;
						break;
					}
				}
			}
			break;
		case 4:
			printf("삭제 시킬 대상의 이름을 입력하세요 : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (arr[i] != 0 && strcmp(name, arr[i]->name) == 0) {
					free(arr[i]);
					arr[i] = 0;
				}
			}
			break;
		case 5:
			printf("합산 점수를 기준으로 정렬됩니다.\n");
			orderBySumDesc(arr);
			ListAll(arr);
			break;
		case 6:
			printf("등수를 오름차순으로 정렬합니다.\n");
			orderBySumDesc(arr);
			Rank(arr);
			ListAll(arr);
			break;

		case 0:
			printf("프로그램을 종료합니다\n"); return 0;
		default:
			printf("잘못된 입력입니다.\n");
		}
		system("pause");
		system("cls"); //정보 제거
	}
}