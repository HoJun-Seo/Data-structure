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
	int** ppnum = &pnum; //���� ������

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
		pointer : Ư�� �޸� �ּҰ��� �����ϴ� ����
		�ּҴ� �����̹Ƿ�, ũ��� int ���� ũ��� ����.

		Asterisk (*) : ������ ������ ���Ǵ� ��ȣ
		1) ����ÿ��� �ش� ������ ������ �������� ��Ÿ����.(�ڷ���)
		2) �� �ܿ���, ������ ������ ����Ű�� ����� ��Ÿ����.

		Amper sand (&) : ������ �տ� �Ἥ, ������ �ּҸ� ��Ÿ���� ������ �Ѵ�.
	*/

	func(&num);
}