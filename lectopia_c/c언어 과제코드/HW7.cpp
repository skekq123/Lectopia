#include<stdio.h>

int main()
{
	double km, kmh, time;
	int our, min;
	printf("����Ÿ�, �ü��� �Է� : ");
	scanf_s("%lf%lf", &km, &kmh);

	time = km / kmh;

	our = (int)time;
	time -= our;

	time *= 60;
	min = (int)time;
	time -= min;
	time *= 60;

	printf("%.2lf Km => %d�ð� %d�� %.3lf�� �ҿ��\n", km, our, min, time);
	return 0;
}