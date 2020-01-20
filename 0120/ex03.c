#include<stdio.h>

void func2(int** ppnum)
{
	//ppnum의 값에 11을 곱하라.

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

//디버깅 모드 진입 : F11