//ex03.c - �Լ��� �迭, �Լ��� ����ü
#include<stdio.h>
typedef struct node { //���� �ٸ� �ڷ����� ��� �����ϱ� ���� ����� ���� �ڷ���
	int num;
	char ch;
	double db;
}Test;
void PrintStruct(Test t) { //����ü ������ �Լ��� ���ڷ� ���� �����ϴ�.
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
	Test t1 = { 7, 'E', 0.1 }; //����ü ���� - �Լ� ȣ�� �� main �Լ� ���� ����ü ������ �ּҿ� �Լ� ���ǽ��� �Ű������� �ּҴ� �ٸ���.
								//������ �����̱� ������ ���� �ٸ� �޸𸮿� ������ ������ �Ҵ�ȴ�.(�����Ϳ� ����� ����)
	int arr[5] = { 7, 'E', 1 }; //�迭 - ���� ���� �ڷ��������� ������ �� �ִ�. - �迭�� �̸� ��ü�� �����ּ��̱� ������
								// main �Լ� ���� �迭�� �ּҿ� �Լ� ���ǽ��� �Ű������� ���޵Ǵ� �迭�� �ּҴ� �����ϴ�(���簳��)
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