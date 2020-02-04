#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// ex02_orderQueue.c : ���ڿ��� �迭�� ó���ϴ� ť
// �迭�� �ű� �� �����Ƿ�, strcpy �Լ��� �̿��Ѵ�
typedef struct node {
	char data[20];		// �迭�� ��ü������ ������ ������ ����
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
void enqueue(Queue** front, Queue** rear, char* name) {
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;
	}
	else {
		(*rear)->link = getNode();
		*rear = (*rear)->link;
	}
//	(*rear)->data = name;	// (*rear)->data �� �ڷ����� �迭�̹Ƿ�, ���� �Ұ�
	
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
	return name; // (�迭�� �ּҰ� ��ȯ�Ǿ, ���������� �Ҹ��ϴϱ� ���� ���� ��)
				 // �ƴϳ׿� ����������
				 // ��ȯ���� ��ٷ� strcpy�� ���� ����ǰ�
				 // strcpy�� ������ ������, ���� �Ҹ�
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
		printf("1. �ֹ� �Է� (enqueue) \n");
		printf("2. �ֹ� ó�� (dequeue) \n");
		printf("3. ����\n");
		printf("���� >>> ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1: 
			printf("�ֹ��� �޴��� �̸� �Է� : ");
			scanf("%s", name);
			enqueue(&front, &rear, name);
			break;
		case 2:
			if (front == NULL) {
				printf("�ֹ��� �����ϴ� !!\n");
				break;
			}
			// �۵��ϴ� �ڵ�
			// strcpy(name, dequeue(&front, &rear));	// ���ٿ��� ó���ϸ� ����

			// �׽�Ʈ (�۵���)
			tmp = dequeue(&front, &rear);	
			
			// �̰� �ּ� Ǯ�� �����Ⱚ�� �����
			// printf("tmp : %s\n", tmp);

			strcpy(name, tmp);	// tmp�� ������ name�� ����
			// printf("tmp : %s\n", tmp);		// ���⼭ ����ϸ� �����Ⱚ

			// �Ǵ� ���
			printf("dequeue : %s\n", name);
			
			// �ȵǴ� ���
			// printf("dequeue : %s\n", tmp);	// ��ȯ���� ��ٷ� �޾Ƽ� ����ϸ� �ȵ�

			break;
		case 3:
			return;
		}
		system("pause");
		system("cls");






	}
}