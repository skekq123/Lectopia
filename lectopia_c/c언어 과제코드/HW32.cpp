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
		case 'i': deposit = inputInt("# �Աݾ��� �Է��ϼ���.");
			total = Deposit(deposit, total); 
			printf("* ���� �ܾ��� %d�� �Դϴ�.\n", total);
			break;
		case 'o': withdraw = inputInt("# ��ݾ��� �Է��ϼ���.");
			total = Withdraw(withdraw, total); 
			if (total < 0)
			{
				total += withdraw;
				printf("* �ܾ��� �����մϴ�.\n");
				printf("* ���� �ܾ��� %d�� �Դϴ�.\n", total);
				break;
			}
			printf("* ���� �ܾ��� %d�� �Դϴ�.\n", total);
			break;
		case 'q': 
			end =1;
			break;
		}
		if (end == 1)
		{
			printf("����Ǿ����ϴ�. \n");
			break;
		}
			
		
	}
	
	
}
int menu()
{
	char ch;
	while (1) {
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf(" %c", &ch);
		if (ch == 'i' || ch == 'o' || ch == 'q')
			return ch;
		else
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���. \n");
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
			printf("* �߸� �Է��ϼ̽��ϴ�.\n");
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