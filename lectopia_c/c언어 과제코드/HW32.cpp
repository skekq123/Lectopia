#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int menu();
int inputInt(char *string);
int Deposit(int deposit, int total);
int Withdraw(int withdraw, int total);
int main()
{
	int deposit, withdraw, total = 0, end=0;
	char ch;
	
	while (1) {
		ch = menu();
		switch (ch)
		{
		case 'i': deposit = inputInt("# 입금액을 입력하세요.");
			total = Deposit(deposit, total); 
			printf("* 현재 잔액은 %d원 입니다.\n", total);
			break;
		case 'o': withdraw = inputInt("# 출금액을 입력하세요.");
			total = Withdraw(withdraw, total); 
			if (total < 0)
			{
				total += withdraw;
				printf("* 잔액이 부족합니다.\n");
				printf("* 현재 잔액은 %d원 입니다.\n", total);
				break;
			}
			printf("* 현재 잔액은 %d원 입니다.\n", total);
			break;
		case 'q': 
			end =1;
			break;
		}
		if (end == 1)
		{
			printf("종료되었습니다. \n");
			break;
		}
			
		
	}
	
	
}
int menu()
{
	char ch;
	while (1) {
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		scanf(" %c", &ch);
		if (ch == 'i' || ch == 'o' || ch == 'q')
			return ch;
		else
		{
			Myflush();
			printf("다시 입력하세요. \n");
		}
	}
	
}
void Myflush()
{
	while (getchar() != '\n');
}
int inputInt(char *string)
{
	int a;
	while (1) {
		printf("%s", string);
		scanf("%d", &a);
		if (getchar() == '\n' && a >= 0) break;
		else
		{
			Myflush();
			printf("* 잘못 입력하셨습니다.\n");
		}
	}
	return a;
}
int Deposit(int deposit, int total)
{

	total += deposit;

	return total;
}
int Withdraw(int withdraw, int total)
{
	total -= withdraw;

	return total;
}