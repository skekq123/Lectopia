#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
int main()
{
	char firstname[20], lastname[20];
	int len1, len2;

	printf("#���� �Է��Ͻÿ� : ");
	scanf("%s", firstname);
	printf("#�̸��� �Է��Ͻÿ� : ");
	scanf("%s", lastname);
	
	len1 = strlen(firstname);
	len2 = strlen(lastname);

	printf("%s %s\n",firstname, lastname);
	printf("%*d %*d\n", len1, len1, len2, len2);

	return 0;
}