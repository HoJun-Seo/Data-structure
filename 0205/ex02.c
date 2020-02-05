// ex01.c - LinkedList
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}LinkedList;
LinkedList* getNode() {
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->link = NULL;
	return newNode;
}
void insertNode(LinkedList** head, int data) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = data;
	}
	else
		insertNode(&(*head)->link, data);
}
void printList(LinkedList* head) {
	printf("[HEAD] - ");
	while (head) {
		printf("%d", head->data);
		printf("%s", (head->link) ? " - " : "\n\n");
		head = head->link;
	}
}

LinkedList* findNode(LinkedList* head, int data) {
	while (head) {
		if (head->data == data)
			return head;

		head = head->link;
	}
	return NULL;
}

void insertNode2(LinkedList** head, int find, int data) {
	// 직접 제어하기 (findNode 안쓰기)
	/*if (*head == NULL)
		return;

	else if ((*head)->data == find) {
		LinkedList* newNode = getNode();
		newNode->data = data;
		newNode->link = (*head)->link;
		(*head)->link = newNode;
	}
	else
		insertNode2(&(*head)->link, find, data);
		*/

	// findNode 사용하기
	
	LinkedList* tmp = findNode(*head, find);
	LinkedList* newNode = getNode();
	if (tmp != NULL) {
		newNode->data = data;
		newNode->link = tmp->link;
		tmp->link = newNode;
	}
	
}

int main() {
	LinkedList* head = NULL;

	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);

	//	printf("%d - %d - %d\n",
	//		head->data, head->link->data, head->link->link->data);

	insertNode(&head, 40);
	insertNode(&head, 50);

	printList(head);		// head부터 끝까지 출력하는 함수

	LinkedList* find;

	find = findNode(head, 20);
	if (find != NULL)	printf("%d : 데이터를 찾았습니다\n", find->data);
	else				printf("데이터를 찾을 수 없습니다\n");

	find = findNode(head, 17);
	if (find != NULL)	printf("%d : 데이터를 찾았습니다\n", find->data);
	else				printf("데이터를 찾을 수 없습니다\n");

	insertNode2(&head, 10, 15);
	// 10 다음에 15를 삽입하세요 (중간삽입)
	// 10 - 15 - 20 - 30 - 40 - 50
	insertNode2(&head, 30, 35);
	// 10 - 15 - 20 - 30 - 35 - 40 - 50
	insertNode2(&head, 24, 35);

	printList(head);

}