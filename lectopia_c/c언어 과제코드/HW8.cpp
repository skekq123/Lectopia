#include<stdio.h>

int main()
{
	int his, liter, art, sum;
	double avg;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf_s("%d%d%d", &his, &liter, &art);

	sum = his + liter + art; // 총점
	avg = (double)sum / 3; // 평균

	printf("총점은 %d 이고 평균은 %.2lf 입니다.\n", sum, avg);


	return 0;
}