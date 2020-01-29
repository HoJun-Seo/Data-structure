//참조 없이 직접 제작

#include<stdio.h>
#include<stdlib.h>

/*
	코드 작성 시 주의 사항
	1. 대입 연산자는 일반적으로 우변을 먼저 처리한다.
	2. 대입 연산자의 좌변은 공간을 말하고, 우변은 값을 말한다.
	3. 대입 연산자의 양변의 자료형은 같아야 한다.
	4. 함수 호출 시, 인자값과 , 매개변수의 개수 및 자료형이 같아야 한다.
	5. 함수 정의에서 매개변수는 지역변수와 유사한 성격을 가진다.
	6. 함수의 자료형은 함수 반환값의 자료형과 같다.
	7. 함수 반환값은 함수 호출 부분을 대체한다.
	8. 함수 호출시 값을 전달하면 참조 단계가 늘어나지 않는다.
	9. 함수 호출시 주소를 전달하면 참조 단계가 늘어난다.
		- int 의 주소를 전달하면 int* 로 받는다.
		- int* 의 주소를 전달하면 int** 로 받는다.
		- Stack* 의 주소를 전달하면 Stack** 로 받는다.
		- Stack* 의 값을 전달하면 Stack* 로 받는다.
		- int 의 값을 전달하면 int 로 받는다.
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