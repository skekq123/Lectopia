#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{
	int day, sum=0, i, j, count = 0;
	while (1) {
		printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
		scanf("%d", &day);
		if (getchar() == '\n') break;

		else
		{
			Myflush();
			printf("�ٽ� �Է��ϼ���.\n");
		}
	}
	for (i = 1; ;i++)
	{
		for (j = 0; j < i; j++)
		{
			sum += i; // �Ѱ��� ����
			count++;  // ���� ī��Ʈ
			if (count == day)
				break;
		}
		if (count == day)
			break;
	}
	printf("�ٹ��� : %d�� / �� ��ȭ �� %d��\n", day, sum);
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}
