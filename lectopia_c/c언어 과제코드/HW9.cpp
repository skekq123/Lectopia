#include<stdio.h>
int Input();
int main()
{
	int number;

	number = Input();
	printf("�Էµ� ���� 8 ������ 0%o �Դϴ�.\n",number);
	printf("�Էµ� ���� 16 ������ 0x%x �Դϴ�. \n", number);
	return 0;
}
int Input()
{
	int number;
	
	printf("�������� �Է��ϼ��� : ");
	scanf_s("%d",&number);

	return number;
}