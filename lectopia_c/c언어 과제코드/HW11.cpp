#include<stdio.h>

int main()
{
	int number;

	printf("ASCII code값을 입력하시오 : ");
	scanf_s("%d",&number);

	printf("%d은 '%c'의 ASCII code 입니다.\n", number, number);


	return 0;
}