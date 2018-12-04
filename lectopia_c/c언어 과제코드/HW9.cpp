#include<stdio.h>
int Input();
int main()
{
	int number;

	number = Input();
	printf("입력된 값은 8 진수로 0%o 입니다.\n",number);
	printf("입력된 값은 16 진수로 0x%x 입니다. \n", number);
	return 0;
}
int Input()
{
	int number;
	
	printf("정수값을 입력하세요 : ");
	scanf_s("%d",&number);

	return number;
}