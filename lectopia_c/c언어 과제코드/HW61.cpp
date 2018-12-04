#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)
void strInput(char(*str)[20]);
void Sort(char(*str)[20]);
void Output(char(*str)[20]);
int main()
{
	char str[5][20];
	
	strInput(str);
	Sort(str);
	Output(str);
	return 0;
}
void strInput(char (*str)[20])
{
	int i;
	for (i = 0; i < 5; i++) {
		printf("# %d번 문자열을 입력하시오 : ", i+1);
		scanf("%s", &str[i][0]);
	}
}
void Sort(char(*str)[20])
{
	char temp[20];
	int i,j;
	for(j = 0; j < 4; j++){
		for (i = 1; i < 5-j; i++)
		{
			if (strncmp(str[i-1], str[i], 1) > 0) {
				strcpy(temp, str[i-1]);
				strcpy(str[i-1], str[i]);
				strcpy(str[i], temp);
			}
		}
	}
}
void Output(char(*str)[20])
{
	int len, i;

	for (i = 0; i < 5; i++)
	{
		len = strlen(str[i]);
		printf("str[%d] = %s %3c%3c\n", i, str[i], str[i][0], str[i][len-1]);
	}
	
}