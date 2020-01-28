#include<stdio.h>
void push(int* stack, int* top, int data)
{
	*(stack + *top) = data;
	(*top)++;
	printf("top : %d\n", *top);
}
int pop(int* stack, int* top)
{
	(*top)--;
	int data = *(stack + *top); //������ �����ϹǷ�, ������ ���� �����ؾ� �Ѵ�.
	*(stack + *top) = 0; //������ �ǹ̷� 0�� ����
	return data;
}
int main()
{
	int stack[5] = { 0 };
	int top = 0; //������ ������ ���� (�ε��� ����)

	push(stack, &top, 10);
	push(stack, &top, 20);
	push(stack, &top, 30);

	for (int i = 0; i < 5; i++)
	{
		if(stack[i] != 0)
			printf("%d ", stack[i]);
	}printf("\n\n");

	printf("pop : %d \n", pop(stack, &top));
	printf("pop : %d \n", pop(stack, &top));
	printf("pop : %d \n", pop(stack, &top));
}