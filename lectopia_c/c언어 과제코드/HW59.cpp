#include<stdio.h>
#pragma warning (disable : 4996)


int main()
{
	int a[3][4] = { {8, 3, 9, 4}, {2, 1, 2, 5}, {6, 3, 9, 2} }, i, j, sum=0;
	for (i = 0; i < 3; i++)
	{
		printf("%d��\t: ", i);
		for (j = 0; j < 4; j++)
		{
			printf("\t%d",a[i][j]);
			sum += a[i][j];
		}
		printf("\t%d���� �� : %d\n",i, sum);
		sum = 0;
	}
	printf("���� �� :");
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 3; i++)
			{
				sum += a[i][j];
			}
			printf("\t\b%d",sum);
			sum = 0;
		}
		printf("\n");
	
	
	return 0;
}
