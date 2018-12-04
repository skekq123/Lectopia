#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)
void Myflush();
int InputMoney();
void NumberChange(int money, char *str);
int main()
{
	int money;
	char str[100];
	while (1) {
		while (1) {
			money = InputMoney();
			if (getchar() != '\n') {
				Myflush();
				printf("문자를 입력하셨습니다.\n");
			}
			else 
				break;
		}
		if (money < 0) {
			printf("종료되었습니다.\n");
				break;
		}
		NumberChange(money, str);
	}
	
	return 0;
}
int InputMoney()
{
	int money;
	
		printf("# 금액 입력 : ");
		scanf("%d", &money);

	return money;
}
void Myflush()
{
	while (getchar() != '\n');
}
void NumberChange(int money, char *str)
{
	int len, i, count;
	sprintf(str, "%d", money);
	len = strlen(str);
	count = 3 - len % 3;
	printf("%s -> ",str);
	for (i = 0; i < len; i++)
	{	
		printf("%c", str[i]);
		count++;
		if (count% 3 == 0 && i != len -1)
		{
			printf(",");
		}
	}
	printf("\n");
}

