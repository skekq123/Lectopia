#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#pragma warning (disable : 4996)
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε�Ϲ�ȣ ����*/
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
	int i, count;    /* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/

	count = sizeof(resident_number) / sizeof(resident_number[0]);

	for (i = 0; i < count; i++)     /* �ֹε�Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
	{
		if (availability_check(resident_number[i]) == TRUE)
		{
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else
		{
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availability_check()�Լ�: �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�ϸ�TRUE, ��ȿ���� ������FALSE ����
------------------------------------------------------------------*/
int availability_check(char *resident_number)
{
	if (length_character_check(resident_number)) /* ���� �� ���ڹ��� ��ȿ���˻�*/
	{
		if (date_check(resident_number))  /* ��¥�˻�*/
		{
			if (identification_check(resident_number))  /* �ν��� ����üũ*/
			{
				if(gender_check(resident_number))

				return TRUE;
			}
		}
	}
	return FALSE;
}
int length_character_check(char *resident_number) // ����13��, 0~9�Ǽ��ڹ��ڸ� ������������ TRUE
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
	else if (yearcheck == FALSE && day > mon[month - 1]) {    //����X�϶�
		return FALSE;
	}
	else if (yearcheck == TRUE && day > leapmonth[month - 1])  //�����ϋ�
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
				return TRUE; //����
			}
			else
			{
				return FALSE; //���
			}
		}
		else
		{

			return TRUE; //����
		}

	}
	else
	{
		return FALSE; //���
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