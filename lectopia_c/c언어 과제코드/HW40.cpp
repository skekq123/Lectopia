#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{
	int money, cream , shrimp , cola, res, end=0;

	while (1) {
		printf("���� ����� ���� �ݾ� �Է� : ");
		res = scanf("%d", &money);
		if (res == 1 && money < 1600)
		{
			printf("�ݾ��� �ʹ� ���ų�, �ܵ��� ������ ������ �����ϴ�. �ٽ� �Է��ϼ���. \n");
		}
		else if(getchar() == '\n') break;
		else
		{
			end = 1;
			printf("����Ǿ����ϴ�. \n");
			break;
		}
			
	}
	for (cream = 500; cream < money; cream += 500) {
		for (shrimp = 700; shrimp < money; shrimp += 700) {
			for (cola = 400; cola <= money; cola += 400) {
				if (cream + shrimp + cola == money)
					printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", cream/500, shrimp/700, cola/400);
			}
		}
	}
	if(end != 1)
	printf("��� �����Ͻðڽ��ϱ�?\n");
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}

