//스택 다시 한번 제작(참조없이)

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* getNode()
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	return newnode;
}

void push(Stack** top, int data) {
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
	*top = (*top)->link;
	free(tmp);
	return data;
}

int main()
{
	Stack* top = NULL;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printf("%d - %d - %d \n", top->data, top->link->data, top->link->link->data);

	printf("pop : %d \n", pop(&top));
	printf("pop : %d \n", pop(&top));
	printf("pop : %d \n", pop(&top));
}