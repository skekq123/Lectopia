#include<stdio.h>
#pragma warning (disable : 4996)
int main()
{
	char ch;
	int word = 0, num = 0, spec = 0, space = 0;

	printf("# ���� ������ �Է� �Ͻÿ� : \n");
	while ((ch = getchar()) != EOF)
	{
		if (ch == EOF)
			break;
		else if ((ch >= 'A') && (ch <= 'Z') || (ch >= 'a') && (ch <= 'z'))
			word++;
		else if ((ch == ' ') || (ch == '\t') || (ch == '\n'))
			space++;
		else if ((ch >= '0') && (ch <= '9'))
			num++;
		else
			spec++;
	}
	printf("* ������ ��ҹ��� ���� : %d\n", word);
	printf("* ���ڹ��� ���� : %d\n", num);
	printf("* ���鹮��(space, tab, enter) ���� : %d\n", space);
	printf("* �� �� ��Ÿ���� ���� : %d\n", spec);
			return 0;
}