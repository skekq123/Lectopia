#include<stdio.h>
#pragma warning (disable : 4996)
#include<math.h>
int primeNumber(int number);
void Myflush();
int Input();
int main()
{
	int num, number, prime, count = 0, enter=1;
	
	num = Input();
	printf("1~%d까지의 소수 값은 다음과 같습니다.\n", num);
	for (number = 2; number <= num; number++)
	{
		prime = primeNumber(number);
		if (prime == 1) {
			printf("%-5d", number);
			count++;
			enter++;
		}
		if (enter % 6 == 0) {
			printf("\n");
			enter = 1;
		}
	}
	printf("\n1~%d까지의 총 소수는 %d개 입니다.\n", num, count);

	return 0;
}
int primeNumber(int number)
{
	int i, mod=0;

	for (i = 1; i <= (int)sqrt(number); i++)
	{
		if (number % i == 0)
			mod++;
	}
	if (mod == 1)
		return 1;
	else
		return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}
int Input()
{
	int num;

	while (1) {
		printf("*정수값 하나를 입력하시오 : ");
		scanf("%d", &num);
		
		if (num > 0) {
			if (getchar() == '\n')
				break;
		}
		else
			Myflush();
		
		
	}
	return num;
}