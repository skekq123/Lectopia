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
		printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
		res = scanf("%d", &code);
		if (res == 1 && code > 0 && code < 4)
			break;
		else {
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	return code;
}
int Input2()
{
	int amount, res;
	while (1) {
		printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
		res = scanf("%d", &amount);
		if (res == 1)
			break;
		else
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
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
		sprintf(ch, "(������)");
	else if (code == 2)
		sprintf(ch, "(�����)");
	else
		sprintf(ch, "(������)");

	printf("# ������ڵ� : %d%s\n", code, ch);
	printf("# ��뷮 : %d ton\n", amount);
	printf("# �Ѽ������ : %d��\n", fee);

}
void Myflush()
{
	while (getchar() != '\n');
}