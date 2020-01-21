//ex02.c 구조체

#include<stdio.h>
#include<stdlib.h> 
struct member {
	char name[20];
	int age;
};
//서로 다른 자료를 묶어서 표현할 수 있는 사용자 정의 자료형 - 구조체
typedef struct member2 {
	char name[20];
	int age;
}Member;

int main()
{ 
	struct member mem1 = { "서호준", 25 };
	printf("%s, %d 살\n", mem1.name, mem1.age);

	Member mem2 = { "홍진호", 37 };
	printf("%s, %d살\n", mem2.name, mem2.age);
	printf("%s, %d살\n", mem2.name, mem2.age);

	//배열을 구조체로 넘기면 배열 통째로 모두 넘겨줄수 있다.

	int* p  = malloc(4); //운영체제에게 할당받고 싶은 바이트 단위의 메모리 크기를 작성한다.(4 바이트)
	*p = 10;
	printf("*p : %d\n", *p);
	free(p); //메모리 사용이 끝났으니 운영체제에게 메모리 공간을 반납한다.
	printf("*p : %d\n", *p);

	//프로그램이 컴파일 되기 이전에 변수가 얼마나 필요할 지 알 수 없을때 동적할당을 활용한다.
	//또는 구조체 변수를 만들때 힙 영역(동적할당 영역 - 변수의 이름이 존재하지 않음(주소로 접근해야 한다 - 포인터))에 변수를 만들어준다.


}
