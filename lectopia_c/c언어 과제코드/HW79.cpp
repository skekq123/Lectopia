#include<stdio.h>
#pragma warning (disable : 4996)
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<process.h>
void Input(char **p);
void Sort(char **p);
void Output(char **p);
void MyDelete(char **p);
int main()
{
	char *p[5];
	
	Input(p);
	Sort(p);
	Output(p);
	MyDelete(p);
	return 0;
}
void Input(char **p)
{
	char temp[100];
	int len, i;
	for(i = 0; i < 5; i++) {
		printf("# ¹®ÀÚ¿­ %d: ", i + 1);
		scanf("%s", temp);
		len = strlen(temp) + 1;
		p[i] = (char *)malloc(sizeof(char) * len);

		assert(p[i] != NULL);
		strcpy(p[i], temp);
	}
}
void Sort(char **p)
{
	int i, j, res;
	char *temp;

	for (i = 0; i < 4; i++)
	{
		for(j = i + 1; j < 5; j++){
		res = strcmp(*(p + i), *(p + j));
		if (res >= 1) {
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
		}
	}
}
void Output(char **p)
{
	int  i;
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", p[i]);
	}
}
void MyDelete(char **p)
{
	int i;
	for (i = 0; i < 5; i++) {
		free(p[i]);
	}
}
