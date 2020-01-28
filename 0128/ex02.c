//ex02_stack.c
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* link;
}Stack;

Stack* getNode()
{
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	newNode->link = NULL;
	return newNode;
}

void push(Stack** top, int data)
{
	Stack* tmp = *top;
	*top = getNode(); //�����Ҵ��� ���� ������ �����ϰ�, �����͸� NULL�� �ʱ�ȭ
	(*top)->data = data;
	(*top)->link = tmp;
}

int main()
{
	Stack* top = NULL;
	
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printf("%d - %d - %d\n", top->data, top->link->data, top->link->link->data);
}