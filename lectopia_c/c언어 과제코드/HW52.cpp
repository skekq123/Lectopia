#include<stdio.h>
#pragma warning (disable : 4996)
void Swap(int *ap, int size);
int main()
{
	int a[] = {1, 2, 3, 4, 5}, size, i;

	size = sizeof(a) / sizeof(a[0]);
	printf("ó�� �迭�� ����� �� : ");
	for (i = 0; i < size; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n�ٲ� �迭�� ����� �� : ");
	Swap(a, size);
	for (i = 0; i < size; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
	return 0;
}
void Swap(int *ap, int size)
{
	int temp, i, j;

	for (i = 0, j=1; i < size/2; i++, j++)
	{
		temp = ap[i];
		ap[i] = ap[size - j];
		ap[size - j] = temp;

	}


}