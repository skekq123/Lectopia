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
			printf("%d�� �л��� Ű�� ? ", n + 1);
			res = scanf("%lf", &a[n]);
			if (res == 1)
				break;
			else
			{	
				Myflush();
				printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���\n");
			}
		}
		sum += a[n];
		n++;

	}

	avg = sum / n;
	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�.\n", avg);
}
void Myflush()
{
	while (getchar() != '\n');
}