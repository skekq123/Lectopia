#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int i, j;
	char ch;
	while (1) {

		printf("* ������ �빮�� �Է�('A' ~ 'Z') : ");
		scanf(" %c", &ch);
		if (ch < 65 || ch > 90 || getchar() != '\n') {
			printf("����Ǿ����ϴ�.\n");
			break;
		}
		for (i = 0; i <= ch - 65; i++)
		{
			for (j = 0; j <= i; j++)
			{
				printf("%c", ch - j);
			}
			printf("\n");
		}
	}
	return 0;
}