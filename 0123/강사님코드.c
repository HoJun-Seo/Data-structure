// ex01.c - 학생 성적 관리 프로그램
/*
	학생의 성적을 관리할 수 있는 프로그램 만들기
	
	1. 신규 등록
	2. 검색
	3. 정보 수정
	4. 정보 삭제
	5. 점수 내림차순 정렬
	6. 등수 오름차순 정렬
	7. 전체 출력
	0. 종료
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	char name[20];
	int kor, eng, mat, sum, rank;
	double avg;
}Student;
void insertStudent(Student** arr) {
	printf("=== 신규 학생 등록 ===\n\n");
	for (int i = 0; i < 100; i++) {
		if (arr[i] == 0) {
			arr[i] = (Student*)malloc(sizeof(Student));
			printf("이름 입력 : "); scanf("%s", arr[i]->name);
			printf("국어 입력 : "); scanf("%d", &arr[i]->kor);
			printf("영어 입력 : "); scanf("%d", &arr[i]->eng);
			printf("수학 입력 : "); scanf("%d", &arr[i]->mat);
			arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->mat;
			arr[i]->avg = arr[i]->sum / 3.0;
			break;
		}
	}
}
void listAll(Student** arr) {
	printf("=== 전체 출력 ===\n\n");
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			printf("%d) %s, %3d, %3d, %3d, %3d, %5.2f, %3d등\n\n",
				i + 1, arr[i]->name, arr[i]->kor, arr[i]->eng, arr[i]->mat,
				arr[i]->sum, arr[i]->avg, arr[i]->rank);
		}
	}
}
void refreshRank(Student** arr) {
	for (int i = 0; i < 100 && arr[i] != NULL; i++) {
		arr[i]->rank = 1;
		for (int j = 0; j < 100 && arr[j] != 0; j++) {
			if (arr[i]->sum < arr[j]->sum)
				arr[i]->rank++;
		}
	}
}
void orderBySumDesc(Student** arr) {
	// 총점 기준 내림차순 정렬
	for (int i = 0; i < 100 && arr[i] != 0; i++) {
		for (int j = i; j < 100 && arr[j] != 0; j++) {
			if (arr[i]->sum < arr[j]->sum) {
				Student* tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}	
		}
	}
}
void orderByRankAsc(Student** arr) {
	// 등수 기준 오름차순 정렬
	for (int i = 0; i < 100 && arr[i] != 0; i++) {
		for (int j = i; j < 100 && arr[j] != 0; j++) {
			if (arr[i]->rank > arr[j]->rank) {
				Student* tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
Student* findStudent(Student** arr) {
	char find[20];
	printf("검색할 학생의 이름을 입력 : ");
	scanf("%s", find);
	int flag = 0;
	for (int i = 0; arr[i] != NULL && i < 100 ; i++) {
		if (strcmp(find, arr[i]->name) == 0) {
			Student* st = arr[i];
			printf("\n\n이름 : %s\n"
				"국어 : %3d\n"
				"영어 : %3d\n"
				"수학 : %3d\n"
				"합계 : %3d\n"
				"평균 : %5.2f\n"
				"등수 : %3d\n\n", st->name, st->kor, st->eng, st->mat,
				st->sum, st->avg, st->rank);
			flag++;
			return st;
		}
	}
	if (flag == 0)
		printf("\n[%s] : 학생을 찾을 수 없습니다\n", find);
	return 0;
}
int parseInt(char* str) {	// 문자열을 정수로 형변환해서 반환하는 함수
	int ret = 0;
	for (int i = 0; str[i] != 0; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			ret *= 10;
			ret += str[i] - 48;
		}	
	}
	return ret;
}
void modifyStudent(Student* st) {
	// 1. 이름을 이용해서 원하는 학생을 찾는다.
	// 2. 학생의 정보를 출력한다

	if (st == 0)	// 검색 결과가 없으면
		return;		// 곧바로 함수 종료
	
	// 3. 새로운 정보를 입력받는다
	printf("\n변경할 정보를 입력하세요 (내용 변경이 없으면 그냥 엔터)\n");

	char name[20], ko[10], en[10], ma[10];
	
	gets(name);		// 남은 버퍼 비우기
	printf("변경할 이름 입력 : "); 	gets(name);
	printf("변경할 국어 입력 : "); 	gets(ko);
	printf("변경할 영어 입력 : "); 	gets(en);
	printf("변경할 수학 입력 : "); 	gets(ma);

	// 사용자가 입력한 값이 있으면, 새로 갱신 (엔터만 치면 그냥 지나감)
	if (strcmp("", name) != 0)	strcpy(st->name, name);
	if (strcmp("", ko) != 0)	st->kor = parseInt(ko);
	if (strcmp("", en) != 0)	st->eng = parseInt(en);
	if (strcmp("", ma) != 0)	st->mat = parseInt(ma);

	// 4. 과목점수가 변경되면, 합계와 평균을 새로 계산한다
	st->sum = st->kor + st->eng + st->mat;
	st->avg = st->sum / 3.0;

	// 5. 메인함수로 돌아가서 등수를 다시 계산한다(전체)
}
void deleteStudent(Student* st, Student** arr) {
	if (st == 0)
		return;

	char select[10];
	printf("[%s] 학생 정보를 삭제하시겠습니까 (y/N) : ", st->name);
	gets(select);
	gets(select);
	if (strcmp("y", select) == 0 || strcmp("Y", select) == 0 || strcmp("yes", select) == 0) {
		for (int i = 0; i < 100; i++) {
			if (arr[i] != NULL && arr[i] == st) {
				free(st);
				arr[i] = 0;
				printf("삭제되었습니다\n");
				return;
			}
		}
	}
	printf("삭제되지 않았습니다\n");
}
int myStrCmp(char* str1, char* str2) {

	for (int i = 0; str1[i] != 0 || str2[i] != 0; i++) {
		if (str1[i] != str2[i])	// 같은 순번의 글자가 서로 다르면
			return str1[i] - str2[i];	// 0이 아닌 값이 반환된다 (차이값)
	}
	return 0;	// 완벽하게 같으면 0이 반환된다
}

int main() {
	int menu;
	Student* result = 0;	// 검색 결과를 저장해 둘 변수
	Student* arr[100] = { 0 };

	printf("myStrCmp : %d\n", myStrCmp("Hell0", "Hello"));

	while (1) {
		printf("\n\t=== 학생 성적 관리 프로그램 ===\n\n"
			"1. 신규 등록\n"
			"2. 검색\n"
			"3. 정보 수정\n"
			"4. 정보 삭제\n"
			"5. 점수 내림차순 정렬\n"
			"6. 등수 오름차순 정렬\n"
			"7. 전체 출력\n"
			"0. 종료\n\n");
		printf("메뉴 선택 >>> "); scanf("%d", &menu); /* SDL 검사 안함 */
		switch (menu) {
			// 메뉴에 맞는 코드 진행(가급적 함수 호출의 형태로)
		case 1:
			insertStudent(arr);
			refreshRank(arr);			// 등수 다시 계산
			break;
		case 2:
			result = findStudent(arr);
			break;
		case 3:
			result = findStudent(arr);	// 검색한 결과를 받아서
			modifyStudent(result);		// 검색한 학생의 구조체 주소를 전달
			refreshRank(arr);			// 등수 다시 계산
			break;
		case 4:
			result = findStudent(arr);
			deleteStudent(result, arr);
			break;
		case 5:
			orderBySumDesc(arr);
			refreshRank(arr);
			listAll(arr);
			break;
		case 6:
			orderByRankAsc(arr);
			refreshRank(arr);
			listAll(arr);
			break;
		case 7:
			refreshRank(arr);
			listAll(arr);
			break;
		case 0:
			printf("프로그램을 종료합니다 !!\n\n");
			return;
		}
		system("pause");
		system("cls");
	}
}
