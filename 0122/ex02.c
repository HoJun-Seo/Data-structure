#include<stdio.h>
int main()
{
	int score[5] = { 100, 94, 96, 88, 99 };
	int rank[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		rank[i]++; //�ϴ� ��� 0 ���� 1�� �����ؼ� 1������ ����
		for (int j = 0; j < 5; j++) {
			if (score[i] < score[j]) { //�� ���� �� ���� ������ ������
				rank[i]++; //�� ����� ���ڰ� ����(������ ������)
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d) %d��, %d��\n", i, score[i], rank[i]);
	}
}