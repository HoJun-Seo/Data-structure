#include<stdio.h>
#include<stdlib.h>
//ex01_expTree.c
typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}ExpTree;
ExpTree* getNode() {
	ExpTree* newNode = (ExpTree*)malloc(sizeof(ExpTree));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void push(ExpTree** top, int data) {
	ExpTree* tmp = *top;
	*top = getNode();
	(*top)->data = data;
	(*top)->left = tmp;
}
int pop(ExpTree** top) {
	int data = (*top)->data;
	ExpTree* tmp = *top;
	*top = (*top)->left;
	free(tmp);
	return data;
}
int getPriority(char ch) {
	switch (ch) {
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	default: return -1;
	}
}

void getPostfix(char* infix, char* p)
{
	ExpTree* top = NULL;
	for (int i = 0; infix[i] != '\0'; i++) {
		// printf("%c ", infix[i]);

		if ('0' <= infix[i] && infix[i] <= '9') {
			*p++ = infix[i];
		}
		else {
			if (top != NULL && infix[i] != '(' && infix[i] != ')') {

				int ExpTreePri = getPriority(top->data);
				int inputPri = getPriority(infix[i]);
				if (ExpTreePri >= inputPri) {
					while (top != NULL && top->data != '(' && top->data != ')')
						*p++ = pop(&top);
				}
			}

			push(&top, infix[i]);

			if (infix[i] == ')') {
				pop(&top);
				while (top->data != '(') {
					*p++ = pop(&top);
				}
				pop(&top);
			}
		}
	}
	while (top != NULL) {
		*p++ = pop(&top);
	}
	*p++ = '\0';
}

void inOrder(ExpTree* root) //left->root->right
{
	if (root)
	{
		inOrder(root->left);
		printf("%c ", root->data);
		inOrder(root->right);
	}
}

int calcExpTree(ExpTree* root)
{
	int n1, n2;
	if (root)
	{
		if (root->left) n1 = calcExpTree(root->left);
		if (root->right) n2 = calcExpTree(root->right);
		switch (root->data)
		{
		case '+':
			return(n1 + n2);
		case '-':
			return(n1 - n2);
		case '*':
			return(n1 * n2);
		case '/':
			return(n1 / n2);
		default:
			return root->data - 48;
		}
	}
		//�� ���� ������ ������ �����ϰ�
		//left -> right -> root (postOrder)�� �������
		//left->data �� n1
		//right->data �� n2
		//root->data �� ������
		//�����ڿ� ���� ���� ���ϰ� ��ȯ�ϴ� ����Լ��� �ۼ�
}

int main() {
	ExpTree* top = NULL;

	char infix[100];
	char postfix[100] = { 0 };
	char* p = postfix;

	printf("���� ǥ��� �Է� : ");
	scanf("%s", infix);

	getPostfix(infix, postfix);
	//infix�� ������ �����Ͽ�, ���� ǥ����� postfix �迭�� �Է��ϴ� �Լ�

	printf("postfix : %s\n", postfix);

	printf("\n\n");

	ExpTree* root = NULL;

	for (int i = 0; postfix[i]; i++) //���� ǥ����� �������� ����Ѵ�.
	{								 //���� ���ڸ� ���ÿ� �����Ѵ�. 
		if ('0' <= postfix[i] && postfix[i] <= '9')
		{
			push(&root, postfix[i]);
		}
		else { //���ڰ� �ƴϸ�(�������̸�)
			push(&root, postfix[i]); //�����ڸ� push�� ����
			if ('0' <= root->left->data && root->left->data <= '9') //�������� ������ �����̸�
			{
				root->right = root->left;
				root->left = root->left->left;
				root->right->left = NULL;
			}
		}
	}

	inOrder(root);

	printf("\n%s = %d\n", infix, calcExpTree(root));
}