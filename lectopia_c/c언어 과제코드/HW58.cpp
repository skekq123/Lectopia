#include<stdio.h>
#pragma warning (disable : 4996)
#include<string.h>
void Input(char *str);
int Numbercheck(char *str, int size);
void Output(char *str, int sum);
int main()
{
	char str[100], end[100] = {"end"};
	int size, sum;
	while(1){
	Input(str);
	size = strlen(str);
	if ((strcmp(str, end)) == 0)
	{
		printf("����Ǿ����ϴ�.\n");
		break;
	}	
	sum = Numbercheck(str, size);
	
	Output(str, sum);
	}

	return 0;
}
void Input(char *str)
{
	printf("# ������ �Է��Ͻÿ� : ");
	scanf("%s", str);
}
int Numbercheck(char *str, int size)
{
	int sum = 0, i, num=0;
	
	for (i = 0; i < size;  i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			num = num * 10 + str[i] - '0';
		}
		else {
			sum += num;
			num = 0;
		}
	}
	sum += num;
	return sum;
}
void Output(char *str, int sum)
{
	printf("\"%s\" ���� �� ���ڴ� [%d]�Դϴ�.\n", str, sum);
}