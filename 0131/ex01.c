//ex01.c - �����Լ� �Ű�����
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
	char cmd[100] = "start chrome "; //13��° ���� ���� ����ϱ�
	int i;
	if (argc == 2)
	{
		if (strcmp(argv[1], "/h") == 0) {
			printf("����\n\n ���α׷��� �����ϸ鼭 �ڿ� ���ϴ� ����Ʈ�� �Է��ϼ���\n");
			printf("����) day10 http://www.naver.com\n\n");
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