#include<stdio.h>
#include<stdlib.h>
int MyStrCmp(char* p1, char* p2) {
	//�迭 �� �����ʹ� �ּҸ� ����
	//�ּҴ� �����ͷ� ����
	//1. char �� �ƽ�Ű �ڵ忡 ���� ������ ǥ���ȴ�.
	//2. �빮�ڿ� �ҹ��ڴ� �ƽ�Ű�ڵ尡 ���� �ٸ���.
	//3. ���ڿ��� �迭�̹Ƿ�, for������ �������� ������ �����ϴ�.
	//4. C��� ���ڿ��� ���������� NULL ����('\0') �� �ִ�.
	//5. NULL ������ �ƽ�Ű �ڵ� ���� 0�̴�.
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
	printf(MyStrCmp(str1, str2) ? "����\n" : "�ٸ���\n");

	printf("MyStrCmp(str1, str3) : ");
	printf(MyStrCmp(str1, str3) ? "����\n" : "�ٸ���\n");
	return 0;
}