#include<stdio.h>
#pragma warning (disable : 4996)
void Input(double *ary);
double Max(double *ary);
double Min(double *ary);
void Output(double max, double min);
void Myflush();
int main()
{
	double ary[5], max, min;
	
	Input(ary);

	max = Max(ary);
	min = Min(ary);
	Output(max, min);
	
	

	return 0;
}
void Input(double *ary)
{
	int i;
	for (i = 0; i < 5; i++) {
		while (1) {
			printf("%d�� �� �� : ", i);
			scanf("%lf", (ary + i));
			if (getchar() == '\n')
				break;
			else
				Myflush();
		}
	}
}
double Max(double *ary)
{
	int i;
	double max;
	max = ary[0];
	for (i = 0; i < 5; i++)
	{
		if (max < ary[i])
			max = ary[i];
		
	}
	return max;
}
double Min(double *ary)
{
	int i;
	double min;
	min = ary[0];

	for (i = 0; i < 5; i++)
	{
		if (min > ary[i])
			min = ary[i];

	}
	return min;
}
void Output(double max, double min)
{
	printf("���� ū �� : %.2lf\n", max);
	printf("���� ���� �� : %.2lf\n", min);
}
void Myflush()
{
	while (getchar() != '\n');
}
