#include<stdio.h>
#pragma warning (disable : 4996)
#include<math.h>
double InputWeight();
double InputHeight();
double CalcBmi(double weight, double height);
void Output(double bmi);
int main()
{
	double weight, height, bmi;

	weight = InputWeight();
	height = InputHeight();
	bmi = CalcBmi(weight, height);
	Output(bmi);

	return 0;
}
double InputWeight()
{
	double weight;

	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%lf",&weight);

	return weight;
}
double InputHeight()
{
	double height;

	printf("Ű�� �Է��ϼ���(m) : ");
	scanf("%lf", &height);

	return height;
}
double CalcBmi(double weight, double height)
{
	double bmi;

	bmi = weight / pow(height, 2);

	return bmi;
}
void Output(double bmi)
{
	
	printf("����� BMI�� %.1lf���� ",bmi);

	if (bmi < 18.5)
		printf("��ü���Դϴ�.\n");
	else if (bmi < 25.0)
		printf("����ü���Դϴ�.\n");
	else if (bmi < 30.0)
		printf("��ü���Դϴ�.\n");
	else if (bmi < 40.0)
		printf("���Դϴ�.\n");
	else 
		printf("�����Դϴ�.\n");
}