#include<stdio.h>
#pragma warning (disable : 4996)
#include<string.h>
void Input(char *str);
void Input2(char *ch);
int strcheck(char *str, char ch);
int main()
{
	char ch, str[100], index;
	char end[] = "end";
	while (1) {
		Input(str);
		if (strcmp(str, end) == 0) break;
		else {
			Input2(&ch);
			index = strcheck(str, ch);
			if (index >= 0)
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d�� ��ġ�� �����մϴ�.\n", str, ch, index);
			else
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n", str, ch);
		}
	}
	return 0;
}
void Input(char *str)
{
		printf("# ���ڿ��� �Է��Ͻÿ� : ");
		scanf("%s", str);
}
void Input2(char *ch)
{
	printf("# ���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", ch);
}
int strcheck(char *str, char ch)
{
	int i, index;
	for (i = 0; i < 100; i++)
	{
		if (str[i] == ch)
		{
			index = i;
			return index;
			break;
		}
	}
	return -1;
}