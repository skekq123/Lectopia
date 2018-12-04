#include<stdio.h>
#pragma warning (disable : 4996)
int Input();
void Myflush();
int main()
{
	int number, number2, count=0;
	
	number = Input();
	number2 = number;
	while (number != 0) {
		printf("*");
		number--;
		count++;
		if (count % 5 == 0)
			printf("\n");
	}
	if (number2 % 5 != 0)
		printf("\n");
	return 0;
}
int Input()
{
	int number, res;
	while (1) {
		printf("# 정수값을 입력하세요 : ");
		res = scanf("%d", &number);
		if (res == 1)
			break;
		else
		{	
			Myflush();
			printf("잘못입력하셨습니다. 다시 입력하세요.\n");
		}
	}
	return number;
}
void Myflush()
{
	while (getchar() != '\n');
}