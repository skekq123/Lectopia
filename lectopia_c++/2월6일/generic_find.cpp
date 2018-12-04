#include <stdio.h>
void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));
int compareInt(void *vp1, void *vp2);     // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int compareDouble(void *vp1, void *vp2);  // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double  y[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	int number = 5;
	double dNumber = 5.5;
	int *ip;
	double *dp;

	ip = (int *)find(x, x + 10, &number, sizeof(int), compareInt);

	if (ip == x + 10) { printf("not find\n"); }
	else { printf("find data = %d\n", *ip); }

	dp = (double *)find(y, y + 5, &dNumber, sizeof(double), compareDouble);
	if (dp == y + 5) { printf("not find\n"); }
	else { printf("find data = %lf\n", *dp); }

	return 0;
}
void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *))
{
	while (begin != end && (compareData(begin, value) != 0))
	{
		begin = (char *)begin + size;
	}
	return begin;
}
int compareInt(void *vp1, void *vp2)     // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
{
	if (*(int*)vp1 > *(int*)vp2) return 1;
	else if (*(int*)vp1 == *(int*)vp2) return 0;
	else return -1;
}
int compareDouble(void *vp1, void *vp2)  // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
{
	if (*(double*)vp1 > *(double*)vp2) return 1;
	else if (*(double*)vp1 == *(double*)vp2) return 0;
	else return -1;
}
