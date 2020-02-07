//ex01.c 미참조 구현

#include<stdio.h>
#include<stdlib.h>
//단일 연결리스트 만들기(메뉴로 구현)
//일반 삽입, 중간 삽입, 검색, 전체출력, 삭제 구현
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

void insertNode(LinkedList** head, int number)
{
	if ((*head) == NULL)
	{
		(*head) = getNode();
		(*head)->data = number;
	}
	else insertNode(&(*head)->link, number);
}

void printList(LinkedList* head)
{
	printf("[HEAD] - ");
	while (head != NULL)
	{
		printf("%d - ", head->data);
		head = head->link;
	}
	printf("[TAIL]\n");
}

LinkedList* findNode(LinkedList* head, int number)
{
	while (head != NULL)
	{
		if (head->data == number) return head;
		else head = head->link;
	}
	if (head == NULL) return NULL;
}

void insertNode2(LinkedList** head, int data1, int data2)
{
	LinkedList* tmp = getNode();
	LinkedList* find = findNode(*head, data1);
	if (find->data == data1)
	{
		tmp->link = find->link;
		tmp->data = data2;
		find->link = tmp;
	}
	else insertNode(&(*head)->link, data1, data2);
}

void deleteNode(LinkedList** head, int data)
{
	if ((*head) == NULL) return;
	else if ((*head)->data == data)
	{
		LinkedList* tmp = (*head);
		(*head) = tmp->link;
		free(tmp);
	}
	else deleteNode(&(*head)->link, data);
}

int main()
{
	LinkedList* head = NULL;
	LinkedList* find = NULL;
	int menu, number, number2;


	while (1)
	{
		printf("\n\n");
		printList(head);
		printf("\n\n\n");
		printf("단일 연결리스트 프로그램\n");
		printf("1. 일반 삽입\n2. 중간 삽입\n3. 검색\n4. 전체 출력\n5. 삭제\n0. 프로그램 종료\n");
		printf("메뉴 입력 > ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("리스트에 삽입할 숫자를 입력하세요 : ");
			scanf("%d", &number);
			insertNode(&head, number);
			printList(head);
			break;
		case 2 :
			printf("중간에 삽입할 노드를 입력하세요 : ");
			scanf("%d", &number);
			printf("삽입 할 위치의 노드를 입력하세요(입력한 노드의 뒤에 삽입됩니다.) : ");
			scanf("%d", &number2);
			insertNode2(&head, number2, number);
			printList(head);
			break;
		case 3 :
			printf("검색할 노드를 입력하세요 : ");
			scanf("%d", &number);
			find = findNode(head, number);
			if (find != NULL) 
				printf("%d : 데이터를 찾았습니다.\n", find->data);
			else printf("%d : 데이터를 찾을 수 없습니다.\n", number);
			break;
		case 4 : 
			printList(head);
			break;
		case 5 :
			printf("삭제할 노드를 입력하세요 : ");
			scanf("%d", &number);
			deleteNode(&head, number);
			printList(head);
			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
		system("pause");
		system("cls");
	}
}