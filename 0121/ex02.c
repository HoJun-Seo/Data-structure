//ex02.c ����ü

#include<stdio.h>
#include<stdlib.h> 
struct member {
	char name[20];
	int age;
};
//���� �ٸ� �ڷḦ ��� ǥ���� �� �ִ� ����� ���� �ڷ��� - ����ü
typedef struct member2 {
	char name[20];
	int age;
}Member;

int main()
{ 
	struct member mem1 = { "��ȣ��", 25 };
	printf("%s, %d ��\n", mem1.name, mem1.age);

	Member mem2 = { "ȫ��ȣ", 37 };
	printf("%s, %d��\n", mem2.name, mem2.age);
	printf("%s, %d��\n", mem2.name, mem2.age);

	//�迭�� ����ü�� �ѱ�� �迭 ��°�� ��� �Ѱ��ټ� �ִ�.

	int* p  = malloc(4); //�ü������ �Ҵ�ް� ���� ����Ʈ ������ �޸� ũ�⸦ �ۼ��Ѵ�.(4 ����Ʈ)
	*p = 10;
	printf("*p : %d\n", *p);
	free(p); //�޸� ����� �������� �ü������ �޸� ������ �ݳ��Ѵ�.
	printf("*p : %d\n", *p);

	//���α׷��� ������ �Ǳ� ������ ������ �󸶳� �ʿ��� �� �� �� ������ �����Ҵ��� Ȱ���Ѵ�.
	//�Ǵ� ����ü ������ ���鶧 �� ����(�����Ҵ� ���� - ������ �̸��� �������� ����(�ּҷ� �����ؾ� �Ѵ� - ������))�� ������ ������ش�.


}
