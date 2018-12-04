#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{
	int day, sum=0, i, j, count = 0;
	while (1) {
		printf("* 기사의 근무일수를 입력하시오 : ");
		scanf("%d", &day);
		if (getchar() == '\n') break;

		else
		{
			Myflush();
			printf("다시 입력하세요.\n");
		}
	}
	for (i = 1; ;i++)
	{
		for (j = 0; j < i; j++)
		{
			sum += i; // 총갯수 누적
			count++;  // 날자 카운트
			if (count == day)
				break;
		}
		if (count == day)
			break;
	}
	printf("근무일 : %d일 / 총 금화 수 %d개\n", day, sum);
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}
