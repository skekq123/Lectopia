#include<stdio.h>
#pragma warning(disable : 4996)
int Input();
int YearCheck(int year);
void Myflush();
void Output(int check, int year);
int main()
{
	int year, check;

	year = Input();
	check = YearCheck(year);
	Output(check, year);
	
	return 0;
}
int Input()
{
	int year, res;
	while (1) {

		printf("�⵵�� �Է��Ͻÿ� : ");
		res = scanf("%d", &year);
		if (res == 1)
			break;
		else {
			Myflush();
			printf("���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
		}
	}
	return year;
}
int YearCheck(int year)
{
	if (year % 4 == 0)
	{	
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return 1; //����
			}
			else
			{	
				return 0; //���
			}
		}
		else
		{
		
			return 1; //����
		}
	
	}
	else
	{
		return 0; //���
	}
}
void Myflush()
{
	while (getchar() != '\n');
}
void Output(int check, int year)
{
	if (check == 1)
		printf("%d���� ����(Leap year)�Դϴ�.\n", year);
	else
		printf("%d���� ���(Common year)�Դϴ�.\n", year);
}