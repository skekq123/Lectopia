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
				printf("���ڸ� �Է��ϼ̽��ϴ�.\n");
			}
			else 
				break;
		}
		if (money < 0) {
			printf("����Ǿ����ϴ�.\n");
				break;
		}
		NumberChange(money, str);
	}
	
	return 0;
}
int InputMoney()
{
	int money;
	
		printf("# �ݾ� �Է� : ");
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

