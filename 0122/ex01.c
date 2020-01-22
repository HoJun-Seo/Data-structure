#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	char name[20];
	int math, kor, eng, sum, rank;
	double avg;
}STUDENT;
void score(STUDENT* arr) {
	printf("�̸� : %s ���� : %d ���� : %d ���� : %d \n", arr->name, arr->kor, arr->eng, arr->math);
	printf("�հ� : %d ��� : %lf\n", arr->sum, arr->avg);
}
void ListAll(STUDENT** arr)
{
	printf("\n\n");
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] != 0 && sizeof(arr[i]) > 0) {
			printf("�̸� : %s\n", arr[i]->name);
			printf("���� : %d ���� : %d ���� : %d \n", arr[i]->kor, arr[i]->eng, arr[i]->math);
			printf("�հ� : %d ��� : %lf\n", arr[i]->sum, arr[i]->avg);
			printf("��� : %d\n", arr[i]->rank);
		}
	}
	printf("\n\n");
}
void orderBySumDesc(STUDENT** arr) {
	// ���� ���� �������� ����
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
			if (arr[i]->sum < arr[i]->sum) { //�� ���� �� ���� ������ ������
				arr[i]->rank += 1; //�� ����� ���ڰ� ����(������ ������)
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
		printf("�л� ���� ��� �� ���� ���� ���α׷��Դϴ�.\n");
		printf("1. �ű� ���\n2. �˻�\n3. ���� ����\n4. ���� ����\n5. ���� �������� ����\n6. ��� �������� ����\n0. ����\n");
		printf("�޴� ���� >>> "); scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("\n\n");
			for (i = 0; i < 100; i++)
			{
				if (arr[i] == 0) {
					arr[i] = (STUDENT*)malloc(sizeof(STUDENT));
					printf("����� ����� ������ �Է��ϼ���(�ִ� 100�� �Է� ����)\n");
					printf("�̸� : "); scanf("%s", arr[i]->name);
					printf("���� : "); scanf("%d", &arr[i]->kor);
					printf("���� : "); scanf("%d", &arr[i]->eng);
					printf("���� : "); scanf("%d", &arr[i]->math);
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
			printf("�˻��� ����� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (arr[i] != 0 && strcmp(name, arr[i]->name) == 0) {
					flag = 1;
					printf("�˻����\n");
					score(arr[i]);
				}
			}
			if (flag == 0)
				printf("����� �������� �ʽ��ϴ�.\n");
			printf("\n\n");
			break;
		case 3:
			flag = 0;
			printf("\n\n");
			printf("������ ������ ����� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			for (i = 0; i < 100; i++)
			{
				if (arr[i] != 0 && strcmp(name, arr[i]->name) == 0) {
					flag = 1;
					printf("1. ����\n2. ����\n3. ����\n");
					printf("������ ������ �����ϼ��� : ");
					scanf("%d", &upt);
					switch (upt) {
					case 1 :
						printf("���� ���� ���� : ");
						scanf("%d", &arr[i]->kor);
						arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
						arr[i]->avg = arr[i]->sum / 3;
						break;
					case 2:
						printf("���� ���� ���� : ");
						scanf("%d", &arr[i]->eng);
						arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
						arr[i]->avg = arr[i]->sum / 3;
						break;
					case 3:
						printf("���� ���� ���� : ");
						scanf("%d", &arr[i]->math);
						arr[i]->sum = arr[i]->kor + arr[i]->eng + arr[i]->math;
						arr[i]->avg = arr[i]->sum / 3;
						break;
					}
				}
			}
			break;
		case 4:
			printf("���� ��ų ����� �̸��� �Է��ϼ��� : ");
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
			printf("�ջ� ������ �������� ���ĵ˴ϴ�.\n");
			orderBySumDesc(arr);
			ListAll(arr);
			break;
		case 6:
			printf("����� ������������ �����մϴ�.\n");
			orderBySumDesc(arr);
			Rank(arr);
			ListAll(arr);
			break;

		case 0:
			printf("���α׷��� �����մϴ�\n"); return 0;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
		}
		system("pause");
		system("cls"); //���� ����
	}
}