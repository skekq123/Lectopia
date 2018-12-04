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
	printf("* 우물의 깊이를 입력하시오(cm단위) : ");
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

	printf("%.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", deep2, day);
}