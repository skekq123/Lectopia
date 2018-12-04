#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int iterator, i, j;
	while (1) {
		printf("# 출력 라인수를 입력하시오 : ");
		scanf("%d", &iterator);
		if (getchar() == '\n')
		{
			for (i = 1; i <= iterator; i++)
			{
				for (j = 1; j <= i; j++)
				{
					printf("*");
				}
				for (j = iterator - i; j >= 0; j--)
				{
					printf("  ");
				}
				for (j = 1; j <= i; j++)
				{
					printf("*");
				}
				printf("\n");

			}
		}
		else
		{
			printf("종료되었습니다.\n");
			break;
		}
	}
		
	return 0;
}
