//���� ���� ����
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* getNode()
{
	Stack* newNode = (Stack*)malloc(sizeof(Stack)); //���� ���� �Ҵ�
	return newNode;
}

void push(Stack** top, int data)
{
	Stack* tmp = *top; //���� ����ü�� �ּҸ� link �� �����ϱ� ����(���� top �ּ� �ӽ� ����)
	//�� ����ü ����(���ÿ� ���� ������ �� ��ũ �ּ�(�ڽ� ������ ���ÿ� �׿��ִ� ����ü�� �ּ�))
	*top = getNode(); //�ű� ����ü �ּ� ��ȯ(���ÿ� ���� �� ����ü �ּ�)
	(*top)->data = data;
	(*top)->link = tmp;
}

int main()
{
	int data;
	char c;
	Stack* top = NULL;
	
	printf("���ÿ� ���� �����͸� �Է��Ͻʽÿ� : ");
	scanf("%d", &data);
	do
	{
		push(&top, data);
		printf("��� �Ͻðڽ��ϱ�? : ");
		scanf("%c", &c);
	} while (c == 'y' || c == 'Y');
	
}