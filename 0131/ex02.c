//ex02.c Queue �⺻ ����
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
	if (*front == NULL) //ť�� ���������
	{
		*front = getNode(); //����Ʈ�� �ű� ��带 �ް�
		*rear = *front; //rear�� front �� ���� ���� ������.
		//(*rear)->data = data;
	}
	else { //rear �� ���������� �� ����ü�� ����Ű�� ����
		
		(*rear)->link = getNode();
		*rear = (*rear)->link;
		   
		   /* Queue* tmp = getNode();
		tmp->data = data;
		(*rear)->link = tmp;
		*rear = tmp; */
	}
	(*rear)->data = data; //���� �ڵ� -> rear�� ����Ű�� data ������ data �� ����
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