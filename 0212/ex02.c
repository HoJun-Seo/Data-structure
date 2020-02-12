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

	printf("중위 표기식 입력 : ");
	scanf("%s", infix);


	for (int i = 0; infix[i] != '\0'; i++)
	{
		//printf("%c ", infix[i]); (입력이 정확하게 들어가는지 확인)
		//1. 숫자는 그대로 후위 표현식에 담는다.
		if ('0' <= infix[i] && infix[i] <= '9')
		{
			*p++ = infix[i];
		}
		//2. 연산자는 스택에 저장한다.
		else {
			//2-1. 연산자의 우선순위를 고려하여 push 하기
			//연산자의 우선순위를 반환하는 함수 만들기
			//(스택이 비어있지 않으면 우선순위를 비교)
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
			push(&top, infix[i]); //스택이 비어있으면 그냥 저장

			//괄호 처리 코드
			if (infix[i] == ')')
			{
				pop(&top); //마지막에 입력한 ) 를 제거
				while (top->data != '(')
				{
					*p++ = pop(&top);
				}
				pop(&top); //아직 남아있는 ( 를 제거
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