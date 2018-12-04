#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{	
	int num, res, count=0, res2;
	unsigned int hex = 0x80000000;
	while (1) {
		printf("* 10진수 정수를 입력하시오 : ");
		res2 = scanf("%d", &num);
		if (res2 == 1)
			break;
		else
		{
			Myflush();
			printf("문자를 입력하셨습니다. 다시 입력하세요.\n");
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