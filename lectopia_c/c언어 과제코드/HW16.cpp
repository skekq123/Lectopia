#include<stdio.h>
#pragma warning (disable : 4996)
int Input();
int Calculation(int count);
void Output(int fee);
int main()
{
	int fee, count;
	
	count = Input();
	fee = Calculation(count);
	Output(fee);

	return 0;
}
int Input()
{
	int count;

	printf("역수를 입력하시오 : ");
	scanf("%d", &count);

	return count;
}
int Calculation(int count)
{
	int fee;

	if (count <= 5)
		fee = 600;
	else if (count <= 10)
		fee = 800;
	else
	{	
		
		if ((count - 10) % 2 == 0)
			fee = 800 + (count - 10) / 2 * 100;
		else
			fee = 800 + (count - 9) / 2 * 100;
		
	}
	return fee;
}
void Output(int fee)
{
	printf("요금 : %d\n",fee);
}