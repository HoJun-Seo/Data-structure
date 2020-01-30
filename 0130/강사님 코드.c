// ex02.c - 스택 활용 문제
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
		printf("\t│ %3d │\n", top->data);
		top = top->link;
	}

	printf("\t└─────┘\n");
	printf("\n======================\n\n");
}

int main() {
	Stack* top = NULL;
	int perHour, hour, day, pay, i;
	int cnt = 0, cntComma = 0;
	char* result;

	printf("시간 당 급여 (원) : ");	scanf("%d", &perHour);
	printf("일 근무 시간 (시) : ");	scanf("%d", &hour);
	printf("월 근무 일자 (일) : ");	scanf("%d", &day);

	pay = perHour * hour * day;

	while (pay) {					// pay가 0이 아닐때 까지 반복
		push(&top, pay % 10 + 48);	// pay의 마지막 1의 자리를 아스키코드로 변환해서 push
		pay /= 10;					// pay의 마지막자리는 스택에 올렸으니, 잘라냄
		cnt++;						// cnt 증가
		if (pay == 0) break;		// 만약 pay가 0이면 현시점에서 종료(더이상 콤마없음)
		if (cnt % 3 == 0) {			// 만약 3으로 나누어 떨어지면
			push(&top, ',');		// 콤마를 스택에 쌓고
			cntComma++;				// 콤마 카운트 증가
		}
	}
	cnt += cntComma;				// 숫자 카운트 += 콤마 카운트
	printStack(top);

	result = (char*)malloc(sizeof(cnt + 1));	// +1은 마지막 널 문자를 넣기 위해서
	for (i = 0; i < cnt; i++) {
		*(result + i) = pop(&top);	// 결과 문자열에다가 pop의 반환값을 추가
	}
	*(result + i) = '\0';			// 마지막에 널문자 추가
	
	printf("이번 달 급여는 %s원 입니다\n", result);	// 출력
 }