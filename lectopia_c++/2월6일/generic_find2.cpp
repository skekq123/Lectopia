#include <stdio.h>
void *find(void *begin, void *end, void *value, int(*compareData)(void *, void *), void(*nextData)(void *));
int compareInt(void *vp1, void *vp2);     // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
int compareDouble(void *vp1, void *vp2);  // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
void nextInt(void *vp);
void nextDouble(void *vp);

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double  y[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	int number = 5;
	double dNumber = 5.5;
	int *ip;
	double *dp;

	ip = (int *)find(x, x + 10, &number, compareInt, nextInt);

	if (ip == x + 10) { printf("not find\n"); }
	else { printf("find data = %d\n", *ip); }

	dp = (double *)find(y, y + 5, &dNumber, compareDouble, nextDouble);
	if (dp == y + 5) { printf("not find\n"); }
	else { printf("find data = %lf\n", *dp); }

	return 0;
}
void *find(void *begin, void *end, void *value, int(*compareData)(void *, void *), void(*nextData)(void *))
{
	while (begin != end && (compareData(begin, value) != 0))
	{
		nextData(&begin);
	}
	return begin;
}
int compareInt(void *vp1, void *vp2)     // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
{
	if (*(int*)vp1 > *(int*)vp2) return 1;
	else if (*(int*)vp1 == *(int*)vp2) return 0;
	else return -1;
}
int compareDouble(void *vp1, void *vp2) // vp1이 가리키는 값이 크면 1, 같으면 0, 작으면 -1 리턴
{
	if (*(double*)vp1 > *(double*)vp2) return 1;
	else if (*(double*)vp1 == *(double*)vp2) return 0;
	else return -1;
}
void nextInt(void *vp)
{
	*(int **)vp = *(int**)vp + 1;
}
void nextDouble(void *vp)
{
	*(double **)vp = *(double **)vp + 1;
}