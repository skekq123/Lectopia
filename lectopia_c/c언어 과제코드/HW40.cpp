#include<stdio.h>
#pragma warning (disable : 4996)
void Myflush();
int main()
{
	int money, cream , shrimp , cola, res, end=0;

	while (1) {
		printf("현재 당신의 소유 금액 입력 : ");
		res = scanf("%d", &money);
		if (res == 1 && money < 1600)
		{
			printf("금액이 너무 적거나, 잔돈을 남기지 않을수 없습니다. 다시 입력하세요. \n");
		}
		else if(getchar() == '\n') break;
		else
		{
			end = 1;
			printf("종료되었습니다. \n");
			break;
		}
			
	}
	for (cream = 500; cream < money; cream += 500) {
		for (shrimp = 700; shrimp < money; shrimp += 700) {
			for (cola = 400; cola <= money; cola += 400) {
				if (cream + shrimp + cola == money)
					printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", cream/500, shrimp/700, cola/400);
			}
		}
	}
	if(end != 1)
	printf("어떻게 구입하시겠습니까?\n");
	return 0;
}
void Myflush()
{
	while (getchar() != '\n');
}

