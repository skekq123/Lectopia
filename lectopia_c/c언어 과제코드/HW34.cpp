#include<stdio.h>
#pragma warning (disable : 4996)
int menu();
void Myflush();
void openFan(unsigned char *hex);
void displayFan(unsigned char *hex);
void offFan(unsigned char *hex);
void reverseFan(unsigned char *hex);
int main()
{
	int select, end = 0, start = 0;
	unsigned char hex = 0;
	while (1)
	{
		start++;
		select = menu();
		if (start == 1)
		{
			printf("8번FAN  7번FAN  6번FAN  5번FAN  4번FAN  3번FAN  2번FAN  1번FAN\n");
			printf("----------------------------------------------------------------\n");
			for (start = 0; start < 8; start++) {

				printf("OFF\t");

			}
			printf("\n");
		}

		switch (select)
		{
		case 1:  openFan(&hex);
			displayFan(&hex);
			break;
		case 2: offFan(&hex);
			displayFan(&hex);
			break;
		case 3:
			reverseFan(&hex);
			displayFan(&hex);
			break;
		case 4:
			printf("종료되었습니다.\n");
			end = 1;
			break;

		}
		if (end == 1) break;
	}

	return 0;
}
int menu()
{
	int select;
	printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환/ 4. 종료 : ");
	while (1)
	{
		scanf("%d", &select);
		printf("----------------------------------------------------------------\n");
		if (getchar() == '\n' && (select == 1 || select == 2 || select == 3 || select == 4))
		{
			return select;
		}

		else {
			Myflush();
			printf("잘못 입력하셨습니다. 다시 입력하세요. \n ");
			printf("----------------------------------------------------------------\n");
		}
	}
}
void Myflush()
{
	while (getchar() != '\n');
}
void  openFan(unsigned char *hex)
{
	int num, i;
	unsigned char hex2 = 0x01;

	printf("Fan 열기 작업 실행 화면\n");
	printf("----------------------------------------------------------------\n");

	while (1)
	{
		printf("* OPEN할 FAN 번호를 입력하시오(1-8) : ");
		scanf("%d", &num);
		printf("----------------------------------------------------------------\n");
		if (getchar() == '\n' && num >= 1 && num <= 8)
		{
			for (i = 1; i < num; i++) {
				hex2 <<= 1;
			}
			*hex = (*hex | hex2);
			break;
		}
		else
		{
			Myflush();
			printf("다시 입력하세요.\n");
			printf("----------------------------------------------------------------\n");
		}

	}
}
void displayFan(unsigned char *hex)
{
	unsigned char hex2 = 0x80, temp1, temp2;
	int count = 0;
	temp2 = *hex;
	printf("8번FAN  7번FAN  6번FAN  5번FAN  4번FAN  3번FAN  2번FAN  1번FAN\n");
	printf("----------------------------------------------------------------\n");
	while (1)
	{
		temp1 = hex2 & temp2;
		temp2 <<= 1;
		if (temp1 == 0)
			printf("OFF\t");
		else
			printf("ON\t");

		count++;
		if (count == 8)
			break;

	}
	printf("\n----------------------------------------------------------------\n");

}
void offFan(unsigned char *hex)
{
	int num, i;
	unsigned char hex2 = 0x01;

	printf("Fan 닫기 작업 실행 화면\n");
	printf("----------------------------------------------------------------\n");

	while (1)
	{
		printf("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");
		scanf("%d", &num);
		printf("----------------------------------------------------------------\n");
		if (getchar() == '\n' && num >= 1 && num <= 8)
		{
			for (i = 1; i < num; i++) {
				hex2 <<= 1;
			}

			*hex = (*hex ^ hex2);
			break;
		}
		else
		{
			Myflush();
			printf("다시 입력하세요.\n");
			printf("----------------------------------------------------------------\n");
		}

	}
}
void reverseFan(unsigned char *hex)
{
	printf("Fan 전체 전환 작업 실행 화면\n");
	printf("----------------------------------------------------------------\n");

	*hex = ~*hex;
}