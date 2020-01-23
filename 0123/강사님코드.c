// ex01.c - �л� ���� ���� ���α׷�
/*
	�л��� ������ ������ �� �ִ� ���α׷� �����
	
	1. �ű� ���
	2. �˻�
	3. ���� ����
	4. ���� ����
	5. ���� �������� ����
	6. ��� �������� ����
	7. ��ü ���
	0. ����
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
	printf("=== �ű� �л� ��� ===\n\n");
	for (int i = 0; i < 100; i++) {
		if (arr[i] == 0) {
			arr[i] = (Student*)malloc(sizeof(Student));
			printf("�̸� �Է� : "); scanf("%s", arr[i]->name);
			printf("���� �Է� : "); scanf("%d", &arr[i]->kor);
			printf("���� �Է� : "); scanf("%d", &arr[i]->eng);
			printf("���� �Է� : "); scanf("%d", &arr[i]->mat);
			arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->mat;
			arr[i]->avg = arr[i]->sum / 3.0;
			break;
		}
	}
}
void listAll(Student** arr) {
	printf("=== ��ü ��� ===\n\n");
	for (int i = 0; i < 100; i++) {
		if (arr[i] != 0) {
			printf("%d) %s, %3d, %3d, %3d, %3d, %5.2f, %3d��\n\n",
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
	// ���� ���� �������� ����
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
	// ��� ���� �������� ����
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
	printf("�˻��� �л��� �̸��� �Է� : ");
	scanf("%s", find);
	int flag = 0;
	for (int i = 0; arr[i] != NULL && i < 100 ; i++) {
		if (strcmp(find, arr[i]->name) == 0) {
			Student* st = arr[i];
			printf("\n\n�̸� : %s\n"
				"���� : %3d\n"
				"���� : %3d\n"
				"���� : %3d\n"
				"�հ� : %3d\n"
				"��� : %5.2f\n"
				"��� : %3d\n\n", st->name, st->kor, st->eng, st->mat,
				st->sum, st->avg, st->rank);
			flag++;
			return st;
		}
	}
	if (flag == 0)
		printf("\n[%s] : �л��� ã�� �� �����ϴ�\n", find);
	return 0;
}
int parseInt(char* str) {	// ���ڿ��� ������ ����ȯ�ؼ� ��ȯ�ϴ� �Լ�
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
	// 1. �̸��� �̿��ؼ� ���ϴ� �л��� ã�´�.
	// 2. �л��� ������ ����Ѵ�

	if (st == 0)	// �˻� ����� ������
		return;		// ��ٷ� �Լ� ����
	
	// 3. ���ο� ������ �Է¹޴´�
	printf("\n������ ������ �Է��ϼ��� (���� ������ ������ �׳� ����)\n");

	char name[20], ko[10], en[10], ma[10];
	
	gets(name);		// ���� ���� ����
	printf("������ �̸� �Է� : "); 	gets(name);
	printf("������ ���� �Է� : "); 	gets(ko);
	printf("������ ���� �Է� : "); 	gets(en);
	printf("������ ���� �Է� : "); 	gets(ma);

	// ����ڰ� �Է��� ���� ������, ���� ���� (���͸� ġ�� �׳� ������)
	if (strcmp("", name) != 0)	strcpy(st->name, name);
	if (strcmp("", ko) != 0)	st->kor = parseInt(ko);
	if (strcmp("", en) != 0)	st->eng = parseInt(en);
	if (strcmp("", ma) != 0)	st->mat = parseInt(ma);

	// 4. ���������� ����Ǹ�, �հ�� ����� ���� ����Ѵ�
	st->sum = st->kor + st->eng + st->mat;
	st->avg = st->sum / 3.0;

	// 5. �����Լ��� ���ư��� ����� �ٽ� ����Ѵ�(��ü)
}
void deleteStudent(Student* st, Student** arr) {
	if (st == 0)
		return;

	char select[10];
	printf("[%s] �л� ������ �����Ͻðڽ��ϱ� (y/N) : ", st->name);
	gets(select);
	gets(select);
	if (strcmp("y", select) == 0 || strcmp("Y", select) == 0 || strcmp("yes", select) == 0) {
		for (int i = 0; i < 100; i++) {
			if (arr[i] != NULL && arr[i] == st) {
				free(st);
				arr[i] = 0;
				printf("�����Ǿ����ϴ�\n");
				return;
			}
		}
	}
	printf("�������� �ʾҽ��ϴ�\n");
}
int myStrCmp(char* str1, char* str2) {

	for (int i = 0; str1[i] != 0 || str2[i] != 0; i++) {
		if (str1[i] != str2[i])	// ���� ������ ���ڰ� ���� �ٸ���
			return str1[i] - str2[i];	// 0�� �ƴ� ���� ��ȯ�ȴ� (���̰�)
	}
	return 0;	// �Ϻ��ϰ� ������ 0�� ��ȯ�ȴ�
}

int main() {
	int menu;
	Student* result = 0;	// �˻� ����� ������ �� ����
	Student* arr[100] = { 0 };

	printf("myStrCmp : %d\n", myStrCmp("Hell0", "Hello"));

	while (1) {
		printf("\n\t=== �л� ���� ���� ���α׷� ===\n\n"
			"1. �ű� ���\n"
			"2. �˻�\n"
			"3. ���� ����\n"
			"4. ���� ����\n"
			"5. ���� �������� ����\n"
			"6. ��� �������� ����\n"
			"7. ��ü ���\n"
			"0. ����\n\n");
		printf("�޴� ���� >>> "); scanf("%d", &menu); /* SDL �˻� ���� */
		switch (menu) {
			// �޴��� �´� �ڵ� ����(������ �Լ� ȣ���� ���·�)
		case 1:
			insertStudent(arr);
			refreshRank(arr);			// ��� �ٽ� ���
			break;
		case 2:
			result = findStudent(arr);
			break;
		case 3:
			result = findStudent(arr);	// �˻��� ����� �޾Ƽ�
			modifyStudent(result);		// �˻��� �л��� ����ü �ּҸ� ����
			refreshRank(arr);			// ��� �ٽ� ���
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
			printf("���α׷��� �����մϴ� !!\n\n");
			return;
		}
		system("pause");
		system("cls");
	}
}
