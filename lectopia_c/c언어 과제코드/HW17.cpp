#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
void Output(char *name, double height, char sex);
void Myflush();
int main()
{
	char name[100], sex;
	double height;
	int res;

	printf("# ���� �Է� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0'; // fgets�Լ��� ������ ���� ó��

	while (1) {
		printf("# Ű �Է�(cm����) : ");
		res = scanf("%lf", &height);
		if (res == 1)
			break;
		else
		{
			Myflush();
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
		}
	}
	while (1) {
		printf("# �����Է�(M/F) : ");
		res = scanf(" %c", &sex);
		if (sex == 'M' || sex == 'F')
			break;
		else
		{
			Myflush();
			printf("�߸� �Է��Ͽ����ϴ�. M/F�߿��� �ϳ��� �Է��ϼ���.\n");
		}
	}
	Output(name, height, sex);
	return 0;
}
void Output(char *name, double height, char sex)
{
	

	if (sex == 'M')
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	else if (sex == 'F')
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
}
void Myflush()
{
	while (getchar() != '\n');
}
