#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int link;
}Stack;
Stack* getNode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = 0;
	return tmp;
}

void Push(Stack** top, int data) {
	if (*top == 0) {
		*top = getNode();
		(*top)->data = data;
	}
	else {
		Stack* backup = *top;
		*top = getNode();
		(*top)->link = backup;
		(*top)->data = data;
	}
}
int Pop(Stack** top) {
	Stack* tmp = *top;
	int data = tmp->data;
	*top = (*top)->link;
	free(tmp);
	return data;
}

int isNum(char ch) {
	if ('0' <= ch && ch <= '9')
		return 1;
	else return 0;
}

int calc(char* exp) {
	Stack* top = 0;
	int n = 0;

	for (int i = 0; exp[i]; i++) {
		if (isNum(exp[i])) {
			n *= 10;
			n += exp[i] - 48;
		}
		else if (exp[i] == ',') {
			Push(&top, n);
			printf("n : %d\n", n);
			n = 0;
		}
		else {
			int n1, n2;
			switch (exp[i]) {
			case '+':
				n1 = Pop(&top);
				n2 = Pop(&top);
				Push(&top, n1 + n2);
				printf("n : %d\n", n1 + n2);
				break;
			case '-':
				n1 = Pop(&top);
				n2 = Pop(&top);
				Push(&top, n2 - n1);
				printf("n : %d\n", n2 - n1);
				break;
			case '*':
				n1 = Pop(&top);
				n2 = Pop(&top);
				Push(&top, n1 * n2);
				printf("n : %d\n", top->data);
				break;
			case '/':
				n1 = Pop(&top);
				n2 = Pop(&top);
				Push(&top, n2 / n1);
				printf("n : %d\n", n2 / n1);
				break;
			}
		}
	}
	return top->data;
}


int main() {
	//stack
	//피연산자 pop();
	//연산자 +, - stack을 비운후 push()
	//연산자 *, / top()이 *, /이면 pop() 아니면 push()

	//1+2*3-4 > 123*+4-
	//56+7-1*5*
	Stack* top = 0;
	char input[50] = { 0 };
	char exp[50] = { 0 };
	char* e = exp;		//e는 exp의 시작지점을 가리키는 상태에서 시작

	int num = 1;	//숫자 0, 연산자 1 > 숫자 다음 연산자가나오면 . 꺼낼때 .을 기준으로 숫자 구분

	printf("수식을 입력 : ");
	scanf("%s", input);

	// 후위 표기식으로 변경하는 코드
	for (int i = 0; input[i]; i++) {
		printf("%c : %s\n", input[i], isNum(input[i]) ? "숫자" : "숫자가 아님");
		if (isNum(input[i])) {	//정수이면
			*e++ = input[i];	//대입 한 후에 가리키는 칸을 한칸 오른쪽으로 증가
			num = 0;
		}
		else if (input[i] == '(') {
			Push(&top, '!');
			if (num == 0)
				*e++ = ',';
			num = 1;
		}
		else if (input[i] == ')') {
			if (num == 0)
				*e++ = ',';
			num = 1;
			while (top->data != '!') {
				*e++ = Pop(&top);
			}
			Pop(&top);
		}
		else if (input[i] == '+' || input[i] == '-') {
			if (num == 0)
				*e++ = ',';
			num = 1;
			if (top == 0)
				Push(&top, input[i]);
			else {
				for (int j = 0; top; j++) {
					if (top->data == '!')
						break;
					*e++ = Pop(&top);
				}
				Push(&top, input[i]);
			}
		}
		else if (input[i] == '*' || input[i] == '/') {
			if (num == 0)
				*e++ = ',';
			num = 1;
			if (top == 0)
				Push(&top, input[i]);
			else {
				while (top) {
					if (top->data == '+' || top->data == '-') {
						break;
					}
					else if (top->data == '!')
						break;
					else {
						*e++ = Pop(&top);
					}
				}
				Push(&top, input[i]);
			}
		}

	}
	if (num == 0)
		*e++ = ',';
	while (top)
		*e++ = Pop(&top);

	*e = '\0';

	printf("\n후위 표현식 : %s\n", exp);

	printf("\n결과 : %d\n", calc(exp));
}