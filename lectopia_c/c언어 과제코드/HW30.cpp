#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{	
	int num, res, count=0, res2;
	unsigned int hex = 0x80000000;
	while (1) {
		printf("* 10���� ������ �Է��Ͻÿ� : ");
		res2 = scanf("%d", &num);
		if (res2 == 1)
			break;
		else
		{
			Myflush();
			printf("���ڸ� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
		}
	}
	printf("%d(10) = ", num);
	
	while (1) {
		res = num & hex;
		if (res == 0)
			printf("0");
		else
			printf("1");
		hex = hex >> 1;
		count++;
		if (count == 32) {
			printf("(2)\n");
			break;
		}
	}
	
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}