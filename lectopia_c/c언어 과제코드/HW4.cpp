#include<stdio.h>

int main()
{
	double da, sec = 365.2422;
	int day, our, min;

	da = sec;

	day = (int)sec;   //day ���ϴ½�
	sec -= day;

	sec *= 24;
	our = (int)sec;  // our ���ϴ½�
	sec -= our;

	sec *= 60;
	min = (int)sec;  // min ���ϴ½�
	sec -= min;

	sec *= 60;
	
	printf("%.4lf���� %d�� %d�ð� %d�� %.2lf���Դϴ�.\n",da, day, our, min, sec);

	return 0;
}