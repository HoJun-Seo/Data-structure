#include<stdio.h>
int main()
{
	int score[5] = { 100, 94, 96, 88, 99 };
	int rank[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		rank[i]++; //일단 모두 0 에서 1씩 증가해서 1등으로 지정
		for (int j = 0; j < 5; j++) {
			if (score[i] < score[j]) { //나 보다 더 높은 점수가 있으면
				rank[i]++; //내 등수의 숫자가 증가(순위가 떨어짐)
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d) %d점, %d등\n", i, score[i], rank[i]);
	}
}