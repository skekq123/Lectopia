#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int Input();
int main()
{
	int egg, count=0;
	while (1) {
		egg = Input();
		while (1) {
			if (egg < 150) {
				printf("* ���߸��� ������ �峭���� ���ÿ� ~ ^^\n");
				break;
			}
			else if (egg > 500) {
				printf("* Ÿ���� ������ �峭���� ���ÿ� ~ ^^\n");
				break;
			}
			else {
				count++;
				printf("���� �ް��� �� : %d\n", count);
				break;
			}
		}
		if (count == 10)
		{
			printf("\n***�ް� ������ �������ϴ�.\n");
			break;
		}
	}
	return 0;
}
int Input()
{
	int egg, res;
	while (1) {
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		res = scanf("%d", &egg);
		if (res != 1)
		{
			Myflush();
			printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
		}
		else 
			break;
	}
			return egg;
}
void Myflush()
{
	while (getchar() != '\n');
}