#include<stdio.h>
void PrintArray(int* arr, int size)
{
	printf("arr : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}
void swap(int* n1, int* n2)
{

	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void SortArray(int* arr)
{
	for (int i = 0; i < 5; i++) //���� ��� ����
	{
		for (int j = i; j < 5; j++) //�� ��� ����
		{
			if (arr[i] > arr[j]) //������ ��󺸴� ũ�ٸ� swap �Լ��� ��ġ�� �ٲ۴�.
				swap(&arr[i], &arr[j]);
		}
	}
}

int main()
{
	int arr[5] = { 2, 7, 4, 8, 6 };
	
	PrintArray(arr, 5);
	int n1 = 5, n2 = 7;
	printf("n1 : %d, n2 : %d\n", n1, n2);
	swap(&n1, &n2);
	printf("n1 : %d, n2 : %d\n", n1, n2);

	for (int i = 0; i < 5; i++) //���� ��� ����
	{
		for (int j = i; j < 5; j++) //�� ��� ����
		{
			if (arr[i] < arr[j]) //������ ��󺸴� ũ�ٸ� swap �Լ��� ��ġ�� �ٲ۴�.
				swap(&arr[i], &arr[j]);
		}
	}
	PrintArray(arr, 5);

	SortArray(arr); //������������ ���ĵǴ� �Լ�
	PrintArray(arr, 5);
}