#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}LinkedList;
//���� ���Ḯ��Ʈ ����
//�Ϲ� ����, �߰�����, ��� �˻�, ����Ʈ ��ü ��� ����

LinkedList* getNode()
{
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->link = NULL;
	return newNode;
}

void insertNode(LinkedList** head, int data)//���� ������ ���� - main�Լ��� head���� �����(����� ������ ���� ���(����, ���� ��))
{
	if ((*head) == NULL) //����Ʈ�� ������� ���
	{
		(*head) = getNode();
		(*head)->data = data;
	}
	else insertNode(&(*head)->link, data);
}

void printList(LinkedList* head)
{
	while (head != NULL)
	{
		printf("LinkedList : %d\n", head->data);
		head = head->link;
	}
}

LinkedList* findNode(LinkedList* head, int data) //���� ������ ���� - ���� ���� ���� ����Ʈ�� ��ȸ�ϴ� �뵵�θ� ����(main�Լ��� head�ʹ� �������)
{
	while(head != NULL)
	{
		if (head->data == data)
			return head; //head �ּ� ��ȯ
		else head = head->link;
		//���� �����ͷ� �޾�����, head�� ���� ������� �ٲپ main() �� head�� ���� ������ ����.
		//���� �����͸� ���� �����ͷ� �޾����� (call by value) ����̴�.
	}
	if (head == NULL)
		return NULL;
}

/*void insertNode2(LinkedList** head, int data1, int data2)
{
	LinkedList* tmp = getNode();
	LinkedList* find = findNode(*head, data1);
	if (find->data == data1)
	{
		tmp->data = data2;
		tmp->link = find->link;
		find->link = tmp;
	}
	else printf("%d : �����͸� ã�� �� �����ϴ�.\n", data1);
}*/ //findNode �� Ȱ���� �߰�����

void insertNode3(LinkedList** head, int data1, int data2)
{
	LinkedList* tmp = getNode();
	if (*head == NULL) return;
	else if ((*head)->data == data1)
	{
		tmp->data = data2;
		tmp->link = (*head)->link;
		(*head)->link = tmp;
	}
	else insertNode3(&(*head)->link, data1, data2);
}

void deleteNode(LinkedList** head, int data)
{
	if (*head == NULL) return;
	else if ((*head)->data == data)
	{
		LinkedList* tmp = *head;
		*head = tmp->link;
		free(tmp);
	}
	else deleteNode(&(*head)->link, data);
}

int main()
{
	LinkedList* head = NULL;
	LinkedList* find = NULL;
	//while,switch ~ case �� �̿��Ͽ� �޴����·� �����ϼ���(����޴� 0�� ����)

	int menu, number, number2;
	

	while (1)
	{
		printf("���Ḯ��Ʈ ���α׷�\n");
		printf("1. �Ϲ� ����\n2. �߰�����\n3. ��� �˻�\n4. ��� ����\n5. ��ü ���\n0. ���α׷� ����\n");
		printf("�޴��� �����ϼ��� > ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1 :
			printf("���Ḯ��Ʈ�� ������ ���� �Է� : ");
			scanf("%d", &number);
			insertNode(&head, number);
			printList(head);
			break;
		case 2 :
			printf("���Ḯ��Ʈ�� �߰� ������ ���� �Է� : ");
			scanf("%d", &number);
			printf("�ش� ���ڸ� ��� ���� �Ͻðڽ��ϱ�?(������ �ڿ� ���Ե˴ϴ�.) : ");
			scanf("%d", &number2);
			insertNode3(&head, number2, number);
			printList(head);
			break;
		case 3 :
			printf("�˻��� ����Ʈ ���� ���� �Է� : ");
			scanf("%d", &number);
			find = findNode(head, number);
			if (find != NULL)
				printf("%d : �����͸� ã�ҽ��ϴ�.\n", find->data);
			else printf("%d : �����͸� ã�� ���߽��ϴ�.\n", number);
			break;
		case 4 :
			printList(head);
			printf("��忡�� ������ ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &number);
			deleteNode(&head, number);
			break;
		case 5 :
			printList(head);
			break;
		case 0 :
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
		system("pause");
		system("cls");

	}
}