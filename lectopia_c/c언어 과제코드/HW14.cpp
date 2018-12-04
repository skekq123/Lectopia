#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)
int main()
{
	char name[20];
	int len1, len2;
	printf("* 문자열 입력 : ");
	scanf("%s", name);

	len1 = strlen(name);
	len2 = len1 / 2;

	printf("[%*.*s...]\n",len1 , len2, name);

	return 0;
}