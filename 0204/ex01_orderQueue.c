#include<stdio.h>
#include<stdlib.h>
// ex01_orderQueue.c : ���ڿ��� �̿��Ͽ� ���� �ֹ� ť�� ������ (���ڿ� ������)
typedef struct node {
	char* data;	// �����ʹ� �ּҸ� ����ų ��, ��ü���� ������ �������� �ʴ´�
	struct node* link;
}Queue;
Queue* getNode() {
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->link = NULL;
	return newNode;
}
void printQueue(Queue* front) {
	if (front == NULL) {
		printf("\n\t�ֹ��� �����ϴ�\n\n");
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
	free(tmp);		// Queue ������ �Ҵ� ����
	return data;
}

int main() {
	Queue* front = NULL;
	Queue* rear = NULL;

	int menu;
	char* name = NULL;

	while (1) {
		printQueue(front);
		printf("1. �ֹ� �ֱ� (enqueue)\n");
		if (front)	printf("2. %s �ֹ� �ϼ� (dequeue)\n", front->data);
		else		printf("\n");
		printf("3. ����\n");
		printf("���� >>> ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:			// �ֹ� �ֱ�
			name = (char*)malloc(20);
			printf("�ֹ��� �޴��� �̸��� �Է� : ");
			scanf("%s", name);
			enqueue(&front, &rear, name);
			break;

		case 2:			// ���� ���� �� �ֹ��� ����ϱ�
			if (front == NULL) {
				printf("\n\t������� �ֹ��� �����ϴ�\n\n");
				break;
			}
			name = dequeue(&front, &rear);
			printf("\n\t[%s] ���Խ��ϴ�~\n\n", name);
			free(name);		// ����ü�� ������ ���ڿ� ������ ����
			break;
		case 3:			// ����
			return;
		}
		system("pause");
		system("cls");
	}
}
