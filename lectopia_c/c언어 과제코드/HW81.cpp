#include<stdio.h>
#pragma warning (disable : 4996)
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<memory.h>
#include<conio.h>
#define L printf("|")
#define NL printf("\n")
int menu();
int inputNum();
int** myAlloc(int num);
void myDelete(int **game, int num);
void solorandomNum(int num, int **game);
int practiceGame(int **game, int num);
void VsrandomNum(int num, int **game);
void vsGameOutput(int **game, int **com, int num);
int myNum(int **game, int **com, int num);
int comNum(int **game, int **com, int num);
int whoWin(int mycount, int num, int comcount);
int main()
{
	int select, num, **game, count = 0, end = 0, **com, whoend;
	int comcount = 0, mycount = 0;
	srand((size_t)time(NULL));
	while (1) {
		system("cls");
		select = menu();
		switch (select)
		{
		case 1:
			system("cls");
			num = inputNum();
			game = myAlloc(num);
			system("cls");
			solorandomNum(num, game);
			while (1) {
				count = practiceGame(game, num);
				if (count >= num) {
					printf("게임이 끝났습니다. 메뉴로 돌아가려면 아무키나 누르세요.\n");
					myDelete(game, num);
					break;
				}
			}
			getch();
			break;
		case 2:
			system("cls");
			num = inputNum();
			game = myAlloc(num);
			com = myAlloc(num);
			system("cls");
			VsrandomNum(num, game);
			VsrandomNum(num, com);
			vsGameOutput(game, com, num);
			while (1) {
				mycount = myNum(game, com, num);
				whoend = whoWin(mycount, num, comcount);
				if (whoend == 1) {
					myDelete(game, num);
					myDelete(com, num);
					break;
				}
				comcount = comNum(game, com, num);
				whoend = whoWin(mycount, num, comcount);
				if (whoend == 1) {
					myDelete(game, num);
					myDelete(com, num);
					break;
				}
			}
			break;
		case 3: end = 1;
			break;

		}
		if (end == 1) {
			system("cls");
			printf("게임이 종료되었습니다.\n");
			break;
		}
	}
	return 0;
}
int menu()
{
	int select;
	printf("1. 연습게임(개인 연습용)\n");
	printf("2. 대전게임(컴퓨터와 대전용)\n");
	printf("3. 종료\n\n");

	printf("# 메뉴선택 : ");
	scanf("%d", &select);

	return select;
}
int inputNum()
{
	int num;
	printf("연습용 빙고게임을 시작합니다.\n");
	printf("# 빙고판의 가로, 세로 크기를 입력해주세요(양수값 입력) : ");
	scanf("%d", &num);

	return num;
}
int** myAlloc(int num)
{
	int **game, i;
	game = (int **)malloc(sizeof(int*)*num);
	for (i = 0; i < num; i++)
	{
		game[i] = (int*)malloc(sizeof(int)*num);
	}
	return game;
}
void myDelete(int **game, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		free(game[i]);
	}
	free(game);
}
void solorandomNum(int num, int **game)
{
	int *numtemp, i, j, random1, random2, temp;

	numtemp = (int*)malloc(sizeof(int) * (int)pow(num, 2));
	for (i = 0; i <(int)pow(num, 2); i++)
	{
		numtemp[i] = i + 1;
	}
	for (i = 0; i < (int)pow(num, 2); i++)
	{
		random1 = rand() % (int)pow(num, 2);
		random2 = rand() % (int)pow(num, 2);

		temp = numtemp[random1];
		numtemp[random1] = numtemp[random2];
		numtemp[random2] = temp;
	}
	for (i = 0; i < num; i++)
	{
		memcpy(game[i], (numtemp + num*i), sizeof(int)*num);
	}
	for (i = 0; i < num; i++)
	{
		L;
		for (j = 0; j < num; j++)
		{
			printf("%3d  ", game[i][j]);
		}
		L;
		printf("\n");
	}

}
int practiceGame(int **game, int num)
{
	int i, j, unum, count = 0, check = 0;
	int length = 0, width = 0, lcross = 0, rcross = 0;

	while (1) {
		NL;
		printf("# 지울 숫자 입력(1 ~ %d) : ", (int)pow(num, 2));
		scanf("%d", &unum);
		for (i = 0; i < num; i++) {

			for (j = 0; j < num; j++) {
				if (unum == game[i][j])
					check = 1;
			}
		}
		if (check == 1) break;
		else
			printf("* 이미 지워진 숫자 입니다. 다시 입력하세요.\n");
	}
	system("cls");
	for (i = 0; i < num; i++)
	{
		L;
		length = 0;
		width = 0;
		for (j = 0; j < num; j++)
		{
			if (unum == game[i][j])
			{
				game[i][j] = 0;
			}
			if (game[i][j] == 0)
				printf("  X  ");
			else
				printf("%3d  ", game[i][j]);

			if (game[i][j] == 0)
				length++;
			if (game[j][i] == 0)
				width++;
		}
		if (length == num)
			count++;
		if (width == num)
			count++;

		if (game[i][i] == 0)
			lcross++;
		if (game[num - i - 1][i] == 0)
			rcross++;
		L;
		NL;
	}
	if (lcross == num)
		count++;
	if (rcross == num)
		count++;

	return count;
}
void vsGameOutput(int **game, int **com, int num)
{
	int i, j;
	printf("사용자 빙고게임판 내용을 생성중입니다.\n");
	printf("컴퓨터 빙고판 내용을 생성중 입니다.\n");
	Sleep(2500);
	system("cls");
	printf("[user]");
	for (i = 0; i < num; i++)
	{
		printf("\t");
	}
	printf("[computer]\n");
	for (i = 0; i < num; i++)
	{
		L;
		for (j = 0; j < num; j++)
		{
			printf("%3d  ", game[i][j]);
		}
		L;
		printf("\t");
		L;
		for (j = 0; j < num; j++)
		{
			printf("  ?  ");
		}
		L;
		NL;
	}

}
void VsrandomNum(int num, int **game)
{
	int *numtemp, i, random1, random2, temp;

	numtemp = (int*)malloc(sizeof(int) * (int)pow(num, 2));
	for (i = 0; i <(int)pow(num, 2); i++)
	{
		numtemp[i] = i + 1;
	}
	for (i = 0; i < (int)pow(num, 2); i++)
	{
		random1 = rand() % (int)pow(num, 2);
		random2 = rand() % (int)pow(num, 2);

		temp = numtemp[random1];
		numtemp[random1] = numtemp[random2];
		numtemp[random2] = temp;
	}
	for (i = 0; i < num; i++)
	{
		memcpy(game[i], (numtemp + num*i), sizeof(int)*num);
	}
}
int comNum(int **game, int **com, int num)
{
	int i, j, comnum, check = 0;
	int length = 0, width = 0, lcross = 0, rcross = 0, count = 0;
	while (1) {
		comnum = rand() % (int)pow(num, 2) + 1;
		for (i = 0; i < num; i++) {

			for (j = 0; j < num; j++) {
				if (comnum == game[i][j])
					check = 1;
			}
		}
		if (check == 1) break;
	}
	system("cls");
	printf("[user]");
	for (i = 0; i < num; i++)
	{
		printf("\t");
	}

	printf("[computer]\n");
	for (i = 0; i < num; i++)         //컴퓨터 입력 확인
	{
		L;
		length = 0;
		width = 0;
		for (j = 0; j < num; j++)
		{
			if (game[i][j] == comnum)
				game[i][j] = 0;
			if (com[i][j] == comnum)
				com[i][j] = 0;
		}
		for (j = 0; j < num; j++)
		{
			if (game[i][j] == 0)
				printf("  X  ");
			else
				printf("%3d  ", game[i][j]);
			if (game[i][j] == 0)
				length++;
			if (game[j][i] == 0)
				width++;
		}

		L;
		printf("\t");
		L;
		for (j = 0; j < num; j++)
		{
			if (com[i][j] == 0)
				printf("  X  ");
			else
				printf("  ?  ");
		}
		if (length == num)
			count++;
		if (width == num)
			count++;

		if (com[i][i] == 0)
			lcross++;
		if (com[num - i - 1][i] == 0)
			rcross++;
		L;
		NL;
	}                                   //컴퓨터 입력 확인 끝
	if (lcross == num)
		count++;
	if (rcross == num)
		count++;
	printf("# 컴퓨터가 선택한 숫자는 (%d)입니다.\n", comnum);
	return count;
}
int myNum(int **game, int **com, int num)
{
	int i, j, mynum, check = 0;
	int length = 0, width = 0, lcross = 0, rcross = 0, count = 0;
	while (1) {
		printf("# 지울 숫자 입력(1 ~ %d)", (int)pow(num, 2));
		scanf("%d", &mynum);
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				if (mynum == game[i][j])
					check = 1;
			}
		}
		if (check == 1) break;
		else
			printf("* 이미 지워진 숫자 입니다. 다시 입력하세요.\n");
	}
	system("cls");
	printf("[user]");
	for (i = 0; i < num; i++)
	{
		printf("\t");
	}
	printf("[computer]\n");
	for (i = 0; i < num; i++)
	{
		L;
		length = 0;
		width = 0;
		for (j = 0; j < num; j++)  //사용자 입력 확인
		{
			if (game[i][j] == mynum)
				game[i][j] = 0;
			if (com[i][j] == mynum)
				com[i][j] = 0;
		}
		for (j = 0; j < num; j++)
		{
			if (game[i][j] == 0)
				printf("  X  ");
			else
				printf("%3d  ", game[i][j]);
		}
		L;
		printf("\t");
		L;
		for (j = 0; j < num; j++)
		{
			if (com[i][j] == 0)
				printf("  X  ");
			else
				printf("  ?  ");
			if (game[i][j] == 0)
				length++;
			if (game[j][i] == 0)
				width++;
		}
		if (length == num)
			count++;
		if (width == num)
			count++;

		if (game[i][i] == 0)
			lcross++;
		if (game[num - i - 1][i] == 0)
			rcross++;
		L;
		NL;
	}     // 사용자 입력 확인 끝
	if (lcross == num)
		count++;
	if (rcross == num)
		count++;

	return count;
}
int whoWin(int mycount, int num, int comcount)
{
	int whoend = 0;
	if (mycount >= num || comcount >= num) {
		if (mycount > comcount) {
			printf("# 사용자 승!\n");
			printf("게임이 끝났습니다. 메뉴로 돌아가려면 아무키나 누르세요.\n");
			whoend = 1;
			getch();
		}
		else if (mycount < comcount) {
			printf("# 컴퓨터 승!\n");
			printf("게임이 끝났습니다. 메뉴로 돌아가려면 아무키나 누르세요.\n");
			whoend = 1;
			getch();
		}
		else {
			printf("무승부!\n");
			printf("게임이 끝났습니다. 메뉴로 돌아가려면 아무키나 누르세요.\n");
			whoend = 1;
			getch();
		}
	}
	return whoend;
}