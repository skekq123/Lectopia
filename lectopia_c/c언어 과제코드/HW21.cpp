#include<stdio.h>
#pragma warning(disable : 4996)
void Myflush();
int main()
{
	double a[5],sum=0, avg;
	int n=0, res;

	while(n != 5)
	{	
		while (1) {
			printf("%d번 학생의 키는 ? ", n + 1);
			res = scanf("%lf", &a[n]);
			if (res == 1)
				break;
			else
			{	
				Myflush();
				printf("잘못 입력하셨습니다. 다시 입력하세요\n");
			}
		}
		sum += a[n];
		n++;

	}

	avg = sum / n;
	printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", avg);
}
void Myflush()
{
	while (getchar() != '\n');
}