#include<stdio.h>
#include<stdlib.h>
// ex01_orderQueue.c : 문자열을 이용하여 음식 주문 큐를 만들어보기 (문자열 포인터)
typedef struct node {
	char* data;	// 포인터는 주소를 가리킬 뿐, 자체적인 공간을 가지지는 않는다
	struct node* link;
}Queue;
Queue* getNode() {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->link = NULL;
	return newNode;
}
void printQueue(Queue* front) {
	if (front == NULL) {
		printf("\n\t주문이 없습니다\n\n");
		return;
	}
	printf("\n\t[FRONT] - ");
	while (front) {
		printf("%s", front->data);
		printf("%s", (front->link == NULL) ? " - [REAR]\n\n" : " - ");
		front = front->link;
	}
	
}
void enqueue(Queue** front, Queue** rear, char* data) {
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;
	}
	else {
		(*rear)->link = getNode();
		*rear = (*rear)->link;
	}
	(*rear)->data = data;
}
char* dequeue(Queue** front, Queue** rear) {
	char* data = (*front)->data;
	Queue* tmp = *front;
	*front = (*front)->link;
	if (*front == NULL) *rear = NULL;
	free(tmp);		// Queue 공간을 할당 해제
	return data;
}

int main() {
	Queue* front = NULL;
	Queue* rear = NULL;

	int menu;
	char* name = NULL;

	while (1) {
		printQueue(front);
		printf("1. 주문 넣기 (enqueue)\n");
		if (front)	printf("2. %s 주문 완성 (dequeue)\n", front->data);
		else		printf("\n");
		printf("3. 종료\n");
		printf("선택 >>> ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:			// 주문 넣기
			name = (char*)malloc(20);
			printf("주문할 메뉴의 이름을 입력 : ");
			scanf("%s", name);
			enqueue(&front, &rear, name);
			break;

		case 2:			// 가장 먼저 들어간 주문을 출력하기
			if (front == NULL) {
				printf("\n\t대기중인 주문이 없습니다\n\n");
				break;
			}
			name = dequeue(&front, &rear);
			printf("\n\t[%s] 나왔습니다~\n\n", name);
			free(name);		// 구조체가 가지던 문자열 공간을 해제
			break;
		case 3:			// 종료
			return;
		}
		system("pause");
		system("cls");
	}
}
