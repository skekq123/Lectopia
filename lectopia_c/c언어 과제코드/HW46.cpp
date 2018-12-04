#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
void Input(int *start, int *end);
char Input2(int *start, int *end);
void Output(char ch, int *start, int *end);
int main()
{
	int start, end;
	char ch;
	Input(&start, &end);
	ch = Input2(&start, &end);
	Output(ch, &start, &end);
		
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}
void Input(int *start, int *end)
{
	while (1) {
		printf("# 시작 값을 입력하세요 : ");
		scanf("%d", start);
		if (*start > 0) {
			if (getchar() == '\n')
				break;
		}
		else
			Myflush();
		
	}
	while (1) {
		printf("# 끝 값을 입력하시오 : ");
		scanf("%d", end);
		if (*end > *start && getchar() == '\n')
			break;
		else
			Myflush();
	}
}char Input2(int *start, int *end)
{
	char ch;
	while (1) {
		printf("*%d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", *start, *end);
		scanf(" %c", &ch);
		if (ch == 'e' || ch == 'o' || ch == 'E' || ch == 'O')
			break;
		else
			Myflush();

	}
	return ch;
}
void Output(char ch, int *start, int *end)
{
	int sum = 0, i;
	if (ch == 'e' || ch == 'E')
	{
		printf("%d~%d 까지의 짝수(", *start, *end);
		for (i = *start; i <= *end; i++)
		{
			if (i % 2 == 0) {
				printf("%d ", i);
				sum += i;
			}
		}
		printf(")의 합은 %d입니다.\n", sum);
	}
	else
	{
		printf("%d~%d 까지의 홀수(", *start, *end);
		for (i = *start; i <= *end; i++)
		{
			if (i % 2 == 1) {
				printf("%d ", i);
				sum += i;
			}
		}
		printf(")의 합은 %d입니다.\n", sum);
	}
}
