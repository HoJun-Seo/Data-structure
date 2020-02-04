#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ex02_orderQueue.c : 문자열을 배열로 처리하는 큐
// 배열을 옮길 수 없으므로, strcpy 함수를 이용한다
typedef struct node {
	char data[20];		// 배열은 자체적으로 공간을 가지는 형태
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
void enqueue(Queue** front, Queue** rear, char* name) {
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;
	}
	else {
		(*rear)->link = getNode();
		*rear = (*rear)->link;
	}
//	(*rear)->data = name;	// (*rear)->data 의 자료형이 배열이므로, 대입 불가
	
	strcpy((*rear)->data, name);
	// memcpy(dst, src, size);
}
char* dequeue(Queue** front, Queue** rear) {
	char name[20];
	strcpy(name, (*front)->data);
	Queue* tmp = *front;
	*front = (*front)->link;
	if (*front == NULL) *rear = NULL;
	free(tmp);
	return name; // (배열의 주소가 반환되어도, 지역변수는 소멸하니까 값이 없을 듯)
				 // 아니네여 ㅋㅋㅋㅋㅋ
				 // 반환값이 곧바로 strcpy에 의해 복사되고
				 // strcpy의 수행이 끝나면, 영역 소멸
}
int main() {
	Queue* front = NULL;
	Queue* rear = NULL;

	int menu;
//	char* name;
	char name[20];
	char* tmp;
	while (1) {
		printQueue(front);
		printf("1. 주문 입력 (enqueue) \n");
		printf("2. 주문 처리 (dequeue) \n");
		printf("3. 종료\n");
		printf("선택 >>> ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1: 
			printf("주문할 메뉴의 이름 입력 : ");
			scanf("%s", name);
			enqueue(&front, &rear, name);
			break;
		case 2:
			if (front == NULL) {
				printf("주문이 없습니다 !!\n");
				break;
			}
			// 작동하는 코드
			// strcpy(name, dequeue(&front, &rear));	// 한줄에서 처리하면 가능

			// 테스트 (작동함)
			tmp = dequeue(&front, &rear);	
			
			// 이거 주석 풀면 쓰레기값이 복사됨
			// printf("tmp : %s\n", tmp);

			strcpy(name, tmp);	// tmp의 내용을 name에 복사
			// printf("tmp : %s\n", tmp);		// 여기서 출력하면 쓰레기값

			// 되는 출력
			printf("dequeue : %s\n", name);
			
			// 안되는 출력
			// printf("dequeue : %s\n", tmp);	// 반환값을 곧바로 받아서 출력하면 안됨

			break;
		case 3:
			return;
		}
		system("pause");
		system("cls");






	}
}