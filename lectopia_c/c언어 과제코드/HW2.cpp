#include<stdio.h>

int main()
{
	int money = 278970;
	int m50000, m10000, m5000, m1000, m500, m100, m50, m10;

	m50000 = money / 50000;
	money %= 50000;
	printf("50000원권 => %d개\n", m50000);

	m10000 = money / 10000;
	money %= 10000;
	printf("10000원권 => %d개\n", m10000);

	m5000 = money / 5000;
	money %= 5000;
	printf("5000원권 => %d개\n", m5000);

	m1000 = money / 1000;
	money %= 1000;
	printf("1000원권 => %d개\n", m1000);

	m500 = money / 500;
	money %= 500;
	printf("500원권 => %d개\n", m500);

	m100 = money / 100;
	money %= 100;
	printf("100원권 => %d개\n", m100);

	m50 = money / 50;
	money %= 50;
	printf("50원권 => %d개\n", m50);

	m10 = money / 10;
	money %= 10;
	printf("10원권 => %d개\n", m10);

	return 0;
}