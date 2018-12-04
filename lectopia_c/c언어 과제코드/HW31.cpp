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
		printf("num값을 입력 : ");
		scanf("%d", &num);
		if (getchar() == '\n') break;
		else {
			Myflush();
			printf("다시 입력하세요.\n");
		}
	}
	while (1) {
		printf("i값을 입력 : ");
		scanf("%d", &i);
		if(i < 0) {
			Myflush();
			printf("다시 입력하세요.\n");
		}
		else if (getchar() == '\n' && i >= 0) break;

		else {
			Myflush();
			printf("다시 입력하세요.\n");
		}
	}
	get = getBit(num, i);
	printf("2의 %d승 bit 값 = %d\n",i, get);
	set = setBit(num, i);
	printf("num변수의 2의 %d승 bit값을 1로 만든 후 num값 = %d\n", i,set);
	clear = clearBit(num, i);
	printf("num변수의 2의 %d승 bit값을 0으로 만든 후 num값 = %d\n", i, clear);
	msbthrought = clearBitsMSBthroughtI(num, i);
	printf("MSB부터 %d승 비트까지 모두 0으로 지운 후 num값 = %d\n", i, msbthrought);
	ithrought0 = clearBitsIthrought0(num, i);
	printf("%d승 비트 ~ 0승 비트까지 모두 0으로 지운 후 num값 = %d\n",i,  ithrought0);
	while (1) {
		printf("%d승 비트의 값을 0 또는 1 중에 무엇으로 바꾸시겠습니까?", i);
		scanf("%d", &value);
		if (value != 0 && value != 1)
		{
			Myflush();
			printf("다시 입력하세요.\n");
		}
		else if (getchar() == '\n') break;
		else
		{
			Myflush();
			printf("다시 입력하세요.\n");
		}
	}
	update = updateBit(num, i, value);
	printf("%d승 비트의 값을 value(0 or 1)값으로 변경한 후 num값 = %d\n", i, update);
	return 0;
}
int getBit(int num, int i) //num변수의 2의 i승 bit값이 0이면 0,1이면 1을 리턴
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
int setBit(int num, int i) //num변수의 2의 i승 bit값을 1로 만든 후 num값 리턴
{
	unsigned hex = 0x00000001;

	hex <<= i;
	num = num | hex;

	return num;
}
int clearBit(int num, int i) // num변수의 2의 i승 bit값을 0으로 만든 후 num값 리턴
{
	unsigned hex = 0x00000001;

	hex <<= i;
	num = 	num & ~hex;

	return num;
}
int clearBitsMSBthroughtI(int num, int i) //MSB부터 i승 비트까지 모두 0으로 지움
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
int clearBitsIthrought0(int num, int i)  // i승 비트 ~ 0승 비트까지 모두 0으로 지움
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
int updateBit(int num, int i, int value) // i승 비트의 값을 value(0 or 1)값으로 변경
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