#include<stdio.h>
#include<stdlib.h>
//tree 기본 - insertNode 구현
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
	{//*root 가 비었을 경우
		*root = getNode();
		(*root)->data = data;
	}
	//*root가 값이 있을 경우
	else if ((*root)->data > data)
	{//작으면 왼쪽으로 재귀 함수 진행
		insertNode(&(*root)->left, data);
	}
	else //if ((*root)->data < data)
	{//크면 오른쪽으로 재귀 함수 진행
		insertNode(&(*root)->right, data);
	}
	//값이 같을 경우는 가정하지 않는다.(중복 허용x)
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
	//값이 작으면 왼쪽, 값이 크면 오른쪽(크기 비교)

	insertNode(&root, 10);
	insertNode(&root, 20);
	insertNode(&root, 5);
	insertNode(&root, 15);

	printf("preOrder : "); preOrder(root); printf("\n");
	printf("inOrder : "); inOrder(root); printf("\n");
	printf("postOrder : "); postOrder(root); printf("\n");

	
}