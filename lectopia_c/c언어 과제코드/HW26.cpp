#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
void Myflush();
int Input();
int Output();
int main()
{

	int win = 0, draw = 0, lose = 0, score;

	srand((unsigned int)time(NULL));
	while (1) {
		score = Output();
		if (score == 2)
			win++;
		else if (score == 1)
			draw++;
		else
			lose++;
		if (lose > 0)
			break;
	}
	printf("���Ӱ�� : %d ��, %d ��\n", win, draw);

	return 0;
}
int Input()
{
	int num, res;
	while (1) {
		printf("# ������ 1, ������2, ���� 3 �߿��� �����ϼ��� : ");
		res = scanf("%d", &num);
		while (1) {
			if (res != 1) {
				Myflush();
				printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
				break;
			}
			return num;
		}
	}

}
void Myflush()
{
	while (getchar() != '\n');
}
int Output()
{
	int number, random, lose;
	while (1)
	{
		random = rand() % 3 + 1;
		number = Input();

		while (1) {
			if (random == 1) {
				if (number == 1) {
					printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
					return 1;
					break;
				}
				else if (number == 2) {
					printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n"); // ���� ������, ���Ӱ��)
					return 0;
					break;
				}
				else
				{
					printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
					return 2;
					break;
				}
			}
			else if (random == 2)
			{
				if (number == 1)
				{
					printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
					return 2;
					break;
				}
				else if (number == 2)
				{
					printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
					return 1;
					break;
				}
				else
					printf("����� �� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n"); // ���� ������, ���Ӱ��)
				return 0;
				break;
			}
			else
			{
				if (number == 1)
				{
					printf("����� ���� ����, ��ǻ�ʹ� �� ���� : ����� �����ϴ�.\n"); // ���� ������, ���Ӱ��)
					return 0;
					break;
				}
				else if (number == 2)
				{
					printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
					return 2;
					break;
				}
				else
					printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
				return 1;
				break;
			}

		}
		if (lose == 1)
			break;
	}

}