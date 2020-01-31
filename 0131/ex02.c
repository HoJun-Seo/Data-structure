//ex02.c Queue 기본 구조
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}Queue;

Queue* getNode()
{
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->link = 0;
	return newNode;
}

void Enqueue(Queue** front, Queue** rear, int data)
{
	if (*front == NULL) //큐가 비어있으면
	{
		*front = getNode(); //프론트가 신규 노드를 받고
		*rear = *front; //rear도 front 와 같은 값을 가진다.
		//(*rear)->data = data;
	}
	else { //rear 는 마지막으로 들어간 구조체를 가리키는 역할
		
		(*rear)->link = getNode();
		*rear = (*rear)->link;
		   
		   /* Queue* tmp = getNode();
		tmp->data = data;
		(*rear)->link = tmp;
		*rear = tmp; */
	}
	(*rear)->data = data; //공통 코드 -> rear가 가리키는 data 영역에 data 값 대입
}

void main()
{
	Queue* front = NULL;
	Queue* rear = NULL;

	Enqueue(&front, &rear, 10);
	Enqueue(&front, &rear, 20);
	Enqueue(&front, &rear, 30);

	printf("%d - %d - %d \n", front->data, front->link->data, front->link->link->data);
}