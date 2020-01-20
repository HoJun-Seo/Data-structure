#include<stdio.h>

void func(int* pnum)
{
	printf("func) pnum : %d\n", pnum);
	printf("func)*pnum : %d\n", *pnum);
}

int main(void)
{
	int num = 7;
	int* pnum = &num;
	int** ppnum = &pnum; //더블 포인터

	printf("   num : %d\n", num);
	printf("  &num : %d\n", &num);
	printf("  pnum : %d\n", pnum);
	printf(" *pnum : %d\n", *pnum);
	printf("\n");
	printf(" &pnum : %d\n", &pnum);
	printf(" ppnum : %d\n", ppnum);
	printf("*ppnum : %d\n", *ppnum);
	printf("**ppnum : %d\n", **ppnum);
	printf("\n");
	/*
		pointer : 특정 메모리 주소값을 저장하는 변수
		주소는 정수이므로, 크기는 int 형의 크기와 같다.

		Asterisk (*) : 포인터 변수에 사용되는 기호
		1) 선언시에는 해당 변수가 포인터 변수임을 나타낸다.(자료형)
		2) 그 외에는, 포인터 변수가 가리키는 대상을 나타낸다.

		Amper sand (&) : 변수의 앞에 써서, 변수의 주소를 나타내는 역할을 한다.
	*/

	func(&num);
}