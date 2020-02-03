#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Queue;

typedef struct food {
	char food[100];
}FOOD;

Queue* getNode()
{
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->link = NULL;
	return newNode;
}

void Enqueue(Queue** front, Queue** rear, char* food)
{
	if (*front == NULL) {
		(*front) = getNode();
		*rear = *front; //rear�� front�� ���� ���� �����Ѵ�.
	}
	else {
		(*rear)->link = getNode();
		(*rear) = (*rear)->link;
	}
	(*rear)->data = food;
}


int dequeue(Queue** front, Queue** rear)
{
	Queue* tmp = (*front);
	int data = (*front)->data;
	(*front) = (*front)->link; //���� �������� ��ġ�� ����Ų��.
	if (*front == NULL) *rear = *front;
		//front�� NULL �̸� == ť�� �������
		//rear �� NULL �� �������ش�.
	free(tmp);
	return data;
}

void printQueue(Queue* front)
{
	while (front != NULL) {
		printf("%s - ", front->data);
		front = front->link;
	}
}

int main()
{
	int i = 0;
	int menu;
	Queue* front = NULL;
	Queue* rear = NULL;
	FOOD food[100];
	
	while(1){
		printf("\n\n1. �ֹ� �Է�\n");
		printf("2. �ֱ� �޴� �ϼ� �˸�\n");
		printf("3. �켱 ����\n");
		printf("4. ���� ����\n\n");

		printf("�Է� > ");
		scanf("%d", &menu);

		switch (menu)
		{

		case 1:
			printf("�ֹ��� �޴��� �Է� : ");
			if (food[i].food != NULL) {
				scanf("%s", food[i].food);
				Enqueue(&front, &rear, food[i].food);
				i++;
			}
			else printf("�߸��� �Է��Դϴ�.\n");
			break;
		case 2:
			if (front->data == NULL) printf("�ֹ� ������ �����ϴ�.\n");
			printf("%s ���Խ��ϴ�.\n", dequeue(&front, &rear));
			break;
		case 3:

		case 4:
			printf("������ ����Ǿ����ϴ�.");
			return 0;

		default:
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
		printf("\n\n\n");
		printf("�ֹ���� : ");
		printf("\nFRONT - ");
		printQueue(front);
		printf("REAR\n");

	}
	

	return 0;
}