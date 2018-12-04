#include<stdio.h>

int main()
{
	double da, sec = 365.2422;
	int day, our, min;

	da = sec;

	day = (int)sec;   //day 구하는식
	sec -= day;

	sec *= 24;
	our = (int)sec;  // our 구하는식
	sec -= our;

	sec *= 60;
	min = (int)sec;  // min 구하는식
	sec -= min;

	sec *= 60;
	
	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다.\n",da, day, our, min, sec);

	return 0;
}