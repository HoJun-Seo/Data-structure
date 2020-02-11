#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
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
	if ((*root) == NULL)
	{
		(*root) = getNode();
		(*root)->data = data;
	}
	else if ((*root)->data > data)
		insertNode(&(*root)->left, data);
	else if ((*root)->data < data)
		insertNode(&(*root)->right, data);
}

Tree* findNode(Tree* root, int data)
{
	if (root != NULL)
	{
		if (root->data == data)
			return root;
		else if (root->data > data)
			findNode(root->left, data);
		else if (root->data < data)
			findNode(root->right, data);
	}
	else return NULL;
}

Tree* findMinNode(Tree* root)
{
	if (root->left != NULL)
		return findMinNode(root->left);
	else return root;
}

void deleteNode(Tree** root, int data)
{
	Tree* tmp = getNode();
	Tree* find = findNode(*root, data);
	int swap = 0;
	if ((*root) != NULL) {
		if ((*root)->data == data)
		{
			if ((*root)->left == NULL && (*root)->right == NULL)
			{
				free((*root));
				(*root) = NULL;
			}
			else if ((*root)->left != NULL && (*root)->right == NULL)
			{
				tmp = find;
				(*root) = find->left;
				free(tmp);
				tmp = NULL;
			}
			else if ((*root)->left == NULL && (*root)->right != NULL)
			{
				tmp = find;
				(*root) = find->right;
				free(tmp);
				tmp = NULL;
			}
			else if ((*root)->left && (*root)->right)
			{
				printf("삭제할 데이터 : %d\n", (*root)->data);
				tmp = findMinNode((*root)->right);
				printf("교체할 데이터 : %d\n", tmp->data);
				swap = (*root)->data;
				(*root)->data = tmp->data;
				tmp->data = swap; //data;(swap을 굳이 사용하지 않아도 상관 없음)
				deleteNode(&(*root)->right, tmp->data);
			}
		}
		else if ((*root)->data > data)
			deleteNode(&(*root)->left, data);
		else if ((*root)->data < data)
			deleteNode(&(*root)->right, data);
	}
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

int main()
{
	Tree* root = NULL;
	Tree* find = NULL;

	int arr[20] = { 45, 27, 17, 62, 57, 73, 52, 65, 76, 69, 63, 64, 71 };
	for (int i = 0; arr[i]; /* arr[i] != 0 */ i++)
		insertNode(&root, arr[i]);

	int menu, data;
	while (1)
	{
		printf("\n\n");
		printf("preOrder : ");
		preOrder(root);
		printf("\n\n");
		printf("1. insertNode\n2. findNode\n3. deleteNode\n");
		printf("9. clear Screen\n0. Quit\nSelect Menu >>>");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("=== insertNode ===\n\n");
			printf("input data : ");
			scanf("%d", &data);
			insertNode(&root, data);
			break;
		case 2:
			printf("=== findNode ===\n\n");
			printf("find data : ");
			scanf("%d", &data);
			find = findNode(root, data);
			if (find != NULL)
				printf("%d : 데이터를 찾았습니다. \n", find->data);
			else printf("%d : 데이터를 찾지 못했습니다.\n", data);
			break;
		case 3:
			printf("=== deleteNode ===\n\n");
			printf("delete data : ");
			scanf("%d", &data);
			deleteNode(&root, data);
			//1. 말단 노드이면, 곧바로 삭제(free)
			//2. 하위 노드가 하나만 있으면(왼쪽 or 오른쪽), 다음 노드를 가리키게 하고 삭제
			//3. 하위 노드가 양쪽다 있으면(왼쪽 and 오른쪽), 대체값을 선출하고 삭제
			break;
		case 9:
			system("cls");
			break;
		case 0:
			printf("종료합니다.\n");
			return;
		}
	}
}
