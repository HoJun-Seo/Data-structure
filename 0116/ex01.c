#include<stdio.h>
int main(void)
{
	char name[20];
	printf("이름을 입력 : ");
	scanf("%s", name);
	printf("입력한 이름은 %s 입니다. \n", name);
	//SDL : Secure Development LifeCycle
	//보안 상 잠재적 위협이 있는 함수를 사용할 수 없게 막음
	//버퍼 오버플로우 취약점이 있으면 막는다.
	//크기 체크를 하지 않고, 복사하는 과정에서 다른 메모리를 덮어 쓸 수 있는 위협
	return 0;
}