#include<stdio.h>
#include<stdlib.h>
//tree �⺻ - insertNode ����
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Tree;

Tree* getNode()
{
	Tree* newNode = (Tree*)malloc(sizeof(Tree));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insertNode(Tree** root, int data)
{
	if (*root == NULL)
	{//*root �� ����� ���
		*root = getNode();
		(*root)->data = data;
	}
	//*root�� ���� ���� ���
	else if ((*root)->data > data)
	{//������ �������� ��� �Լ� ����
		insertNode(&(*root)->left, data);
	}
	else //if ((*root)->data < data)
	{//ũ�� ���������� ��� �Լ� ����
		insertNode(&(*root)->right, data);
	}
	//���� ���� ���� �������� �ʴ´�.(�ߺ� ���x)
}

void preOrder(Tree* root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Tree* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(Tree* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int main()
{
	Tree* root = NULL;
	//���� ������ ����, ���� ũ�� ������(ũ�� ��)

	insertNode(&root, 10);
	insertNode(&root, 20);
	insertNode(&root, 5);
	insertNode(&root, 15);

	printf("preOrder : "); preOrder(root); printf("\n");
	printf("inOrder : "); inOrder(root); printf("\n");
	printf("postOrder : "); postOrder(root); printf("\n");

	
}