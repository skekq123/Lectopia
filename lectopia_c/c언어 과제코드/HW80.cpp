#include<stdio.h>
#pragma warning (disable : 4996)
#include<stdlib.h>
#include<assert.h>
#include<process.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
int NumberInput();
char** NameInput(char **name, int num);
int** ScoreInput(int **score, int num, char **name);
void menu();
void gotoxy(int x, int y);
void SortScore(char **name, int **score, int num);
void Myflush();
void myDelete(char **name, int num, int **score);
int main()
{
	char **name = { 0 }, select;
	int **score = { 0 }, num, end = 0;

	num = NumberInput();
	name = NameInput(name, num);
	score = ScoreInput(score, num, name);
	while (1) {
		system("cls");
		menu();
		select = getch();
		system("cls");
		switch (select) {
		case '1':
			myDelete(name, num, score);
			num = NumberInput();
			name = NameInput(name, num);
			score = ScoreInput(score, num, name);
			break;
		case '2':
			SortScore(name, score, num);
			getchar();
			break;
		case '3':
			end = 1;
			break;
		}
		if (end == 1)
		{
			myDelete(name, num, score);
			break;
		}
	}
	return 0;
}
int NumberInput()
{
	int num;
	printf("학생 수를 입력하시오.");
	scanf("%d", &num);
	return num;
}
char** NameInput(char **name, int num)
{
	char temp[100];
	int i, len;
	name = (char **)malloc(sizeof(char *) * num);
	assert(name != NULL);

	for (i = 0; i < num; i++)
	{
		printf("%d번 학생의 이름을 입력하시오 : ", i + 1);
		scanf("%s", temp);
		len = strlen(temp) + 1;
		name[i] = (char *)malloc(sizeof(char) * len);
		assert(name[i] != NULL);
		strcpy(name[i], temp);
	}
	return name;
}
int** ScoreInput(int **score, int num, char **name)
{
	int i, kor, eng, math, res, sum, avg;

	score = (int **)malloc(sizeof(int *) * num);
	assert(score != NULL);

	for (i = 0; i < num; i++)
	{
		while (1) {
			printf("%s 학생의 성적을 입력하시오(국어,영어,수학) :", name[i]);
			res = scanf("%d%d%d", &kor, &eng, &math) + 2;
			if (kor >= 0 && eng >= 0 && math >= 0)
			{
				if (kor < 101 && eng < 101 && math < 101)
				{
					if (getchar() == '\n')
						break;
				}
			}
			else
				Myflush();
		}
		score[i] = (int *)malloc(sizeof(int) * res);
		assert(score[i] != NULL);
		*(score[i] + 0) = kor;
		*(score[i] + 1) = eng;
		*(score[i] + 2) = math;
		sum = kor + eng + math;
		*(score[i] + 3) = sum;
		avg = sum / 3;
		*(score[i] + 4) = avg;
	}

	return score;
}
void menu()
{
	gotoxy(46, 8);
	printf("******MENU******");
	gotoxy(46, 11);
	printf("1.성적 수정\n");
	gotoxy(46, 14);
	printf("2.전체성적출력\n");
	gotoxy(46, 17);
	printf("3.종료\n");
}
void gotoxy(int x, int y)
{
	COORD Pos = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void SortScore(char **name, int **score, int num)
{
	int i, j, *temp, k;
	char *strtemp;
	system("cls");
	printf("성적\n");
	printf("[석차\t성명\t국어\t영어\t수학\t총점\t평균]\n");

	for (i = 0; i < num - 1; i++)
	{
		for (j = i + 1; j<num; j++)
		{
			if (*(score[i] + 3) < *(score[j] + 3))
			{
				temp = *(score + i);
				*(score + i) = *(score + j);
				*(score + j) = temp;

				strtemp = *(name + i);
				*(name + i) = *(name + j);
				*(name + j) = strtemp;
			}
		}
	}
	for (i = 0, k = 1; i < num; i++)
	{
		if (i > 0)
		{
			if (*(score[i] + 3) == *(score[i - 1] + 3))
				k = k;
			else
				k = i+1;
		}
		printf("   %d\t%s\t", k, name[i]);
		
		for (j = 0; j < 5; j++)
		{
			printf("%d\t", *(score[i] + j));

		}
		printf("\n");
	}
	printf("메뉴로 돌아가려면 아무키나 누르세요.\n");
}
void Myflush()
{
	while (getchar() != '\n');
}
void myDelete(char **name, int num, int **score)
{
	int i;
	for (i = 0; i < num; i++)
	{
		free(score[i]);
		free(name[i]);
	}
	free(score);
	free(name);
}

