#include<stdio.h>
#include<windows.h>
#include<conio.h>
#pragma warning (disable : 4996)
#define LIGHTRED 12
#define LIGHTBLUE 9
#define LIGHTGRAY 7
#define BLACK 0
void textcolor(int foreground, int background);
void gotoxy(int x, int y);
void Output(int *year, int *month, int *day);
int YearCheck(int year);
int Daysum(int *year, int *month, int *day, int *mon);
int Week(int sum);
void Page(int *year, int *month, int *day);
int main()
{	
	int year = 2016, month = 7, day = 1;
	Output(&year, &month, &day);
	Page(&year, &month, &day);

	return 0;
}
void textcolor(int foreground, int background)
{
	int color = foreground + background*16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  color);
}
void gotoxy(int x, int y)
{
	COORD Pos = {(short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Output(int *year, int *month, int *day)
{
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapmon[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, leapcheck, sum, startday, count = 0;
	gotoxy(32, 3);
	textcolor(LIGHTGRAY, BLACK);
	printf("\t  [%d  .   %d]\t\t  ", *year, *month);
	gotoxy(32, 5);
	textcolor(LIGHTRED, BLACK);
	printf("SUN");
	textcolor(LIGHTGRAY, BLACK);
	printf("  MON  TUE  WED  THU  FRI");
	textcolor(LIGHTBLUE, BLACK);
	printf("  SAT");
	gotoxy(32, 6);
	textcolor(LIGHTGRAY, BLACK);
	printf("-------------------------------------\n\n");
	leapcheck = YearCheck(*year);
	sum = Daysum(year, month, day, mon);
	startday = Week(sum);
	if (leapcheck == 1)
	{
		gotoxy(30, 7);
		for (i = 0; i < startday; i++)
		{
			printf("     ");
		}
		for (i = 1; i <= leapmon[*month - 1]; i++)
		{
			
			if ((i + startday)% 7 == 0)
			{
				textcolor(LIGHTBLUE, BLACK);
			}
			else if ((i + startday) % 7 == 1)
			{
				textcolor(LIGHTRED, BLACK);
			}
				else 
					textcolor(LIGHTGRAY, BLACK);

			printf("  %3d", i);

				if ((i + startday) % 7 == 0)
				{
					count++;
					gotoxy(30, 7+count);
				}
			
		}
	}
	else if (leapcheck == 0)
	{

		gotoxy(30, 7);
		for (i = 0; i < startday; i++)
		{
			printf("     ");
		}
		for (i = 1; i <= mon[*month - 1]; i++)
		{
			if ((i + startday) % 7 == 0)
			{
				textcolor(LIGHTBLUE, BLACK);
			}
			else if ((i + startday) % 7 == 1)
			{
				textcolor(LIGHTRED, BLACK);
			}
			else
				textcolor(LIGHTGRAY, BLACK);
			printf("  %3d", i);

			if ((i + startday) % 7 == 0)
			{
				count++;
				gotoxy(30, 7 + count);
			}

		}
	}
	gotoxy(30, 8 + count);
	textcolor(LIGHTGRAY, BLACK);
	printf("\n \t\tw : 전 년도 / s : 다음 년도 / a : 전 월 / d : 다음 월 / ESC : 종료\n");

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
int Daysum(int *year, int *month, int *day, int *mon)
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
	for (i = 1; i < *month; i++)
	{
		sum += mon[i - 1];
		if (moon == 1)
		{
			if (*month > 2 && i == 1)
				sum += 1;
		}
	}

	sum += *day;

	return sum;
}
int Week(int sum)
{
	int mod = sum % 7;

	return mod;	
}
void Page(int *year, int *month, int *day)
{
	char ch, end=0;
	while (1) {
		while (1) {
			ch = getch();
			switch (ch) {
			case 'w':
			{
				system("cls");
				*year = *year -1;
				Output(year, month, day);

			}
			break;
			case 'a':
			{
				system("cls");
				if (*month == 1) {
					*year = *year - 1;
					*month = 12;
				}
				else
				*month = *month - 1;
				Output(year, month, day);
			}
			break;
			case 's':
			{
				system("cls");
				*year = *year + 1;
				Output(year, month, day);
			}
			break;
			case 'd':
			{
				system("cls");
				if (*month == 12) {
					*year = *year + 1;
					*month = 1;
				}
				else
					*month = *month + 1;
				Output(year, month, day);
			}
				break;
			case 27:
				end = 1;
				break;
			}
			if (end == 1)
				break;
		}
		if (end == 1)
		{
			printf("종료되었습니다.\n");
		}
			break;
	}
}
