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
				printf("* 메추리알 가지고 장난하지 마시오 ~ ^^\n");
				break;
			}
			else if (egg > 500) {
				printf("* 타조알 가지고 장난하지 마시오 ~ ^^\n");
				break;
			}
			else {
				count++;
				printf("현재 달걀의 수 : %d\n", count);
				break;
			}
		}
		if (count == 10)
		{
			printf("\n***달걀 포장이 끝났습니다.\n");
			break;
		}
	}
	return 0;
}
int Input()
{
	int egg, res;
	while (1) {
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		res = scanf("%d", &egg);
		if (res != 1)
		{
			Myflush();
			printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
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