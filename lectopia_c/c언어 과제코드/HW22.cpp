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
		printf("# �������� �Է��ϼ��� : ");
		res = scanf("%d", &number);
		if (res == 1)
			break;
		else
		{	
			Myflush();
			printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
		}
	}
	return number;
}
void Myflush()
{
	while (getchar() != '\n');
}