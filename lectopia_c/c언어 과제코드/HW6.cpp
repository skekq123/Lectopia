#include<stdio.h>
double Input();
void Output(double C);
int main()
{
	double F, C;

	F = Input();
	C = (double)5/(double)9*(F-(double)32);
	Output(C);

	return 0;
}

double Input()
{
	double F;

	printf("화씨 온도를 입력하세요 : ");
	scanf_s("%lf",&F);

	return F;
}
void Output(double C)
{
	printf("섭씨 온도는 %.1lf도입니다.\n",C);
}