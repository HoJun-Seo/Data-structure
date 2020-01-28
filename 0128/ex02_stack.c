// ex02_stack.c
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}Stack;
Stack* getNode() {
	Stack* newNode = (Stack*)malloc(sizeof(Stack));
							// 6. 구조체 생성 및 주소를 newNode에 저장
	newNode->link = NULL;	// 7. 신규 구조체의 link에 NULL을 대입
	return newNode;			// 8. 신규 구조체의 주소를 반환
}
void push(Stack** top, int data) {	// 3. 매개변수는 먼저 선언되며, 값은 인자값을 받는다
	Stack* tmp = *top;		// 4. main()의 top의 값을 저장하는 tmp 생성(백업)
	*top = getNode();		// 5. main()의 top에게 getNode()의 반환값을 대입(호출)
								// 8. 신규 구조체의 주소를 main()의 top에게 전달
	(*top)->data = data;		// 9. main()의 top이 가리키는 data에 매개변수 data 대입
	(*top)->link = tmp;			// 10. main()의 top이 가리키는 link에 이전 top 값을 대입
}								// (신규 노드 이전 top값을 신규 노드가 가리키게 한다)
int pop(Stack** top) {
	Stack* tmp = *top;
	int num = (*top)->data;
	*top = (*top)->link;	// 좌변과 우변에 같은 변수가 있어도, 우변이 먼저 수행된다
	free(tmp);
	return num;
}
int main() {
	Stack* top = NULL;	// 1. top 포인터 변수 생성 및 NULL로 초기화
	
	push(&top, 10);		// 2. 10을 입력하는 push() 호출
	push(&top, 20);
	push(&top, 30);

	printf("%d - %d - %d\n",
		(*top).data, top->link->data, top->link->link->data);

	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
	printf("pop : %d\n", pop(&top));
	
}