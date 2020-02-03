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
		*rear = *front; //rear에 front의 참조 값을 대입한다.
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
	(*front) = (*front)->link; //다음 데이터의 위치를 가리킨다.
	if (*front == NULL) *rear = *front;
		//front가 NULL 이면 == 큐가 비었으면
		//rear 도 NULL 로 변경해준다.
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
		printf("\n\n1. 주문 입력\n");
		printf("2. 최근 메뉴 완성 알림\n");
		printf("3. 우선 예약\n");
		printf("4. 영업 종료\n\n");

		printf("입력 > ");
		scanf("%d", &menu);

		switch (menu)
		{

		case 1:
			printf("주문할 메뉴를 입력 : ");
			if (food[i].food != NULL) {
				scanf("%s", food[i].food);
				Enqueue(&front, &rear, food[i].food);
				i++;
			}
			else printf("잘못된 입력입니다.\n");
			break;
		case 2:
			if (front->data == NULL) printf("주문 내역이 없습니다.\n");
			printf("%s 나왔습니다.\n", dequeue(&front, &rear));
			break;
		case 3:

		case 4:
			printf("영업이 종료되었습니다.");
			return 0;

		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
		printf("\n\n\n");
		printf("주문목록 : ");
		printf("\nFRONT - ");
		printQueue(front);
		printf("REAR\n");

	}
	

	return 0;
}