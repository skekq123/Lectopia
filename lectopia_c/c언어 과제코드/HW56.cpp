#include<stdio.h>
#pragma warning (disable : 4996)
#define SWAP(x, y)   {int t;  t = x;  x = y;  y = t;}
#define NL printf("\n");
FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
int main()
{
	int dataArray[100];
	int testCnt;  // 3건
	int dataCnt;
	int i, j,k, m;
	FILE *fp;
	fp = fileOpen("hw56_sortData.txt", "rt");
	if (fp == NULL) return 1;
	fscanf(fp, "%d", &testCnt);


	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, dataArray);
		printf("# 소트 전 데이터 : ");
		for (j = 0; j < dataCnt; j++) 
		{
			printf("%d ", dataArray[j]);		
		}
		NL
		printf("# 소트 후 데이터 : ");
		for (m = 0; m < dataCnt - 1; m++) {
			for (k = 0; k < dataCnt - 1; k++)
			{
				if (dataArray[k] > dataArray[k + 1])
					SWAP(dataArray[k], dataArray[k + 1]);
			}
		}
		for (j = 0; j < dataCnt; j++)
		{
			printf("%d ", dataArray[j]);
		}
		NL
		NL

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
		if (dataArray[dataCnt] == 0) break;
		dataCnt++;

	}
	return dataCnt;
}