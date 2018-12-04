#include<stdio.h>
#pragma warning (disable : 4996)
FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
int main()
{
	int dataArray[100];
	int testCnt;  // 3건
	int dataCnt;  
	int i, j, count = 0, k;
	FILE *fp;
	fp = fileOpen("C:\\data\\hw48\\9_number_list.txt", "rt"); 
	if (fp == NULL) return 1;
	fscanf(fp, "%d", &testCnt);
		
	
	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, dataArray);
		printf("# 수열 : ");
		for (k = 0; k < dataCnt; k++) {
			for (j = 0; j < dataCnt; j++) {
				if(j == k)
				printf("%3d", dataArray[j]);
				if (dataArray[j] * 2 == dataArray[k])
					count++;
			}
		}
		printf("\n2배 값이 존재하는 원소의 개수는 %d 개 입니다.\n", count);
		count = 0;
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