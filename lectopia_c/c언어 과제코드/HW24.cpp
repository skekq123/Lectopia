#include<stdio.h>
#pragma warning(disable : 4996)
int Input();
int Escape(int deep);
void Output(int deep, int day);
int main()
{
	int deep, day;

	deep = Input();
	day = Escape(deep);
	Output(deep, day);
	return 0;
}
int Input()
{
	int deep;
	printf("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &deep);

	return deep;
}
int Escape(int deep)
{
	int position = 0, day = 0;

	while (1)
	{	
		position += 50;
		day++;
		if (position >= deep)
			break;
		else
			position -= 20;
	}
	if (deep == 0)
		return 0;
	else
	return day;
}
void Output(int deep, int day)
{	
	double deep2;
	deep2 = (double)deep / 100.0;

	printf("%.2lf���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n", deep2, day);
}