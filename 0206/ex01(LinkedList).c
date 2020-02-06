#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}LinkedList;
//단일 연결리스트 구현
//일반 삽입, 중간삽입, 노드 검색, 리스트 전체 출력 까지

LinkedList* getNode()
{
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->link = NULL;
	return newNode;
}

void insertNode(LinkedList** head, int data)//이중 포인터 전달 - main함수의 head까지 변경됨(노드의 변경이 있을 경우(삽입, 삭제 등))
{
	if ((*head) == NULL) //리스트가 비어있을 경우
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

LinkedList* findNode(LinkedList* head, int data) //단일 포인터 전달 - 내용 변경 없이 리스트를 순회하는 용도로만 사용됨(main함수의 head와는 상관없음)
{
	while(head != NULL)
	{
		if (head->data == data)
			return head; //head 주소 반환
		else head = head->link;
		//단일 포인터로 받았으니, head의 값을 마음대로 바꾸어도 main() 의 head는 값의 변경이 없다.
		//단일 포인터를 단일 포인터로 받았으니 (call by value) 방식이다.
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
	else printf("%d : 데이터를 찾을 수 없습니다.\n", data1);
}*/ //findNode 를 활용한 중간삽입

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
	//while,switch ~ case 를 이용하여 메뉴형태로 구현하세요(종료메뉴 0번 세팅)

	int menu, number, number2;
	

	while (1)
	{
		printf("연결리스트 프로그램\n");
		printf("1. 일반 삽입\n2. 중간삽입\n3. 노드 검색\n4. 노드 삭제\n5. 전체 출력\n0. 프로그램 종료\n");
		printf("메뉴를 선택하세요 > ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1 :
			printf("연결리스트에 삽입할 숫자 입력 : ");
			scanf("%d", &number);
			insertNode(&head, number);
			printList(head);
			break;
		case 2 :
			printf("연결리스트에 중간 삽입할 숫자 입력 : ");
			scanf("%d", &number);
			printf("해당 숫자를 어디에 삽입 하시겠습니까?(숫자의 뒤에 삽입됩니다.) : ");
			scanf("%d", &number2);
			insertNode3(&head, number2, number);
			printList(head);
			break;
		case 3 :
			printf("검색할 리스트 상의 숫자 입력 : ");
			scanf("%d", &number);
			find = findNode(head, number);
			if (find != NULL)
				printf("%d : 데이터를 찾았습니다.\n", find->data);
			else printf("%d : 데이터를 찾지 못했습니다.\n", number);
			break;
		case 4 :
			printList(head);
			printf("노드에서 삭제할 숫자를 입력하세요 : ");
			scanf("%d", &number);
			deleteNode(&head, number);
			break;
		case 5 :
			printList(head);
			break;
		case 0 :
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
		system("pause");
		system("cls");

	}
}