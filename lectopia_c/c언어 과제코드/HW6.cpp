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

	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf_s("%lf",&F);

	return F;
}
void Output(double C)
{
	printf("���� �µ��� %.1lf���Դϴ�.\n",C);
}