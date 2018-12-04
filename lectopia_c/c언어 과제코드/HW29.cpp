#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int inputUnit(char *msg);
int inputUnit2(char *msg);
int transNumber(int num);
void Output(int P1, int P2, int N);
int main()
{
	int P1, P2, N;

	P1 = inputUnit("시작 값(P1) : ");
	P2 = inputUnit("끝 값(P2) : ");
	N = inputUnit2("고집수(N) : ");

	
	
	Output(P1, P2, N);
	
	return 0;
}
int transNumber(int num)
{
	int hund, ten, one, tho ,end;
	if (num <= 999) {
		hund = num / 100;
		ten = (num - hund * 100) / 10;
		one = num - hund * 100 - ten * 10;
	}
	else {
		tho = num / 1000;
		hund = (num - tho * 1000) / 100;
		ten = (num - tho * 1000 - hund * 100) / 10;
		one = num - tho * 1000 - hund * 100 - ten * 10;
	}
	if (num >= 1000)
		end = tho * hund * ten * one;
	else if (num >= 100)
		end = hund * ten * one;
	else
		end = ten * one;
		
	return end;
}
int inputUnit(char *msg)
{
	int a, res;

	while (1)
	{
		printf("%s", msg);
		res = scanf("%d", &a);
		if (a < 100 || a > 10000 || a < 0)
		{
			Myflush();
			printf("다시 입력하세요.\n");
		}
		else if (res == 1) break;
		else if(res != 1){
			Myflush();
			printf("다시 입력하세요.\n");
		}
		

	}
	return a;
}
int inputUnit2(char *msg)
{
	int a, res;
	while (1)
	{
		printf("%s", msg);
		res = scanf("%d", &a);
		
		
		if (a<1 || a > 10) {
			Myflush();
			printf("다시 입력하세요.\n");
		}
		else if (res == 1) break;
	}
	return a;
}
void Myflush()
{
	while (getchar() != '\n');
}
void Output(int P1, int P2, int N)
{
	int temp, temp2, count, total=0, num;

	for (temp2 = P1; temp2 <= P2; temp2++)
	{
		num = temp2;
		count = 0;
		while (1)
		{
			temp = transNumber(num);
			num = temp;
			count++;
			if (num < 9)
				break;
		}
		if (count == N) {
			printf("%d\n", temp2);
			total++;
		}
	}

	printf("총 개수 : %d개\n", total);
}