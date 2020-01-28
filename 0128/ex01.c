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
	int data = *(stack + *top); //대입은 복사하므로, 원본을 직접 삭제해야 한다.
	*(stack + *top) = 0; //삭제의 의미로 0을 대입
	return data;
}
int main()
{
	int stack[5] = { 0 };
	int top = 0; //포인터 변수의 역할 (인덱스 참조)

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