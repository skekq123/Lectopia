#include<stdio.h>
#pragma warning (disable : 4996)
#include<math.h>
int inputInt(char *string);
void Myflush();
int ipow(int num, int N);
double inputDouble(char *string);
double fpow(double fnum, double N2);
int main()
{
	
	int num, N1, N2, result1;
	double fnum, result2;

	num = inputInt("* ���� ���� ���� �Է� �Ͻÿ� : ");
	N1 = inputInt("* ���� ���� �Է� �Ͻÿ� : ");

	result1 = ipow(num, N1);
	printf("%d�� %d���� %d�Դϴ�.\n", num, N1, result1);

	fnum = inputDouble("* ���� �Ǽ� ���� �Է� �Ͻÿ� : ");
	N2 = inputInt("* ���� ���� �Է� �Ͻÿ� : ");

	result2 = fpow(fnum, N2);
	printf("%.2lf�� %d���� %.3lf �Դϴ�.",fnum, N2, result2);

}
int inputInt(char *string)
{
	int a;
	while (1) {
		printf("%s", string);
		scanf("%d", &a);
		if (a >=0 && getchar() == '\n')
			break;
		else
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	return a;
}
void Myflush()
{
	while (getchar() != '\n');
}
int ipow(int num, int N1)
{
	int result;

	result = (int)pow(num, N1);

	return result;
}
double inputDouble(char *string)
{	
	double a;
	while (1) {
		printf("%s", string);
		scanf("%lf", &a);
		if (a >= 0.0 && getchar() == '\n')
			break;
		else
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	return a;
}
double fpow(double fnum, double N2)
{
	double result;
	result = pow(fnum, N2);

	return result;
}