#include<stdio.h>
#pragma warning (disable : 4996)
int getBit(int num, int i);
int setBit(int num, int i);
int clearBit(int num, int i);
int clearBitsMSBthroughtI(int num, int i);
int clearBitsIthrought0(int num, int i);
int updateBit(int num, int i, int value);
int updateBit(int num, int i, int value);
void Myflush();
int main()
{
	int num, i, get, set, clear, msbthrought, ithrought0, value, update;
	while (1) {
		printf("num���� �Է� : ");
		scanf("%d", &num);
		if (getchar() == '\n') break;
		else {
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	while (1) {
		printf("i���� �Է� : ");
		scanf("%d", &i);
		if(i < 0) {
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
		else if (getchar() == '\n' && i >= 0) break;

		else {
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	get = getBit(num, i);
	printf("2�� %d�� bit �� = %d\n",i, get);
	set = setBit(num, i);
	printf("num������ 2�� %d�� bit���� 1�� ���� �� num�� = %d\n", i,set);
	clear = clearBit(num, i);
	printf("num������ 2�� %d�� bit���� 0���� ���� �� num�� = %d\n", i, clear);
	msbthrought = clearBitsMSBthroughtI(num, i);
	printf("MSB���� %d�� ��Ʈ���� ��� 0���� ���� �� num�� = %d\n", i, msbthrought);
	ithrought0 = clearBitsIthrought0(num, i);
	printf("%d�� ��Ʈ ~ 0�� ��Ʈ���� ��� 0���� ���� �� num�� = %d\n",i,  ithrought0);
	while (1) {
		printf("%d�� ��Ʈ�� ���� 0 �Ǵ� 1 �߿� �������� �ٲٽðڽ��ϱ�?", i);
		scanf("%d", &value);
		if (value != 0 && value != 1)
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
		else if (getchar() == '\n') break;
		else
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	update = updateBit(num, i, value);
	printf("%d�� ��Ʈ�� ���� value(0 or 1)������ ������ �� num�� = %d\n", i, update);
	return 0;
}
int getBit(int num, int i) //num������ 2�� i�� bit���� 0�̸� 0,1�̸� 1�� ����
{
	unsigned hex = 0x00000001;
	int res, get;
	
		hex <<= i;
		res = hex & num;
		if (res == 0)
		{
			get = 0;
			return get;
		}
		else
		{
			get = 1;
			return get;
		}
}
int setBit(int num, int i) //num������ 2�� i�� bit���� 1�� ���� �� num�� ����
{
	unsigned hex = 0x00000001;

	hex <<= i;
	num = num | hex;

	return num;
}
int clearBit(int num, int i) // num������ 2�� i�� bit���� 0���� ���� �� num�� ����
{
	unsigned hex = 0x00000001;

	hex <<= i;
	num = 	num & ~hex;

	return num;
}
int clearBitsMSBthroughtI(int num, int i) //MSB���� i�� ��Ʈ���� ��� 0���� ����
{
	unsigned hex = 0x80000000;
	int j;
	for (j = 31; j >= i; j--)
	{
		num = num & ~hex;
		hex >>= 1;
	}
	return num;

}
int clearBitsIthrought0(int num, int i)  // i�� ��Ʈ ~ 0�� ��Ʈ���� ��� 0���� ����
{
	unsigned hex = 0x00000001;
	int j;
	for (j = 0; j <= i; j++)
	{
		num = num & ~hex;
		hex <<= 1;
	}
	return num;

}
int updateBit(int num, int i, int value) // i�� ��Ʈ�� ���� value(0 or 1)������ ����
{
	unsigned hex = 0x00000001;
	
	if (value == 0)
	{
		hex <<= i;
		num = num & ~hex;
	}
	else if (value == 1)
	{
		hex <<= i;
		num = num | hex;
	}
	
	return num;
}
void Myflush()
{
	while (getchar() != '\n');
}