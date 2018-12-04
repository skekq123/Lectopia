#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable : 4996)
void gotoxy(int x, int y);
void Input(char *ch);
void Scroll(char *ch, int size);
void Blink(char *ch2, int size);
int main()
{
	char ch[51], ch2[51];
	int size;
	Input(ch);
	size = strlen(ch);
	size -= 1;
	strcpy(ch2,ch);
	Scroll(ch, size);
	Blink(ch2, size);

	return 0;
}
void gotoxy(int x, int y)
{
	COORD Pos = {(short)x, (short)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Input(char *ch)
{
	printf("문자열을 입력하시오 : ");
	//scanf("%s",ch);
	fgets(ch, 51, stdin);
}
void Scroll(char *ch, int size)
{
	char temp[51];
	int i, j, count=0;
	
	system("cls");
	for (i = 0; count <= size*2; count++) {
		
		gotoxy(30, 12);
		printf("%s", ch);
		Sleep(200);
		temp[i]  = ch[i];
		for (j = 0; j < size; j++)
		{
			ch[j] = ch[j+1];
		}
		ch[size - 1] = temp[i];
		}
	}
void Blink(char *ch2, int size)
{
	int i;
	for (i = 0; i < 3; i++) {
		system("cls");
		Sleep(500);
		gotoxy(30, 12);
		printf("%s\n", ch2);
	}
}
