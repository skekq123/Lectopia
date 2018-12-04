#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
void Myflush();
int Input();
int Output();
int main()
{

	int win = 0, draw = 0, lose = 0, score;

	srand((unsigned int)time(NULL));
	while (1) {
		score = Output();
		if (score == 2)
			win++;
		else if (score == 1)
			draw++;
		else
			lose++;
		if (lose > 0)
			break;
	}
	printf("게임결과 : %d 승, %d 무\n", win, draw);

	return 0;
}
int Input()
{
	int num, res;
	while (1) {
		printf("# 바위는 1, 가위는2, 보는 3 중에서 선택하세요 : ");
		res = scanf("%d", &num);
		while (1) {
			if (res != 1) {
				Myflush();
				printf("잘못 입력하셨습니다. 다시 입력하세요.\n");
				break;
			}
			return num;
		}
	}

}
void Myflush()
{
	while (getchar() != '\n');
}
int Output()
{
	int number, random, lose;
	while (1)
	{
		random = rand() % 3 + 1;
		number = Input();

		while (1) {
			if (random == 1) {
				if (number == 1) {
					printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n");
					return 1;
					break;
				}
				else if (number == 2) {
					printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 당신이 졌습니다.\n"); // 지면 끝나고, 게임결과)
					return 0;
					break;
				}
				else
				{
					printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
					return 2;
					break;
				}
			}
			else if (random == 2)
			{
				if (number == 1)
				{
					printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
					return 2;
					break;
				}
				else if (number == 2)
				{
					printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n");
					return 1;
					break;
				}
				else
					printf("당신은 보 선택, 컴퓨터는 가위 선택 : 당신이 졌습니다.\n"); // 지면 끝나고, 게임결과)
				return 0;
				break;
			}
			else
			{
				if (number == 1)
				{
					printf("당신은 바위 선택, 컴퓨터는 보 선택 : 당신이 졌습니다.\n"); // 지면 끝나고, 게임결과)
					return 0;
					break;
				}
				else if (number == 2)
				{
					printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
					return 2;
					break;
				}
				else
					printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
				return 1;
				break;
			}

		}
		if (lose == 1)
			break;
	}

}