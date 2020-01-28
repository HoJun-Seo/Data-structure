// ex02_stack.c
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}Stack;
Stack* getNode() {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
							// 6. ����ü ���� �� �ּҸ� newNode�� ����
	newNode->link = NULL;	// 7. �ű� ����ü�� link�� NULL�� ����
	return newNode;			// 8. �ű� ����ü�� �ּҸ� ��ȯ
}
void push(Stack** top, int data) {	// 3. �Ű������� ���� ����Ǹ�, ���� ���ڰ��� �޴´�
	Stack* tmp = *top;		// 4. main()�� top�� ���� �����ϴ� tmp ����(���)
	*top = getNode();		// 5. main()�� top���� getNode()�� ��ȯ���� ����(ȣ��)
								// 8. �ű� ����ü�� �ּҸ� main()�� top���� ����
	(*top)->data = data;		// 9. main()�� top�� ����Ű�� data�� �Ű����� data ����
	(*top)->link = tmp;			// 10. main()�� top�� ����Ű�� link�� ���� top ���� ����
}								// (�ű� ��� ���� top���� �ű� ��尡 ����Ű�� �Ѵ�)
int pop(Stack** top) {
	Stack* tmp = *top;
	int num = (*top)->data;
	*top = (*top)->link;	// �º��� �캯�� ���� ������ �־, �캯�� ���� ����ȴ�
	free(tmp);
	return num;
}
int main() {
	Stack* top = NULL;	// 1. top ������ ���� ���� �� NULL�� �ʱ�ȭ
	
	push(&top, 10);		// 2. 10�� �Է��ϴ� push() ȣ��
	push(&top, 20);
	push(&top, 30);

	printf("%d - %d - %d\n",
		(*top).data, top->link->data, top->link->link->data);

	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
	
}