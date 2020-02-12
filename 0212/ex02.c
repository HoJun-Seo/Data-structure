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
	*top = getNode();
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

int getPriority(char ch)
{
	switch (ch)
	{
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	default: return -1;
	}
}

int main()
{
	Stack* top = NULL;
	
	char infix[100];
	char postfix[100] = { 0 };
	char* p = postfix;

	printf("���� ǥ��� �Է� : ");
	scanf("%s", infix);


	for (int i = 0; infix[i] != '\0'; i++)
	{
		//printf("%c ", infix[i]); (�Է��� ��Ȯ�ϰ� ������ Ȯ��)
		//1. ���ڴ� �״�� ���� ǥ���Ŀ� ��´�.
		if ('0' <= infix[i] && infix[i] <= '9')
		{
			*p++ = infix[i];
		}
		//2. �����ڴ� ���ÿ� �����Ѵ�.
		else {
			//2-1. �������� �켱������ ����Ͽ� push �ϱ�
			//�������� �켱������ ��ȯ�ϴ� �Լ� �����
			//(������ ������� ������ �켱������ ��)
			if (top != NULL && infix[i] != '(' && infix[i] != ')')
			{
				int stackPri = getPriority(top->data);
				int inputPri = getPriority(infix[i]);
				if (stackPri >= inputPri)
				{
					while(top != NULL && infix[i] != '(' && infix[i] != ')')
						*p++ = pop(&top);
				}
			}
			push(&top, infix[i]); //������ ��������� �׳� ����

			//��ȣ ó�� �ڵ�
			if (infix[i] == ')')
			{
				pop(&top); //�������� �Է��� ) �� ����
				while (top->data != '(')
				{
					*p++ = pop(&top);
				}
				pop(&top); //���� �����ִ� ( �� ����
			}
		}
		//end for
	}
	while (top != NULL)
	{
		*p++ = pop(&top);
	}
	*p++ = '\0';
	printf("postfix : %s\n", postfix);
	printf("\n\n");
}