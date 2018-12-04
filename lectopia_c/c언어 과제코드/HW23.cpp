#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int num1, num2, result, res;
	while (1) {
		printf("# 두개의 정수를 입력하세요 : ");
		res = scanf("%d%d",&num1, &num2);
		if (res != 2)
			break;
		if (num1 > num2) {
			result = num1 - num2;
			printf("%d - %d = %d\n",num1, num2, result);
		}
		else {
			result = num2 - num1;
			printf("%d - %d = %d\n",num2, num1, result);
		}
		

	}
	return 0;
}