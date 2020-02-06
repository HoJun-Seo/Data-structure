#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}LinkedList;

// 단일 연결 리스트를 구현하세요
// 일반 삽입, 중간 삽입, 노드 검색, 리스트 전체 출력 까지

LinkedList* getNode() {
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->link = NULL;
	return newNode;
}
void insertNode(LinkedList** head, int data) {
	if (*head == NULL) {	// 리스트가 비어있을 경우
		*head = getNode();
		(*head)->data = data;
	}
	else
		insertNode(&(*head)->link, data);
}

LinkedList* findNode(LinkedList* head, int data) {
	while (head) {
		if (head->data == data) {
			return head;
		}
		head = head->link;
		// 단일 포인터로 받았으니 
		// (단일 포인터를 단일 포인터로 받았으니)
		// ( Call By Value )
		// head의 값을 마음대로 바꾸어도
		// main()의 head는 값의 변경이 없다
	}
	return NULL;
}

void printList(LinkedList* head) {
	if (head == 0)
		return;
	printf("\n\t[HEAD] - ");
	while (head) {
		printf("%d", head->data);
		printf("%s", head->link ? " - " : "");
		head = head->link;
	}
	printf("\n\n");
}

void insertNode2(LinkedList** head, int find, int data) {
	LinkedList* tmp = findNode(*head, find);
	LinkedList* newNode = getNode();
	if (tmp != NULL) {
		newNode->data = data;		// 신규노드의 data 입력
		newNode->link = tmp->link;	// 신규노드의 link 입력
		tmp->link = newNode;		// 누가 신규노드를 가리킬 것인가
	}
}
void insertNode3(LinkedList** head, int find, int data) {
	// 1. *head 가 NULL이면 종료
	if (*head == NULL) return;
	else if ((*head)->data == find) {
		LinkedList* newNode = getNode();
		newNode->data = data;
		newNode->link = (*head)->link;
		(*head)->link = newNode;
	}
	else
		insertNode3(&(*head)->link, find, data);

	// 2. (*head)->data == find : 신규 노드 생성 및 배치
		// newNode = getNode();
		// newNode->data = data;
		// newNode->link = (*head)->link
		// (*head)->link = newNode;

	// 3. 아니면, (*head)->link의 주소를 head인 것 처럼 재귀호출
}


void deleteNode(LinkedList** head, int data) {
	if (*head == NULL)
		return;
	else if ((*head)->data == data) {
		LinkedList* tmp = *head;
		*head = tmp->link;
		free(tmp);
	}
	else
		deleteNode(&(*head)->link, data);
}
int main() {
	LinkedList* head = NULL;
	LinkedList* node;
	int menu, data, find;

	// while, switch ~ case를 이용하여 메뉴형태로 구현하세요
	while (1) {
		if (head == 0) {
			printf("\n\n\n");
		}
		printList(head);
		printf("1. 일반 데이터 삽입\n");
		printf("2. 중간 데이터 삽입\n");
		printf("3. 노드 검색\n");
		printf("4. 노드 삭제\n");
		printf("0. 종료\n");
		printf("메뉴 입력 >>> ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:	// 일반 데이터 삽입
			printf("일반 삽입 데이터 입력 : ");
			scanf("%d", &data);
			insertNode(&head, data);
			break;

		case 2:	// 중간 데이터 삽입
			printf("중간 삽입 데이터 입력 : ");
			scanf("%d", &data);
			printf("어느 데이터 뒤에 삽입할까 : ");
			scanf("%d", &find);
			insertNode3(&head, find, data);
			break;

		case 3:	// 노드 검색
			printf("검색할 데이터 입력 : ");
			scanf("%d", &data);
			node = findNode(head, data);
			if (node != NULL)
				printf("%d : 리스트에서 찾았습니다\n", node->data);
			else
				printf("%d : 리스트에서 찾을 수 없습니다\n", data);
			break;

		case 4:
			printf("삭제할 데이터 입력 : ");
			scanf("%d", &data);
			deleteNode(&head, data);
			break;
		case 5:
			break;
		case 0:
			printf("프로그램을 종료합니다\n");
			return;
		}
		system("pause");
		system("cls");
	}
}