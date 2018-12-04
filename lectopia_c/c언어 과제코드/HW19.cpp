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

		printf("년도를 입력하시오 : ");
		res = scanf("%d", &year);
		if (res == 1)
			break;
		else {
			Myflush();
			printf("문자를 입력하셨습니다. 다시 입력하십시오.\n");
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
				return 1; //윤년
			}
			else
			{	
				return 0; //평년
			}
		}
		else
		{
		
			return 1; //윤년
		}
	
	}
	else
	{
		return 0; //평년
	}
}
void Myflush()
{
	while (getchar() != '\n');
}
void Output(int check, int year)
{
	if (check == 1)
		printf("%d년은 윤년(Leap year)입니다.\n", year);
	else
		printf("%d년은 평년(Common year)입니다.\n", year);
}