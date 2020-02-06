#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}LinkedList;

// ���� ���� ����Ʈ�� �����ϼ���
// �Ϲ� ����, �߰� ����, ��� �˻�, ����Ʈ ��ü ��� ����

LinkedList* getNode() {
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->link = NULL;
	return newNode;
}
void insertNode(LinkedList** head, int data) {
	if (*head == NULL) {	// ����Ʈ�� ������� ���
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
		// ���� �����ͷ� �޾����� 
		// (���� �����͸� ���� �����ͷ� �޾�����)
		// ( Call By Value )
		// head�� ���� ������� �ٲپ
		// main()�� head�� ���� ������ ����
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
		newNode->data = data;		// �űԳ���� data �Է�
		newNode->link = tmp->link;	// �űԳ���� link �Է�
		tmp->link = newNode;		// ���� �űԳ�带 ����ų ���ΰ�
	}
}
void insertNode3(LinkedList** head, int find, int data) {
	// 1. *head �� NULL�̸� ����
	if (*head == NULL) return;
	else if ((*head)->data == find) {
		LinkedList* newNode = getNode();
		newNode->data = data;
		newNode->link = (*head)->link;
		(*head)->link = newNode;
	}
	else
		insertNode3(&(*head)->link, find, data);

	// 2. (*head)->data == find : �ű� ��� ���� �� ��ġ
		// newNode = getNode();
		// newNode->data = data;
		// newNode->link = (*head)->link
		// (*head)->link = newNode;

	// 3. �ƴϸ�, (*head)->link�� �ּҸ� head�� �� ó�� ���ȣ��
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

	// while, switch ~ case�� �̿��Ͽ� �޴����·� �����ϼ���
	while (1) {
		if (head == 0) {
			printf("\n\n\n");
		}
		printList(head);
		printf("1. �Ϲ� ������ ����\n");
		printf("2. �߰� ������ ����\n");
		printf("3. ��� �˻�\n");
		printf("4. ��� ����\n");
		printf("0. ����\n");
		printf("�޴� �Է� >>> ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:	// �Ϲ� ������ ����
			printf("�Ϲ� ���� ������ �Է� : ");
			scanf("%d", &data);
			insertNode(&head, data);
			break;

		case 2:	// �߰� ������ ����
			printf("�߰� ���� ������ �Է� : ");
			scanf("%d", &data);
			printf("��� ������ �ڿ� �����ұ� : ");
			scanf("%d", &find);
			insertNode3(&head, find, data);
			break;

		case 3:	// ��� �˻�
			printf("�˻��� ������ �Է� : ");
			scanf("%d", &data);
			node = findNode(head, data);
			if (node != NULL)
				printf("%d : ����Ʈ���� ã�ҽ��ϴ�\n", node->data);
			else
				printf("%d : ����Ʈ���� ã�� �� �����ϴ�\n", data);
			break;

		case 4:
			printf("������ ������ �Է� : ");
			scanf("%d", &data);
			deleteNode(&head, data);
			break;
		case 5:
			break;
		case 0:
			printf("���α׷��� �����մϴ�\n");
			return;
		}
		system("pause");
		system("cls");
	}
}