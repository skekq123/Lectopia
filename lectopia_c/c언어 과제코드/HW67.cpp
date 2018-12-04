#include<stdio.h>
#pragma warning (disable : 4996)
int InputNum();
int InputNumCheck(int *number, int n);
int main()
{
	int n, number[1000], count;
	while (1) {
		n = InputNum();
		if (getchar() != '\n')
		{
			printf("종료되었습니다.\n");
			break;
		}
		count = InputNumCheck(number, n);
		printf("서로 다른 수의 개수 : %d\n", count);
	}
	return 0;
}
int InputNum()
{
	int n;
	printf("* 입력할 숫자의 개수 : ");
	scanf("%d", &n);

	return n;
}
int InputNumCheck(int *number, int n)
{
	int i,j, count = 0;

	printf("* 숫자 입력 : ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
		for (j = 0; j < i; j++)
			if (number[i] == number[j]) break;
		if (i == j)
			count++;
	}
	return count;
}
