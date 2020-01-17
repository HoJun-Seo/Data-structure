//ex03.c - 함수와 배열, 함수와 구조체
#include<stdio.h>
typedef struct node { //서로 다른 자료형을 묶어서 관리하기 위한 사용자 정의 자료형
	int num;
	char ch;
	double db;
}Test;
void PrintStruct(Test t) { //구조체 변수는 함수의 인자로 전달 가능하다.
	printf("&t : %p\n", &t);
	printf("%d, %c, %.1f\n", t.num, t.ch, t.db);
}
void PrintArray(int arr[]) {
	printf("arr : %p\n", arr);
	for (int i = 0; arr[i] != '\0'; i++) {
		printf("%d\n", arr[i]);
	}
}
int main(void)
{
	Test t1 = { 7, 'E', 0.1 }; //구조체 변수 - 함수 호출 시 main 함수 내의 구조체 변수의 주소와 함수 정의시의 매개변수의 주소는 다르다.
								//변수의 개념이기 때문에 서로 다른 메모리에 변수의 공간이 할당된다.(포인터와 비슷한 개념)
	int arr[5] = { 7, 'E', 1 }; //배열 - 서로 같은 자료형끼리만 묶어줄 수 있다. - 배열의 이름 자체가 시작주소이기 때문에
								// main 함수 내의 배열의 주소와 함수 정의시의 매개변수로 전달되는 배열의 주소는 동일하다(복사개념)
	PrintStruct(t1);
	PrintArray(arr);
	printf("&t : %p\n", &t1);
	printf("arr : %p\n", arr);
	for (int i = 0; arr[i] != 0; i++) {
		printf("arr[%d] : %d\n", i, arr[i]);
	}
	system("cls");
	//================================================
	printf("%s\n", "Hello World!!");
	printf("%p\n", "Hello World!!");
	printf("%p\n", &"Hello World!!");

	return 0;
}