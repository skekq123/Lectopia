#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int i, j;
	char ch;
	while (1) {

		printf("* 영문자 대문자 입력('A' ~ 'Z') : ");
		scanf(" %c", &ch);
		if (ch < 65 || ch > 90 || getchar() != '\n') {
			printf("종료되었습니다.\n");
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