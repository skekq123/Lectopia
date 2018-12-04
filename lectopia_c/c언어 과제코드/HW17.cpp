#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
void Output(char *name, double height, char sex);
void Myflush();
int main()
{
	char name[100], sex;
	double height;
	int res;

	printf("# 성명 입력 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0'; // fgets함수로 가져온 개행 처리

	while (1) {
		printf("# 키 입력(cm단위) : ");
		res = scanf("%lf", &height);
		if (res == 1)
			break;
		else
		{
			Myflush();
			printf("잘못 입력하셨습니다. 다시 입력하세요.\n");
		}
	}
	while (1) {
		printf("# 성별입력(M/F) : ");
		res = scanf(" %c", &sex);
		if (sex == 'M' || sex == 'F')
			break;
		else
		{
			Myflush();
			printf("잘못 입력하였습니다. M/F중에서 하나만 입력하세요.\n");
		}
	}
	Output(name, height, sex);
	return 0;
}
void Output(char *name, double height, char sex)
{
	

	if (sex == 'M')
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n", name, height);
	else if (sex == 'F')
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", name, height);
}
void Myflush()
{
	while (getchar() != '\n');
}
