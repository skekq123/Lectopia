#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int iterator, i, j;
	while (1) {
		printf("# ��� ���μ��� �Է��Ͻÿ� : ");
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
			printf("����Ǿ����ϴ�.\n");
			break;
		}
	}
		
	return 0;
}
