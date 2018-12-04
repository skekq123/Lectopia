#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
int main()
{
	char firstname[20], lastname[20];
	int len1, len2;

	printf("#성을 입력하시오 : ");
	scanf("%s", firstname);
	printf("#이름을 입력하시오 : ");
	scanf("%s", lastname);
	
	len1 = strlen(firstname);
	len2 = strlen(lastname);

	printf("%s %s\n",firstname, lastname);
	printf("%*d %*d\n", len1, len1, len2, len2);

	return 0;
}