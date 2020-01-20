#include<stdio.h>

void modify(int* arr)
{
	//arr[2] = 30;
	*(arr + 2) = 30;
}
int main()
{
	int arr[5] = { 10, 20, 3, 40, 50 };
	modify(arr);

	printf("arr : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
}



// code : code(machine language)

// data : literal(���)

// heap : dynamic allocation(���� �Ҵ�)

// stack : function, local variable(���� ����)