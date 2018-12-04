#include<stdio.h>
#pragma warning (disable : 4996)
#include<string.h>
void Input(char *str);
void Input2(char *ch);
int strcheck(char *str, char ch);
int main()
{
	char ch, str[100], index;
	char end[] = "end";
	while (1) {
		Input(str);
		if (strcmp(str, end) == 0) break;
		else {
			Input2(&ch);
			index = strcheck(str, ch);
			if (index >= 0)
				printf("\"%s\" 문자열 안에 '%c' 문자는 %d번 위치에 존재합니다.\n", str, ch, index);
			else
				printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n", str, ch);
		}
	}
	return 0;
}
void Input(char *str)
{
		printf("# 문자열을 입력하시오 : ");
		scanf("%s", str);
}
void Input2(char *ch)
{
	printf("# 문자를 입력하시오 : ");
	scanf(" %c", ch);
}
int strcheck(char *str, char ch)
{
	int i, index;
	for (i = 0; i < 100; i++)
	{
		if (str[i] == ch)
		{
			index = i;
			return index;
			break;
		}
	}
	return -1;
}