#include<stdio.h>
#pragma warning(disable : 4996)
int main()
{
	int i, j;

	for (i = 1; i <= 10 ; i++) {
		for (j = i; j <= 100; j++)
		{
			if (j % 10 == 0)
			printf("%3d", j+i-11);
		}
		printf("\n");
	}
	return 0;
}
