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

	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf",&weight);

	return weight;
}
double InputHeight()
{
	double height;

	printf("키를 입력하세요(m) : ");
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
	
	printf("당신의 BMI는 %.1lf으로 ",bmi);

	if (bmi < 18.5)
		printf("저체중입니다.\n");
	else if (bmi < 25.0)
		printf("정상체중입니다.\n");
	else if (bmi < 30.0)
		printf("과체중입니다.\n");
	else if (bmi < 40.0)
		printf("비만입니다.\n");
	else 
		printf("고도비만입니다.\n");
}