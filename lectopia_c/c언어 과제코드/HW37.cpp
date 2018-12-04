#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int i, count;
	
	for (i = 1, count = 1; i <= 100; i++, count++)
	{	
		if (i % 3 != 0 && i % 5 != 0)
			printf("%3d", i);
		else if (i % 3 == 0 && i % 5 == 0)
			printf("%3d", i);
		else if (i % 3 == 0)
			printf("  *");
		else if (i % 5 == 0)
			printf("  #");

		if (count % 10 == 0)
			printf("\n");
	}
	return 0;
}