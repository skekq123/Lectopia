#include<stdio.h>   // 문자입력받으면 종료시킬떄, 음수입력 예외처리 안함
#pragma warning (disable : 4996)
int YearCheck(int year);
void Input(int *year, int *mon, int *day);
int ErrorCheck(int *year, int *mon, int *day, int *month);
int Daysum(int *year, int *mon, int *day, int *month);
int main()
{
	int year, mon, day, month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, sum, end;
	while (1) {
		end = ErrorCheck(&year, &mon, &day, month);
		if (end == 1)
		{
			printf("종료되었습니다.\n");
			break;
		}
		else {
			sum = Daysum(&year, &mon, &day, month);

			printf("%d년 %d월 %d일 ", year, mon, day);
			switch (sum % 7) {
			case 0: printf("일요일\n"); break;
			case 1: printf("월요일\n"); break;
			case 2: printf("화요일\n"); break;
			case 3: printf("수요일\n"); break;
			case 4: printf("목요일\n"); break;
			case 5: printf("금요일\n"); break;
			case 6: printf("토요일\n"); break;
			}
		}
	}
}
void Input(int *year, int *mon, int *day)
{
	printf("* 년 월 일을 입력하시오 : ");
	scanf("%d%d%d", year, mon, day);
}
int ErrorCheck(int *year, int *mon, int *day, int *month)
{
	int leap, leapmonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, end = 0;

	while (1) {
		Input(year, mon, day);
		if (getchar() != '\n') {
			end = 1;
			break;
		}
		else {
			leap = YearCheck(*year);
			if (*mon > 12 || *mon < 1) {
				printf("다시입력하세요\n");
			}
			else if (leap == 0 && *day > month[*mon - 1]) {    //윤년X일때
				printf("다시입력하세요\n");
			}
			else if (leap == 1 && *day > leapmonth[*mon - 1])  //윤년일떄
			{

				printf("다시입력하세요\n");
			}
			else break;
		}

	}
	return end;

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
int Daysum(int *year, int *mon, int *day, int *month)
{
	int sum = 0, moon, i;


	for (i = 1900; i < *year; i++)
	{
		moon = YearCheck(i);
		if (moon == 1)
			sum += 366;
		else
			sum += 365;
	}
	moon = YearCheck(*year);
	for (i = 1; i < *mon; i++)
	{
		sum += month[i - 1];
		if (moon == 1)
		{
			if (*mon > 2 && i == 1)
				sum += 1;
		}
	}

	sum += *day;

	return sum;
}