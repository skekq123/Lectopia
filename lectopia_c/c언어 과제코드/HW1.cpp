#include<stdio.h>
void PrintfAge(int);//나이함수 선언부
void PrintfHeight(double);//키함수 선언부
int main()
{
	char name[20] = "고영빈";
	int age = 23;
	double height = 174.8;

	printf("성명 : %s\n",name);
	PrintfAge(age);//나이함수 호출부
	PrintfHeight(height);//키함수 호출부
	return 0;
}
void PrintfAge(int Copyage)//나이함수 정의부
{
	printf("나이 : %d\n",Copyage);
}
void PrintfHeight(double Copyheight)//키함수 정의부
{
	printf("키 : %5.1lf\n",Copyheight);
}