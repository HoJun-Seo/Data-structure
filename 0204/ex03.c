#include<stdio.h>
int result = 1;

int getFactorial(int num)
{
	if (num > 0)
		 result = num * getFactorial(num - 1);
	else return result;
}

int main() {
	//1.while문을 이용하여 정수의 팩토리얼 결과를 출력하기
	//4! = 4 * 3 * 2 * 1;
	int num = 4;
	int facto1 = 1;
	while (num > 0)
	{
		facto1 = facto1 * num;
		num--;
	}

	printf("facto1 : %d\n", facto1);

	int facto2 = getFactorial(4);
	printf("facto2 : %d\n", facto2);
}