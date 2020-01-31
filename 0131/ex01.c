//ex01.c - 메인함수 매개변수
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	printf("argc : %d \n", argc); //argument Count

	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d] : %s \n", i, argv[i]);
		//argument Value
	}
	char cmd[100] = "start chrome "; //13번째 부터 글자 기록하기
	int i;
	if (argc == 2)
	{
		if (strcmp(argv[1], "/h") == 0) {
			printf("도움말\n\n 프로그램을 실행하면서 뒤에 원하는 사이트를 입력하세요\n");
			printf("예시) day10 http://www.naver.com\n\n");
		}
		else {
			for (i = 0; argv[1][i] != '\0'; i++)
			{
				cmd[i + 13] = argv[1][i];
			}
			cmd[i + 13] = '\0';
			printf("cmd : %s\n", cmd);
			system(cmd);
		}
	}


	return 0;
}