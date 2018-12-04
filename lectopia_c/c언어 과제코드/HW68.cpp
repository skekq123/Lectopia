#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#pragma warning (disable : 4996)
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/
int availability_check(char *resident_number);
int length_character_check(char *resident_number);
int date_check(char *resident_number);
int YearCheck(int year);
int identification_check(char *resident_number);
int gender_check(char *resident_number);

int main()
{
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418"
	};
	int i, count;    /* 검사할 주민등록번호의 개수 계산*/

	count = sizeof(resident_number) / sizeof(resident_number[0]);

	for (i = 0; i < count; i++)     /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availability_check(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availability_check()함수: 주민등록번호 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효하면TRUE, 유효하지 않으면FALSE 리턴
------------------------------------------------------------------*/
int availability_check(char *resident_number)
{
	if (length_character_check(resident_number)) /* 길이 및 숫자문자 유효성검사*/
	{
		if (date_check(resident_number))  /* 날짜검사*/
		{
			if (identification_check(resident_number))  /* 인식자 오류체크*/
			{
				if(gender_check(resident_number))

				return TRUE;
			}
		}
	}
	return FALSE;
}
int length_character_check(char *resident_number) // 길이13개, 0~9의숫자문자만 가지고있으면 TRUE
{
	int i, len, count =0;
	len = strlen(resident_number);
	if (len == 13)
	{
		for (i = 0; i < len; i++)
		{
			if (resident_number[i] >= '0' && resident_number[i] <= '9')
				count++;
		}
		if (count == 13) {
			return TRUE;
		}
		else
			return FALSE;
	}
	else return FALSE;
}
int date_check(char *resident_number)
{
	int i, year, month, day, number[13], yearcheck;
	int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int leapmonth[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	
	for (i = 0; i < 13; i++)
	{
		number[i] = resident_number[i] - '0';
	}
	if (number[6] == 3 || number[6] == 4)
	{
			year = 2000 + number[0] * 10 + number[1];
	}
	else if (number[6] == 1 || number[6] == 2)
	{
		year = 1900 + number[0] * 10 + number[1];
	}
	else
		return FALSE;
	month = (number[2] * 10 + number[3]);
	day = (number[4] * 10 + number[5]);
	if (day == 0)
		return FALSE;
	yearcheck = YearCheck(year);
	if (month > 12 || month < 1) {
		return FALSE;
	}
	else if (yearcheck == FALSE && day > mon[month - 1]) {    //윤년X일때
		return FALSE;
	}
	else if (yearcheck == TRUE && day > leapmonth[month - 1])  //윤년일떄
	{
		return FALSE;
	}
	else 
		return TRUE;
}
int YearCheck(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return TRUE; //윤년
			}
			else
			{
				return FALSE; //평년
			}
		}
		else
		{

			return TRUE; //윤년
		}

	}
	else
	{
		return FALSE; //평년
	}
}
int identification_check(char *resident_number)
{
	int i, sum=0;

	for (i = 0; i < 12; i++)
	{
		sum += resident_number[i] - '0';
	}
	
	if (sum % 10 == resident_number[12] - '0')
		return TRUE;
	else
		return FALSE;
}
int gender_check(char *resident_number)
{
	int number[13], i, year;

	for (i = 0; i < 13; i++)
	{
		number[i] = resident_number[i] - '0';
	}
	if (number[6] == 3 || number[6] == 4)
	{
		year = 2000 + number[0] * 10 + number[1];
	}
	else
		year = 1900 + number[0] * 10 + number[1];
	
	if (year < 2000) {
		if (number[6] == 1 || number[6] == 2)
		{
			return TRUE;
		}
		else
			return FALSE;
	}
	else 
		if (number[6] == 3 || number[6] == 4)
		{
			return TRUE;
		}
		else
			return FALSE;

}