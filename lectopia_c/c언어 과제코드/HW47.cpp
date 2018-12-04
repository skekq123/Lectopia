#include<stdio.h>
#pragma warning (disable : 4996)
#include<windows.h>
#include<conio.h>
void gotoxy(int *sx, int *sy, int k);
void Move(int *sx, int *sy, int *ex, int *ey);
int main()
{
	int sx, ex, sy, ey, k=0, end=0;
	char ch;
	printf("sx ÁÂÇ¥ ÀÔ·Â(1~70) : ");
	scanf("%d", &sx);
	while (1) {
		printf("ex ÁÂÇ¥ ÀÔ·Â(%d~70) : ", sx + 1);
		scanf("%d", &ex);
		if (ex >= sx + 1)
			break;
	}
	printf("sy ÁÂÇ¥ ÀÔ·Â(1~20) : ");
	scanf("%d", &sy);
	while (1) {
		printf("ey ÁÂÇ¥ ÀÔ·Â(%d~24) : ", sy + 1);
		scanf("%d", &ey);
		if (ey >= sy + 1)
			break;
	}
	Move(&sx, &sy, &ex, &ey);

	while (1) {
		ch = getch();
		switch (ch) {
		case 'w': 
			if(sy == 1)
				printf("\a");
			else{
			sy -= 1;
			ey -= 1;
			Move(&sx, &sy, &ex, &ey);
			}
			break;
		case 'a':
			if (sx == 1)
				printf("\a");
			else {
				sx -= 1;
				ex -= 1;
				Move(&sx, &sy, &ex, &ey);
			}
			break;
		case 's':
			if(ey == 24)
				printf("\a");
			else {
				sy += 1;
				ey += 1;
				Move(&sx, &sy, &ex, &ey);
			}
			break;
		case 'd':
			if (ex == 80) 
				printf("\a");
			
			else {
				sx += 1;
				ex += 1;
				Move(&sx, &sy, &ex, &ey);
			}
			break;
		case 27:
			end = 1;
			break;
		}
		if (end == 1)
			break;

	}
	
	return 0;
}
void gotoxy(int *sx, int *sy, int k)
{
	COORD Pos = { (short)*sx, (short)(*sy+k)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Move(int *sx, int *sy, int *ex, int *ey)
{
	int i, j, k=0;
	(system("cls"));
	gotoxy(sx, sy, k);

	for (i = *sy, k = 1; i <= *ey; i++, k++)
	{
		for (j = *sx; j <= *ex; j++)
		{
			if (i == *sy || i == *ey || j == *sx || j == *ex)
				printf("*");
			else
				printf(" ");
		}
		gotoxy(sx, sy, k);
	}
}