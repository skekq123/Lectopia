#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "doublelinkedlist.h"

void mInput(LinkedList *lp, int *num, char word[][80], int *arysize);       // �Է¸޴� ó�� �Լ�
void dataFileLoad(char name[][80]); // ���ϳ��� �����͸� �迭�� ���� 
void ArraySort(char name[][80], int *arysize); //�迭 ��Ʈ
void printWord(DataType *lp); //�迭 ���
int errocCheck(LinkedList *lp, DataType *inData); //������Ʈ���� �����ڿ� ù���ڰ� ������ check
void WordCheck(char word[][80], DataType inData, int *arysize); //�迭�� string�� �Է��� string�� ������ check
int overCheck(char word[][80], int *arysize); // ���� �������
int main()
{
	LinkedList list;
	char word[5][80];
	int i, num=1, arysize = sizeof(word) / sizeof(word[0]);
	
	dataFileLoad(word);
	ArraySort(word, &arysize);
	create(&list);
	DataType first = {"pointer"};
	appendFromTail(&list,&first);

	while (1)
	{	
		printf("*����Ʈ�ܾ� : ");
		for (i = 0; i < arysize; i++)
			if(word[i][0] != NULL) printf("%s / ", word[i]);
		printf("\n*����� �Է� �ܾ� : ");
		display(&list, printWord);
		printf("\n�����ձ� �ܾ� �Է�(%dȸ��) : ", num);
		mInput(&list, &num,word, &arysize);
		printf("\n");
		if (overCheck(word, &arysize) == 1)
		{	
			printf("** ����Ʈ �ܾ ��� ������ϴ�. ������ �����մϴ�.\n");
			destroy(&list);
			break;
		}
	}
	return 0;
}
int overCheck(char word[][80], int *arysize)
{
	int i, count=0;
	for (i = 0; i < *arysize; i++)
	{
		if (word[i][0] == NULL) count++;
	}
	if (count == 5) return 1;
	else return 0;
}
int errocCheck(LinkedList *lp, DataType *inData)
{
	if (lp->tail->prev->data.name[strlen(lp->tail->prev->data.name) - 1] == inData->name[0]) return 1;
	else return 0;
}
void dataFileLoad(char word[][80]) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
{
	FILE *fp;
	int i;
	fp = fopen("C:\\data\\pointWord.txt", "rt");
	assert(fp != NULL);

		for (i = 0; ; i++) {

			if (fscanf(fp, "%s", &word[i][0]) == EOF)	break;
	}
	fclose(fp);
	
}
void ArraySort(char word[][80], int *arysize)
{
	int i, j;
	char temp[80];
	for (i = 0;i<*arysize; i++)
	{
		for (j = i+1;j<*arysize; j++)
		{
			if (strcmp(word[i], word[j]) == 1)
			{
				strcpy(temp, word[i]);
				strcpy(word[i], word[j]);
				strcpy(word[j],temp);
			}
		}
	}
	return;
}
void mInput(LinkedList *lp, int *num, char word[][80], int *arysize)
{
		DataType inData;
		scanf("%s", inData.name);
		if (errocCheck(lp, &inData) == 1) {
			(*num)++;
			appendFromTail(lp, &inData); //tail ��� �տ� ������ �߰�
			WordCheck(word, inData, arysize);
		}
		else printf("���߸� �Է��ϼ̽��ϴ�.\n");
		
		return;
}
void printWord(DataType *lp)  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
{
	printf("%s / ", lp->name);
}
void WordCheck(char word[][80], DataType inData, int *arysize) //������ �������迭�� �����κ� ����, �� ������ �������ִ� �Լ�
{
	int i;
	for (i = 0; i < *arysize; i++)
	{
		if (strcmp(word[i], inData.name) == 0)
			word[i][0] = NULL;
	}
}