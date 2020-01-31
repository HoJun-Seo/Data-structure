//ex03.c - Queue, Enqueue 함수까지 구현
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Queue;

Queue* getNode()
{
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->link = NULL;
	return newNode;
}

void Enqueue(Queue** front, Queue** rear, int data)
{
	if (*front == NULL)
	{
		*front = getNode();
		*rear = *front;
	}
	else
	{
		(*rear)->link = getNode();
		*rear = (*rear)->link;
	}
	(*rear)->data = data;
}

int Dequeue(Queue** front)
{
	Queue* tmp = *front;
	int data = (*front)->data;
	(*front) = tmp->link;
	free(tmp);
	return data;
}

int main()
{
	Queue* front = NULL;
	Queue* rear = NULL;
	
	Enqueue(&front, &rear, 10);
	Enqueue(&front, &rear, 20);
	Enqueue(&front, &rear, 30);

	printf("%d - %d - %d\n", front->data, front->link->data, front->link->link->data);

	printf("[Front] %d ", Dequeue(&front));
	printf("%d ", Dequeue(&front));
	printf("%d [Rear]", Dequeue(&front));
}