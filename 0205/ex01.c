//ex01.c - LinkedList
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}LinkedList;

LinkedList* getNode()
{
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->link = NULL;
	return newNode;
}

void insertNode(LinkedList** head, int data)
{
	if ((*head) == NULL)
	{
		(*head) = getNode();
		(*head)->data = data;
	}
	else {
		insertNode(&(*head)->link, data); //link를 head인 것처럼 전달(link는 NULL 인 상태이다.)
	}
}

void printList(LinkedList* head)
{
	while (head != NULL)
	{
		printf("LinkedList print : %d\n", head->data);
		head = head->link;
	}
}

LinkedList* findNode(LinkedList* head, int data)
{
	while (head) {
		if (head->data == data)
			return head;
		else head = head->link;
	}
	return NULL;
}

void insertNode2(LinkedList** head, int data1, int data2)
{
	/*while ((*head) != NULL)
	{
		if ((*head)->data == data1) {
			LinkedList* tmp1 = (*head)->link;
			LinkedList* tmp = getNode();
			(*head)->link = tmp;
			tmp->data = data2;
			tmp->link = tmp1;
			break;
		}
		else (*head) = (*head)->link;
	}*/

	LinkedList* tmp = findNode(*head, data1);
	LinkedList* tmp1 = getNode();
	if (tmp != NULL)
	{
		tmp1->data = data2;
		tmp1->link = tmp->link;
		tmp->link = tmp1;
	}
}

int main()
{
	LinkedList* head = NULL;
	LinkedList* find = NULL;

	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);

	printf("%d - %d - %d\n", head->data, head->link->data, head->link->link->data);

	insertNode(&head, 40);
	insertNode(&head, 50);

	printList(head);

	find = findNode(head, 20); //20 : 데이터를 찾았습니다.
	if (find != NULL) printf("%d : 데이터를 찾았습니다.\n", find->data);
	else printf("데이터를 찾지 못했습니다.\n");
	find = findNode(head, 17); //17 : 데이터를 찾을 수 없습니다.
	if (find != NULL) printf("%d : 데이터를 찾았습니다.\n", find->data);
	else printf("데이터를 찾지 못했습니다.\n");

	printf("\n\n");
	insertNode2(&head, 10, 15);
	printList(head);
	//10 다음에 15를 삽입(중간삽입)
	//10 - 15 - 20 - 30 - 40 - 50
	printf("\n\n");
	
	insertNode2(&head, 30, 35);
	insertNode2(&head, 24, 35);
	printList(head);
	//10 - 15 - 20 - 30 - 35 - 40 - 50
}