//스택 직접 구현
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* getNode()
{
	Stack* newNode = (Stack*)malloc(sizeof(Stack)); //동적 공간 할당
	return newNode;
}

void push(Stack** top, int data)
{
	Stack* tmp = *top; //이전 구조체의 주소를 link 에 저장하기 위함(현재 top 주소 임시 저장)
	//새 구조체 생성(스택에 쌓을 데이터 및 링크 주소(자신 이전에 스택에 쌓여있는 구조체의 주소))
	*top = getNode(); //신규 구조체 주소 반환(스택에 새로 들어갈 구조체 주소)
	(*top)->data = data;
	(*top)->link = tmp;
}

int main()
{
	int data;
	char c;
	Stack* top = NULL;
	
	printf("스택에 쌓을 데이터를 입력하십시오 : ");
	scanf("%d", &data);
	do
	{
		push(&top, data);
		printf("계속 하시겠습니까? : ");
		scanf("%c", &c);
	} while (c == 'y' || c == 'Y');
	
}