// ex02.c - ���� Ȱ�� ����
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}Stack;
Stack* getNode() {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
	newNode->link = NULL;
	return newNode;
}
void push(Stack** top, int data) {
	Stack* tmp = *top;
	*top = getNode();
	(*top)->data = data;
	(*top)->link = tmp;
}
int pop(Stack** top) {
	int num = (*top)->data;
	Stack* tmp = *top;
	*top = (*top)->link;
	free(tmp);
	return num;
}
void printStack(Stack* top) {
	printf("\n===== printStack =====\n\n");

	while (top) {
		printf("\t�� %3d ��\n", top->data);
		top = top->link;
	}

	printf("\t��������������\n");
	printf("\n======================\n\n");
}

int main() {
	Stack* top = NULL;
	int perHour, hour, day, pay, i;
	int cnt = 0, cntComma = 0;
	char* result;

	printf("�ð� �� �޿� (��) : ");	scanf("%d", &perHour);
	printf("�� �ٹ� �ð� (��) : ");	scanf("%d", &hour);
	printf("�� �ٹ� ���� (��) : ");	scanf("%d", &day);

	pay = perHour * hour * day;

	while (pay) {					// pay�� 0�� �ƴҶ� ���� �ݺ�
		push(&top, pay % 10 + 48);	// pay�� ������ 1�� �ڸ��� �ƽ�Ű�ڵ�� ��ȯ�ؼ� push
		pay /= 10;					// pay�� �������ڸ��� ���ÿ� �÷�����, �߶�
		cnt++;						// cnt ����
		if (pay == 0) break;		// ���� pay�� 0�̸� ���������� ����(���̻� �޸�����)
		if (cnt % 3 == 0) {			// ���� 3���� ������ ��������
			push(&top, ',');		// �޸��� ���ÿ� �װ�
			cntComma++;				// �޸� ī��Ʈ ����
		}
	}
	cnt += cntComma;				// ���� ī��Ʈ += �޸� ī��Ʈ
	printStack(top);

	result = (char*)malloc(sizeof(cnt + 1));	// +1�� ������ �� ���ڸ� �ֱ� ���ؼ�
	for (i = 0; i < cnt; i++) {
		*(result + i) = pop(&top);	// ��� ���ڿ����ٰ� pop�� ��ȯ���� �߰�
	}
	*(result + i) = '\0';			// �������� �ι��� �߰�
	
	printf("�̹� �� �޿��� %s�� �Դϴ�\n", result);	// ���
 }