#include<stdio.h>

int main()
{
	int num1, num2;

	printf("�ΰ��� ������ �Է��Ͻÿ� : ");
	scanf_s("%d%d",&num1,&num2);

	printf("%d+%d = %d\n",num1, num2, num1+num2);
	printf("%d-%d = %d\n",num1, num2, num1-num2);
	printf("%d*%d = %d\n",num1, num2, num1*num2);
	printf("%d/%d = %.2lf\n",num1, num2, (double)num1/(double)num2);

	return 0;
}