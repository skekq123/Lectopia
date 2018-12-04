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

	num = inputInt("* 양의 정수 밑을 입력 하시오 : ");
	N1 = inputInt("* 양의 승을 입력 하시오 : ");

	result1 = ipow(num, N1);
	printf("%d의 %d승은 %d입니다.\n", num, N1, result1);

	fnum = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	N2 = inputInt("* 양의 승을 입력 하시오 : ");

	result2 = fpow(fnum, N2);
	printf("%.2lf의 %d승은 %.3lf 입니다.",fnum, N2, result2);

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
			printf("다시 입력하세요.\n");
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
			printf("다시 입력하세요.\n");
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