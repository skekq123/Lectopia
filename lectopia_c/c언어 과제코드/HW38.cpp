#include<stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int count, i, temp1 = 0, temp2 = 1, num, sum = 0;
	while (1) {
		printf("�Ǻ���ġ ������ �׼��� �Է��Ͻÿ� : ");
		scanf("%d", &count);
		if (getchar() == '\n')
			break;
		else
		{
				while (getchar() != '\n');
				printf("�ٽ� �Է��ϼ���.\n");

		}
	}
	for (i=2; i <= count; i++)
	{
		num = temp1 + temp2;
		temp1 = temp2;
		temp2 = num;
		if (i == 2) {
			printf("%d ", num);
			sum += 1;
		}
		printf("+ %d ", num);
		sum += num;
	}
	printf(" = %d\n", sum);
	return 0;
}
