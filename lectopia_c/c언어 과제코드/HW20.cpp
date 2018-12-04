#include<stdio.h>
#pragma warning(disable : 4996)
int Input();
int Total(int hour);
int Tax(int total);
void Output(int total, int tax);
void Myflush();
int main()
{
	int hour, tax, total;

	hour = Input();
	total = Total(hour);
	tax = Tax(total);
	Output(total, tax);

	return 0;
}
int Input()
{
	int hour, res;
	while (1) {
		printf("*1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
		res = scanf("%d", &hour);
		if (res == 1)
			break;
		else
		{
			Myflush();
			printf("���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
		}
	}
	return hour;
}
int Total(int hour)
{
	int total, pay = 3000;

	if (hour <= 40)
		total = 40 * pay;
	else
		total = 40 * pay + ((hour - 40) * pay * 3)/2 ;

	return total;
}
int Tax(int total)
{
	int tax;

	if (total <= 100000) 
		tax = total * 15 / 100;
	
	else 
		tax = 100000 * 15 / 100 + (total - 100000) * 25 / 100;
	
	return tax;
}
void Output(int total, int tax)
{
	int income;

	income = total - tax;

	printf("#�Ѽ��� : %d��\n", total);
	printf("#��  �� : %d��\n", tax);
	printf("#�Ǽ��� : %d��\n", income);
}
void Myflush()
{
	while (getchar() != '\n');
}