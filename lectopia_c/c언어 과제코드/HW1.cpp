#include<stdio.h>
void PrintfAge(int);//�����Լ� �����
void PrintfHeight(double);//Ű�Լ� �����
int main()
{
	char name[20] = "����";
	int age = 23;
	double height = 174.8;

	printf("���� : %s\n",name);
	PrintfAge(age);//�����Լ� ȣ���
	PrintfHeight(height);//Ű�Լ� ȣ���
	return 0;
}
void PrintfAge(int Copyage)//�����Լ� ���Ǻ�
{
	printf("���� : %d\n",Copyage);
}
void PrintfHeight(double Copyheight)//Ű�Լ� ���Ǻ�
{
	printf("Ű : %5.1lf\n",Copyheight);
}