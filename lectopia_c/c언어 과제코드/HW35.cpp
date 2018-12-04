#include<stdio.h>
#pragma warning (disable : 4996)
int Input1();
int Input2();
int Calculation(int code, int amount);
void Output(int code, int amount, int fee);
void Myflush();
int main()
{
	int code, amount, fee;

	code = Input1();
	amount = Input2();
	
	fee = Calculation(code, amount);

	Output(code, amount, fee);

	return 0;
}
int Input1()
{
	int code, res;
	while (1) {
		printf("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
		res = scanf("%d", &code);
		if (res == 1 && code > 0 && code < 4)
			break;
		else {
			Myflush();
			printf("다시 입력하세요.\n");
		}
	}
	return code;
}
int Input2()
{
	int amount, res;
	while (1) {
		printf("* 사용량을 입력하시오(ton단위) : ");
		res = scanf("%d", &amount);
		if (res == 1)
			break;
		else
		{
			Myflush();
			printf("다시 입력하세요.\n");
		}
	}
	return amount;
}
int Calculation(int code, int amount)
{
	int fee;

	switch (code)
	{
	case 1: fee = amount * 50; break;
	case 2: fee = amount * 45; break;
	default: fee = amount * 30;
	}
	fee = fee + fee / 20;

	return fee;
}
void Output(int code, int amount, int fee)
{
	char ch[20];

	if (code == 1)
		sprintf(ch, "(가정용)");
	else if (code == 2)
		sprintf(ch, "(상업용)");
	else
		sprintf(ch, "(공업용)");

	printf("# 사용자코드 : %d%s\n", code, ch);
	printf("# 사용량 : %d ton\n", amount);
	printf("# 총수도요금 : %d원\n", fee);

}
void Myflush()
{
	while (getchar() != '\n');
}