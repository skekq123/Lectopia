#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{
	int num, count = 0, sum = 0;
	for (;;)
	{
		while (1) {
			printf("0보다 큰수를 입력하시오(%d 번째) : ", count + 1);
			scanf("%d", &num);
			if (getchar() == '\n') break;

			else
			{
				Myflush();
			}
		}
		if (num > 0) {
			sum += num;
			count++;
		}
		if (count == 5)
			break;
	}
	printf("입력된 값의 총 합 : %d\n",sum);
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}
