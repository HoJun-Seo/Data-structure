//ex01.c ������ ����

#include<stdio.h>
#include<stdlib.h>
//���� ���Ḯ��Ʈ �����(�޴��� ����)
//�Ϲ� ����, �߰� ����, �˻�, ��ü���, ���� ����
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
		printf("���� ���Ḯ��Ʈ ���α׷�\n");
		printf("1. �Ϲ� ����\n2. �߰� ����\n3. �˻�\n4. ��ü ���\n5. ����\n0. ���α׷� ����\n");
		printf("�޴� �Է� > ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("����Ʈ�� ������ ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &number);
			insertNode(&head, number);
			printList(head);
			break;
		case 2 :
			printf("�߰��� ������ ��带 �Է��ϼ��� : ");
			scanf("%d", &number);
			printf("���� �� ��ġ�� ��带 �Է��ϼ���(�Է��� ����� �ڿ� ���Ե˴ϴ�.) : ");
			scanf("%d", &number2);
			insertNode2(&head, number2, number);
			printList(head);
			break;
		case 3 :
			printf("�˻��� ��带 �Է��ϼ��� : ");
			scanf("%d", &number);
			find = findNode(head, number);
			if (find != NULL) 
				printf("%d : �����͸� ã�ҽ��ϴ�.\n", find->data);
			else printf("%d : �����͸� ã�� �� �����ϴ�.\n", number);
			break;
		case 4 : 
			printList(head);
			break;
		case 5 :
			printf("������ ��带 �Է��ϼ��� : ");
			scanf("%d", &number);
			deleteNode(&head, number);
			printList(head);
			break;
		case 0:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		system("pause");
		system("cls");
	}
}