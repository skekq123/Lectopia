#include<stdio.h> 
#pragma warning (disable : 4996)
#include<string.h>
void Input(char *str);
void Input2(char *ch);
void strcheck(char *str, char ch, int *num, int len);
int main()
{
	char ch, str[100];
	char end[] = "end";
	int num[100] = {-1}, i, j, len;
	while (1) {
		Input(str);
		len = strlen(str);
		if (strcmp(str, end) == 0){
			printf("����Ǿ����ϴ�.\n");
			break;
	}
		else {
			Input2(&ch);
			strcheck(str, ch, num, len);
			if (num[0] == -1)
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n", str, ch);
			else {
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ�", str, ch);
				for (i = 0, j=0; i < 100; i++)
				{
					if (i > 0 && num[j] == 0) break;
					else {
						printf(" %d�� ��ġ", num[i]);
						j++;
					}
				}
				printf("�� �����մϴ�.\n");
				for (i = 0; i < len; i++)  //�迭 �ʱ�ȭ �κ�
				{
					if (i == 0)
						num[i] = -1;
					else
					num[i] = 0;
				}
			}
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
void strcheck(char *str, char ch, int *num, int len)
{
	int i, j;
	for (i = 0, j = 0; i < len; i++)
	{
		if (str[i] == ch)
		{
			num[j] = i;
			j++;
		}
	}
	
}