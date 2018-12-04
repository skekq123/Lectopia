#include<stdio.h>
#pragma warning (disable : 4996)
char* ustrchr(char *str, int ch);
char* ustrcat(char *s1, char *s2);
void ustrcpy(char *s1, char *s2);
unsigned int ustrlen(char *str);
int ustrcmp(char *s1, char *s2);
char* ustrstr(char *s1, char *s2);
int main()
{
	char str[100] = "apple", s1[100] = "lo", s2[100] = "ve", s3[100] = "loooong", s4[100] = "short";
	int ch = 'p';
	
	printf("1번 답 : %s\n", ustrchr(str, ch));          //1 ustrchr
	printf("2번 답 : %s\n", ustrcat(s1, s2));          //2  ustrcat
	printf("3번 답 : %s\n", ustrstr(s1, s2));          //3  ustrstr
	ustrcpy(s1, s2);    
	printf("4번 답 : %s\n", s1);                       //4 ustrcpy
	printf("5번 답 : strlen = %d\n", ustrlen(str));    //5 ustrlen
	printf("6번 답 : return값 : %d\n", ustrcmp(s3, s4));  //6 ustrcmp
	return 0;
}
char* ustrchr(char *str, int ch)
{
	int i;
	for (i = 0;str[i] != NULL; i++)
	{
		if (str[i] == ch)
			return &str[i];
	}
	return NULL;
}
char* ustrcat(char *s1, char *s2)
{
	int i, j, count=0;
	for (i = 0;; i++)
	{	
		if (s1[i] == NULL)
		{
			for (j = 0;; j++)
			{
				s1[i + j] = s2[j];
				if (s2[j] == NULL) {
					count = 1;
					break;
				}
			}
		}
		if (count == 1)
			break;
	}
	return s1;
}
char* ustrstr(char *s1, char *s2)
{
	int i = 0, len = 0;
	while (s2[len] != NULL)
	{
		len++;
	}
	while (*s1 != NULL)
	{
		if (*s1 != s2[i])
		{
			if (i == 0)
				s1++;
			i = 0;
			continue;
		}
		if (len - 1 == i)
			break;
		i++;
		s1++;
	}
	if (*s1 == NULL)
		return NULL;

	return s1 - i;

}
void ustrcpy(char *s1, char *s2)
{
	int i;
	for (i = 0;; i++)
	{
		s1[i] = s2[i];
		if (s2[i] == NULL)
			break;
	}
}
unsigned int ustrlen(char *str)
{
	unsigned int i = 0;

	while (str[i] != NULL)
	{
		i++;
	}
	return i;
}
int ustrcmp(char *s1, char *s2)
{
	int i, num;
	for (i = 0;; i++)
	{
		
		if (s1[i] == NULL || s2[i] == NULL)
		{
			num = s1[i] - s2[i];
			break;
		}
	}
	if (num > 0)
		return 1;
	else if (num < 0)
		return -1;
	else
		return 0;
}
