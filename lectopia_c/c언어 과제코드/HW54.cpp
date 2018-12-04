#include<stdio.h> 
#pragma warning (disable : 4996)
#include<string.h>
void Input(char *str);
void Input2(char *ch);
void strcheck(char *str, char ch, int *num, int len);
int main()
{
	char ch, str[100];
	char end[] = "end";
	int num[100] = {-1}, i, j, len;
	while (1) {
		Input(str);
		len = strlen(str);
		if (strcmp(str, end) == 0){
			printf("종료되었습니다.\n");
			break;
	}
		else {
			Input2(&ch);
			strcheck(str, ch, num, len);
			if (num[0] == -1)
				printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n", str, ch);
			else {
				printf("\"%s\" 문자열 안에 '%c' 문자는", str, ch);
				for (i = 0, j=0; i < 100; i++)
				{
					if (i > 0 && num[j] == 0) break;
					else {
						printf(" %d번 위치", num[i]);
						j++;
					}
				}
				printf("에 존재합니다.\n");
				for (i = 0; i < len; i++)  //배열 초기화 부분
				{
					if (i == 0)
						num[i] = -1;
					else
					num[i] = 0;
				}
			}
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
void strcheck(char *str, char ch, int *num, int len)
{
	int i, j;
	for (i = 0, j = 0; i < len; i++)
	{
		if (str[i] == ch)
		{
			num[j] = i;
			j++;
		}
	}
	
}