#include<stdio.h> // �̿ϼ�
#pragma warning (disable : 4996)
FILE *fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
void Output(FILE *fp, int testCnt, int *dataArray);
int main()
{
	int dataArray[100];
	int testCnt;  // �Ǽ�
	FILE *fp;
	fp = fileOpen("hw63_histogram.txt", "rt");
	if (fp == NULL) return 1;
	fscanf(fp, "%d", &testCnt);  
	Output(fp, testCnt, dataArray);
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
void Output(FILE *fp, int testCnt, int *dataArray)
{
	int i, l, k, j, temp, max = 0;
	int dataCnt;  // �� ���� ����
	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, dataArray);
		temp = dataCnt;
		for (k = 0; k < temp; k++)
		{
			if (dataArray[k] > max)
				max = dataArray[k];
		}
		for (l = 0; l < max; l++)     //����뵵
		{
			for (k = 0; k < temp; k++) // ���ΰ��� : temp -1, 
			{
				if (dataArray[k] >= max - l)
					printf(" *");

				else
					printf("  ");
			}
			printf("\n");
		}
		for (j = 0; j < dataCnt; j++) {

			printf("%2d", dataArray[j]);
		}
		printf("\n-------------------------------------------\n");
	}
}

