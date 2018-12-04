#include<stdio.h>
#pragma warning (disable : 4996)
#define NL printf("\n");
#include<stdlib.h>
#include<time.h>
void Input(int(*array)[5]);
void Sum(int(*array)[5], int *sum1, int *sum2, int *sum3);
void Output(int *sum1, int *sum2, int *sum3);
int main()
{
	srand((unsigned int)time(NULL));
	int array[5][5], sum1 = 0, sum2 = 0 ,sum3 = 0;
	Input(array);
	Sum(array, &sum1, &sum2, &sum3);
	Output(&sum1, &sum2, &sum3);

	return 0;
}
void Input(int (*array)[5])
{
	int i , j;
	
	for (i = 0; i < 5; i++)
	{
		printf("%d¹ø Çà : ",i);
		for (j = 0; j < 5; j++)
		{
			array[j][i] = rand()%20+1;
			printf("%3d ", array[j][i]);
		}
		NL
	}
}
void Sum(int(*array)[5], int *sum1, int *sum2, int *sum3)
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i == j)
				*sum1 += array[i][j];
			else if (j > i)
				*sum3 += array[i][j];
			else if (i > j)
				*sum2 += array[i][j];
		}
	}
}
void Output(int *sum1, int *sum2, int *sum3)
{
	
	printf("sum1 == %d\n", *sum1);
	printf("sum2 == %d\n", *sum2);
	printf("sum3 == %d\n", *sum3);

}
