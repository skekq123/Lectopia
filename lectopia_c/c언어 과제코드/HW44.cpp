#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int i, j, k;

	printf("<2중 for문을 이용한 출력>\n");

	for (i = 1; i < 10; i++)
	{
		for (j = 2; j < 6; j++)
		{
			printf("%d*%d= %-5d", j, i, i*j);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 1; i < 10; i++)
	{
		for (j = 6; j < 10; j++)
		{
			printf("%d*%d= %-5d", j, i, i*j);
		}
		printf("\n");
	}
	printf("----------------------------------------\n");
	printf("<3중 for문을 이용한 출력>\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 2; k < 6; k++)
			{
				if(i == 0 )
				printf("%d*%d = %-5d", k, j, k*j);
				else
					printf("%d*%d = %-5d", k+4, j, (k+4)*j);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}