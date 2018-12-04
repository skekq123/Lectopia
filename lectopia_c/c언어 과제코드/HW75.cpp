#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#pragma warning (disable : 4996)
void Random(int *num);
void BallcountCheck(int * num, int *ball, int *strike, int *count);
void Output(int *num, int *ball, int *strike, int * count);
int main()
{
	int num[4], i, ball = 0, strike = 0, count = 1;
	srand((unsigned int)time(NULL));
	Random(num);
	for (i = 0; i < 4; i++) {
		printf("%3d", num[i]);
	}
	printf("\n");
	Output(num, &ball, &strike, &count);
	return 0;
}
void Random(int *num)
{
	int number, i, j;

	number = rand() % 10;
	num[0] = number;
	for (i = 1; i < 4;) {
		number = rand() % 10;
		for (j = 0; j < i; j++)
		{
			if (num[j] == number) break;
			else if (num[j] != number)
			{
				if (j == i - 1) {
					num[i] = number;
					i++;
					break;
				}
			}
		}
	}
	}
void BallcountCheck(int * num, int *ball, int *strike, int *count)
{
	int i, j, str[4];
	
	printf("# %dÂ÷ : ", *count);
	for (i = 0; i < 4; i++)
	{
		str[i] = getche() - '0';
		printf("\t");
	}
	for (i = 0; i < 4; i++)
	{
		
		for (j = 0; j < 4; j++)
		{
			
			if (str[i] == num[j])
			{
				if (i == j) {
					(*strike)++;
				
				}
				else
					(*ball)++;
			}
			
			}
	
		}
	
	(*count)++;
}
void Output(int *num, int *ball, int *strike, int * count)
{
	while (1) {
		BallcountCheck(num, ball, strike, count);
		if (*strike == 4) {
			printf("OK!!!\n");
			break;
		}
		else if (*strike + *ball > 0)
			printf("%dS %dB", *strike, *ball);
		else
			printf("NO!!!");
		*strike = 0;
		*ball = 0;
		printf("\n");
	}
}
