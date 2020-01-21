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
	for (int i = 0; i < 5; i++) //기준 요소 설정
	{
		for (int j = i; j < 5; j++) //비교 대상 설정
		{
			if (arr[i] > arr[j]) //기준이 대상보다 크다면 swap 함수로 위치를 바꾼다.
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

	for (int i = 0; i < 5; i++) //기준 요소 설정
	{
		for (int j = i; j < 5; j++) //비교 대상 설정
		{
			if (arr[i] < arr[j]) //기준이 대상보다 크다면 swap 함수로 위치를 바꾼다.
				swap(&arr[i], &arr[j]);
		}
	}
	PrintArray(arr, 5);

	SortArray(arr); //오름차순으로 정렬되는 함수
	PrintArray(arr, 5);
}