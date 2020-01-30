//ex01.c - 스택 기본 코드를 구현
//printStack() 함수를 구현하세요(세로로 출력하도록)

#include<stdio.h>
#include<stdlib.h>
int Size = 3;

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* getNode()
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->link = NULL;
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
	(*top) = (*top)->link;
	free(tmp);
	return data;
}

void printStack(Stack* top)
{
	printf("===printStack===\n\n");
	while (top != NULL) {
		printf("\t│ %3d │\n", top->data);
		top = top->link;
	}
	printf("\t└─────┘\n");
	printf("\n=====================\n\n");
}

int main()
{
	Stack* top = NULL;


	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printStack(top);

	printf("pop : %d \n", pop(&top));
	printf("pop : %d \n", pop(&top));
	printf("pop : %d \n", pop(&top));

	printStack(top);
}