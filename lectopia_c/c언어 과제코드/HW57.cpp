#include<stdio.h>
#include<string.h>
#include<ctype.h>
#pragma warning (disable : 4996)
void Input(char *word);
int Check(char *word, int size, char *word2);
void Output(int check, char *word);
int main()
{
	char word[100], word2[100], end[] = "end";
	int size, check;;
	while (1) {
		Input(word);
		if (strcmp(word, end) == 0)
		{
			printf("종료되었습니다.\n");
			break;
		}
		else {
			size = strlen(word);
			strcpy(word2, word);
			check = Check(word, size, word2);
		}
		Output(check, word);
	}
	return 0;
}
void Input(char *word)
{
	printf("# 단어 입력 : ");
	scanf("%s",word);
}
int Check(char *word, int size, char *word2)
{
	int i, j;
	char temp;

	for (i = 0, j=1; i < size/2; i++, j++)
	{
		temp = word2[i];
		word2[i] = word2[size - j];
		word2[size - j] = temp;
	}
	if (toupper(*word)==toupper(*word2))
		return 1;
	else
		return 0;
}
void Output(int check, char *word)
{
	if (check == 1)
		printf("\" %s \" : 회문입니다!\n", word);
	else
		printf("\" %s \" : 회문이 아닙니다!\n", word);
}
