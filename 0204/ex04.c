#include<stdio.h>
#include<stdlib.h>
int i = 0;
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
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = data;
	}
	else {
		insertNode(&(*head)->link, data);
	}
}

int main()
{
	LinkedList* head = NULL;

	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);

	printf("%d - %d - %d\n", head->data, head->link->data, head->link->link->data);
}