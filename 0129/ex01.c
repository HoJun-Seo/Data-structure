//���� ���� ���� ����

#include<stdio.h>
#include<stdlib.h>

/*
	�ڵ� �ۼ� �� ���� ����
	1. ���� �����ڴ� �Ϲ������� �캯�� ���� ó���Ѵ�.
	2. ���� �������� �º��� ������ ���ϰ�, �캯�� ���� ���Ѵ�.
	3. ���� �������� �纯�� �ڷ����� ���ƾ� �Ѵ�.
	4. �Լ� ȣ�� ��, ���ڰ��� , �Ű������� ���� �� �ڷ����� ���ƾ� �Ѵ�.
	5. �Լ� ���ǿ��� �Ű������� ���������� ������ ������ ������.
	6. �Լ��� �ڷ����� �Լ� ��ȯ���� �ڷ����� ����.
	7. �Լ� ��ȯ���� �Լ� ȣ�� �κ��� ��ü�Ѵ�.
	8. �Լ� ȣ��� ���� �����ϸ� ���� �ܰ谡 �þ�� �ʴ´�.
	9. �Լ� ȣ��� �ּҸ� �����ϸ� ���� �ܰ谡 �þ��.
		- int �� �ּҸ� �����ϸ� int* �� �޴´�.
		- int* �� �ּҸ� �����ϸ� int** �� �޴´�.
		- Stack* �� �ּҸ� �����ϸ� Stack** �� �޴´�.
		- Stack* �� ���� �����ϸ� Stack* �� �޴´�.
		- int �� ���� �����ϸ� int �� �޴´�.
*/
typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* getNode()
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	return newnode;
}

void push(Stack** top, int data)
{
	Stack* tmp = *top;
	(*top) = getNode();
	(*top)->data = data;
	(*top)->link = tmp;
}
int pop(Stack** top)
{
	Stack* tmp = *top;
	int data = (*top)->data;
	(*top)->data = 0;
	(*top) = (*top)->link;
	free(tmp);
	return data;
}

int main()
{
	Stack* top = NULL;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printf("%d - %d - %d\n", top->data, top->link->data, top->link->link->data);

	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
}