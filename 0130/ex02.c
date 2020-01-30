//ex01.c - 스택 기본 코드를 구현
//printStack() 함수를 구현하세요(세로로 출력하도록)

#include<stdio.h>
#include<stdlib.h>

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

void push(Stack** top, char data)
{
	Stack* tmp = *top;
	(*top) = getNode();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack** top)
{
	Stack* tmp = *top;
	char data = (*top)->data;
	(*top) = (*top)->link;
	free(tmp);
	return data;
}

void printStack(Stack* top)
{
	printf("===printStack===\n\n");
	while (top != NULL) {
		printf("\t│ %3c │\n", top->data);
		top = top->link;
	}
	printf("\t└─────┘\n");
	printf("\n=====================\n\n");
}

int main()
{
	Stack* top = NULL;

	int i = 0, j = 0, count = 0;
	int tm, time;
	int salary;
	char sal[100];
	//시간당 급여 : 20000
	//월 근무시간 : 180
	//월 급여 : 3600000
	//출력 : 3,600,000
	printf("시간당 급여를 입력하세요 : ");
	scanf("%d", &tm);
	printf("하루 근무시간을 입력하세요(월 근무일수는 20일 입니다.) : ");
	scanf("%d", &time);
	salary = tm * (time * 20);

	sprintf(sal, "%d", salary);

	while (sal[i] != '\0') {
		i++;
		j++;
	}
	for (; i >=0; i--)
	{
		push(&top, sal[i]);
		if (count % 3 == 0 && count != 0) {
			push(&top, ',');
			j++;
		}
		count++;
	}

	printStack(top);

	printf("이번달 급여는 ");
	for (; j >= 0; j--) printf("%c", pop(&top));
	printf("입니다.\n");
	
}