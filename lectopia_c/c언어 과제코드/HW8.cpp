#include<stdio.h>

int main()
{
	int his, liter, art, sum;
	double avg;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf_s("%d%d%d", &his, &liter, &art);

	sum = his + liter + art; // ����
	avg = (double)sum / 3; // ���

	printf("������ %d �̰� ����� %.2lf �Դϴ�.\n", sum, avg);


	return 0;
}