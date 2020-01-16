#include<stdio.h>
void swap(int* n1, int* n2) {
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;

}

int main(void)
{
	int n1 = 11, n2 = 22;

	printf("n1 : %d, n2 : %d\n", n1, n2);

	swap(&n1, &n2);

	printf("n1 : %d, n2 : %d\n", n1, n2);

	return 0;
}