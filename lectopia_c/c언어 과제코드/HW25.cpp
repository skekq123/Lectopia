#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996)
int Input(int random);
void Myflush();
int main()
{
	int random, count;
	srand((unsigned int)time(NULL));

	random = rand() % 100 + 1; // 맞춰야할 난수 랜덤으로 생성 저장
	count = Input(random);
	printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.\n",count);
	return 0;
}
int Input(int random)
{
	int num, num2=0, num3=101, count = 0, res;


	while (1)
	{
		printf("# 숫자를 입력하시오 : ");
		res = scanf("%d", &num);
		

		if (res != 1 || num > 100 || num < 0)  //범위밖 입력했을때
		{
			Myflush();
			printf("문자 및 범위 밖의 값을 입력하셨습니다. 다시 입력하세요.\n");
		}
		else
			count++;
		if (num == random) // 같으면 while 탈출
			break;
		while (1) {
			if (res != 1 || num > 100 || num < 0)
				break;

			else if (random > num)
			{
				num2 = num;
				printf("%d보다는 크고 %d보다 작습니다.\n", num, num3);
				
				break;
			}
			else if (random < num)
			{
				
				printf("%d보다는 크고 %d보다 작습니다.\n", num2, num);
				num3 = num;
				break;
			}
		}


	}
	return count;
}
void Myflush()
{
	while (getchar() != '\n');
}