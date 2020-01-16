#include<stdio.h>
#include<stdlib.h>
int MyStrCmp(char* p1, char* p2) {
	//배열 및 포인터는 주소를 전달
	//주소는 포인터로 받음
	//1. char 는 아스키 코드에 의해 정수로 표현된다.
	//2. 대문자와 소문자는 아스키코드가 서로 다르다.
	//3. 문자열은 배열이므로, for문으로 순차적인 접근이 가능하다.
	//4. C언어 문자열의 마지막에는 NULL 문자('\0') 가 있다.
	//5. NULL 문자의 아스키 코드 값은 0이다.
	int result;
	int i = 0;
	while(1) {
		if (p1[i] == '\0' || p2[i] == '\0') break;
		if (p1[i] != p2[i]) {
			result = 0;
			break;
		}
		else result = 1;
		i++;
	}
	return result;
	/*while(*p1 != '\0' && *p2 != 0){
		if(*p1 != *p2) return 0;
		p1++;
		p2++;
	}
	
	return p1;
	*/

	/*for(p1, p2; *p1 && *p2; p1++, p2++)
		if(*p1 != *p2) return 0;
	return 1;
	*/
}
int main(void)
{
	char str1[] = "ITBANK";
	char str2[] = "ITANK";
	char* str3 = "ITBANK";

	printf("%d %d %d\n", str1, str2, str3);

	printf("MyStrCmp(str1, str2) : ");
	printf(MyStrCmp(str1, str2) ? "같다\n" : "다르다\n");

	printf("MyStrCmp(str1, str3) : ");
	printf(MyStrCmp(str1, str3) ? "같다\n" : "다르다\n");
	return 0;
}