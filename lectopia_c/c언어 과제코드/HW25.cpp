#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
int Input(int random);
void Myflush();
int main()
{
	int random, count;
	srand((unsigned int)time(NULL));

	random = rand() % 100 + 1; // ������� ���� �������� ���� ����
	count = Input(random);
	printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.\n",count);
	return 0;
}
int Input(int random)
{
	int num, num2=0, num3=101, count = 0, res;


	while (1)
	{
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		res = scanf("%d", &num);
		

		if (res != 1 || num > 100 || num < 0)  //������ �Է�������
		{
			Myflush();
			printf("���� �� ���� ���� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
		}
		else
			count++;
		if (num == random) // ������ while Ż��
			break;
		while (1) {
			if (res != 1 || num > 100 || num < 0)
				break;

			else if (random > num)
			{
				num2 = num;
				printf("%d���ٴ� ũ�� %d���� �۽��ϴ�.\n", num, num3);
				
				break;
			}
			else if (random < num)
			{
				
				printf("%d���ٴ� ũ�� %d���� �۽��ϴ�.\n", num2, num);
				num3 = num;
				break;
			}
		}


	}
	return count;
}
void Myflush()
{
	while (getchar() != '\n');
}