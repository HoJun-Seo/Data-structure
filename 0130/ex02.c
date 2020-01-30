//ex01.c - ���� �⺻ �ڵ带 ����
//printStack() �Լ��� �����ϼ���(���η� ����ϵ���)

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
		printf("\t�� %3c ��\n", top->data);
		top = top->link;
	}
	printf("\t��������������\n");
	printf("\n=====================\n\n");
}

int main()
{
	Stack* top = NULL;

	int i = 0, j = 0, count = 0;
	int tm, time;
	int salary;
	char sal[100];
	//�ð��� �޿� : 20000
	//�� �ٹ��ð� : 180
	//�� �޿� : 3600000
	//��� : 3,600,000
	printf("�ð��� �޿��� �Է��ϼ��� : ");
	scanf("%d", &tm);
	printf("�Ϸ� �ٹ��ð��� �Է��ϼ���(�� �ٹ��ϼ��� 20�� �Դϴ�.) : ");
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

	printf("�̹��� �޿��� ");
	for (; j >= 0; j--) printf("%c", pop(&top));
	printf("�Դϴ�.\n");
	
}