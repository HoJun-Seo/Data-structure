//ex01.c 함수 구조 알아보기
#include<stdio.h>
int getMaxNum(int n1, int n2); //함수의 선언
int getMaxNum3(int n1, int n2, int n3);
int getMaxNum(n1, n2) //함수의 정의, 상세내용 까지 작성
{
	if (n1 > n2) return n1;
	else		 return n2; //반환, 반환값은 호출을 대체한다.
}
int getMaxNum3(int n1, int n2, int n3) 
{
	int maximum;
	if (n1 >= n2) maximum = n1;
	else maximum = n2;

	if (maximum >= n3) return maximum;
	else return n3;
	/*
	int max = n1;
	if(max < n2) max = n2;
	if(max < n3) max = n3;
	return max;
	*/
}

int main(void)
{
	/*
		[반환형][함수이름]([매개변수], [매개변수])
			y =	f(x)
	*/
	//함수의 선언 : 함수의 형식만 알려준다.
	//함수의 정의 : 함수의 형식 + 내용(몸체)까지 알려준다.
	//함수의 호출 : 함수의 이름을 불러서 내용을 실행한다.
	//함수의 반환 : 함수의 실행결과 최종값을 호출자리로 되돌리기
	int n1 = 113, n2 = 25, n3 = 512;
	int max = getMaxNum(n1, n2); //getMaxNum 함수 호출(call)
	printf("max : %d\n", max);
	int max2 = getMaxNum3(n1, n2, n3);
	printf("max2 : %d\n", max2);

	return 0;
}
