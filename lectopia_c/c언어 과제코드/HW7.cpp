#include<stdio.h>

int main()
{
	double km, kmh, time;
	int our, min;
	printf("주행거리, 시속을 입력 : ");
	scanf_s("%lf%lf", &km, &kmh);

	time = km / kmh;

	our = (int)time;
	time -= our;

	time *= 60;
	min = (int)time;
	time -= min;
	time *= 60;

	printf("%.2lf Km => %d시간 %d분 %.3lf초 소요됨\n", km, our, min, time);
	return 0;
}