#include<stdio.h>
#pragma warning(disable : 4996)
int InputAge();
int InputNum();
void Output(int total, int sale, int pay);
int main()
{
	int age, num, fee, total, sale, pay;

	age = InputAge();
	num = InputNum();
	
	if (age <= 7)
		fee = 500;
	else if (age <= 13)
		fee = 700;
	else if (age <= 19)
		fee = 1000;
	else if (age <= 55)
		fee = 1500;
	else
		fee = 500;

	total = num * fee;

	if (num >= 5) {
		pay = (total) * 9 / 10;
		sale = total / 10;
	}

	else {
		pay = total;
		sale = 0;
	}
	Output(total, sale, pay);
	return 0;
}
int InputAge()
{
	int age;

	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d",&age);

	return age;
}
int InputNum()
{
	int num;
	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d",&num);

	return num;
}
void Output(int total, int sale, int pay)
{
	printf("����� => %d��\n", total);
	printf("���αݾ� => %d��\n", sale);
	printf("�����ݾ� => %d��\n", pay);
}