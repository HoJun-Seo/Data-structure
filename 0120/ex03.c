#include<stdio.h>

void func2(int** ppnum)
{
	//ppnum�� ���� 11�� ���϶�.

	**ppnum = **ppnum * 11;
}

void func1(int* pnum)
{
	func2(&pnum);
}

int main(void)
{
	int num = 7;
	func1(&num);
	printf("num : %d\n", num);
}

//����� ��� ���� : F11