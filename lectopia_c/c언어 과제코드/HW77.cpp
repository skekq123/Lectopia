#include<stdio.h>
#pragma warning (disable : 4996)
FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
int FeeCalculation(int *ary);
int main()
{
	int ary[10];
	int testCnt;  // 2건
	int dataCnt;
	int i, fee;
	FILE *fp;
	fp = fileOpen("hw77_parking_info.txt", "rt");
	if (fp == NULL) return 1;
	fscanf(fp, "%d", &testCnt);


	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, ary);
		printf("A 요금 : %d / B 요금 : %d / C 요금 : %d\n", ary[0], ary[1], ary[2]);
		fee = FeeCalculation(ary);
		printf("총 주차 요금 : %d\n", fee);
	}
	fclose(fp);
	return 0;

}
FILE *fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL)
	{
		printf("File open error!\n");
	}
	return fp;
}
int fileRead(FILE *fp, int *dataArray)
{
	int dataCnt = 0;
	while (1)
	{
		fscanf(fp, "%d", &dataArray[dataCnt]);
		
		dataCnt++;
		if (dataCnt == 9) break;

	}
	return dataCnt;
}
int FeeCalculation(int *ary)
{
	int i, fee = 0, car1[99] = { 0 }, car2[99] = { 0 }, car3[99] = { 0 }, sumtime[100];
	int one = 0, two = 0, three = 0;

	for (i = ary[3]+1; i <= ary[4]; i++)
	{
		car1[i] = 1;
		
	}
	for (i = ary[5]+1; i <= ary[6]; i++)
	{
		car2[i] = 1;
		
	}
	for (i = ary[7]+1; i <= ary[8]; i++)
	{
		car3[i] = 1;
	}
	for (i = 1; i < 100; i++)
	{
		sumtime[i] = car1[i] + car2[i] + car3[i];
		if (sumtime[i] == 1)
			one++;
		else if (sumtime[i] == 2)
			two++;
		else if (sumtime[i] == 3)
			three++;
	}
	fee = one * ary[0] + two * 2 * ary[1] + three * 3 * ary[2];

	return fee;
}