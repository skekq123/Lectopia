#include<stdio.h>
#pragma warning (disable : 4996)
int main()
{
	char ch;
	int word = 0, num = 0, spec = 0, space = 0;

	printf("# 영문 문장을 입력 하시오 : \n");
	while ((ch = getchar()) != EOF)
	{
		if (ch == EOF)
			break;
		else if ((ch >= 'A') && (ch <= 'Z') || (ch >= 'a') && (ch <= 'z'))
			word++;
		else if ((ch == ' ') || (ch == '\t') || (ch == '\n'))
			space++;
		else if ((ch >= '0') && (ch <= '9'))
			num++;
		else
			spec++;
	}
	printf("* 영문자 대소문자 개수 : %d\n", word);
	printf("* 숫자문자 개수 : %d\n", num);
	printf("* 여백문자(space, tab, enter) 개수 : %d\n", space);
	printf("* 그 외 기타문자 개수 : %d\n", spec);
			return 0;
}