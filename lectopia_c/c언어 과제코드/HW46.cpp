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
		printf("# ���� ���� �Է��ϼ��� : ");
		scanf("%d", start);
		if (*start > 0) {
			if (getchar() == '\n')
				break;
		}
		else
			Myflush();
		
	}
	while (1) {
		printf("# �� ���� �Է��Ͻÿ� : ");
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
		printf("*%d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", *start, *end);
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
		printf("%d~%d ������ ¦��(", *start, *end);
		for (i = *start; i <= *end; i++)
		{
			if (i % 2 == 0) {
				printf("%d ", i);
				sum += i;
			}
		}
		printf(")�� ���� %d�Դϴ�.\n", sum);
	}
	else
	{
		printf("%d~%d ������ Ȧ��(", *start, *end);
		for (i = *start; i <= *end; i++)
		{
			if (i % 2 == 1) {
				printf("%d ", i);
				sum += i;
			}
		}
		printf(")�� ���� %d�Դϴ�.\n", sum);
	}
}
