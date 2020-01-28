// ex03_test.c
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}Stack;
Stack* getNode() {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	newNode->link = NULL;
	return newNode;
}
void push(Stack** top, int data) {
	Stack* tmp = *top;
	*top = getNode();
	(*top)->data = data;
	(*top)->link = tmp;
}
void printStack(Stack* top) {
	printf("Stack : ");
	while (top != NULL) {
		printf("%d", top->data);
		top = top->link;
		printf("%s", (top != NULL) ? ", " : "\n");
	}
	printf("\n\n");
}
int pop(Stack** top) {
	Stack* tmp = *top;
	int num = (*top)->data;
	*top = (*top)->link;
	free(tmp);
	return num;
}
int main() {
	Stack* top = NULL;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	printStack(top);

	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
}