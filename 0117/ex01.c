//ex01.c �Լ� ���� �˾ƺ���
#include<stdio.h>
int getMaxNum(int n1, int n2); //�Լ��� ����
int getMaxNum3(int n1, int n2, int n3);
int getMaxNum(n1, n2) //�Լ��� ����, �󼼳��� ���� �ۼ�
{
	if (n1 > n2) return n1;
	else		 return n2; //��ȯ, ��ȯ���� ȣ���� ��ü�Ѵ�.
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
		[��ȯ��][�Լ��̸�]([�Ű�����], [�Ű�����])
			y =	f(x)
	*/
	//�Լ��� ���� : �Լ��� ���ĸ� �˷��ش�.
	//�Լ��� ���� : �Լ��� ���� + ����(��ü)���� �˷��ش�.
	//�Լ��� ȣ�� : �Լ��� �̸��� �ҷ��� ������ �����Ѵ�.
	//�Լ��� ��ȯ : �Լ��� ������ �������� ȣ���ڸ��� �ǵ�����
	int n1 = 113, n2 = 25, n3 = 512;
	int max = getMaxNum(n1, n2); //getMaxNum �Լ� ȣ��(call)
	printf("max : %d\n", max);
	int max2 = getMaxNum3(n1, n2, n3);
	printf("max2 : %d\n", max2);

	return 0;
}
