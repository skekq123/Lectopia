#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "doublelinkedlist.h"

void mInput(LinkedList *lp, int *num, char word[][80], int *arysize);       // 입력메뉴 처리 함수
void dataFileLoad(char name[][80]); // 파일내의 데이터를 배열에 저장 
void ArraySort(char name[][80], int *arysize); //배열 소트
void printWord(DataType *lp); //배열 출력
int errocCheck(LinkedList *lp, DataType *inData); //더블리스트에서 끝글자와 첫글자가 같은지 check
void WordCheck(char word[][80], DataType inData, int *arysize); //배열의 string과 입력한 string이 같은지 check
int overCheck(char word[][80], int *arysize); // 게임 끝내기용
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
		printf("*포인트단어 : ");
		for (i = 0; i < arysize; i++)
			if(word[i][0] != NULL) printf("%s / ", word[i]);
		printf("\n*사용자 입력 단어 : ");
		display(&list, printWord);
		printf("\n끝말잇기 단어 입력(%d회차) : ", num);
		mInput(&list, &num,word, &arysize);
		printf("\n");
		if (overCheck(word, &arysize) == 1)
		{	
			printf("** 포인트 단어를 모두 맞췄습니다. 게임을 종료합니다.\n");
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
void dataFileLoad(char word[][80]) // 데이터 파일내의 데이터를 리스트에 저장 
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
			appendFromTail(lp, &inData); //tail 노드 앞에 데이터 추가
			WordCheck(word, inData, arysize);
		}
		else printf("★잘못 입력하셨습니다.\n");
		
		return;
}
void printWord(DataType *lp)  // Person 구조체의 모든 멤버를 출력하는 함수 
{
	printf("%s / ", lp->name);
}
void WordCheck(char word[][80], DataType inData, int *arysize) //맞으면 이차원배열에 맞힌부분 삭제, 다 맞출경우 삭제해주는 함수
{
	int i;
	for (i = 0; i < *arysize; i++)
	{
		if (strcmp(word[i], inData.name) == 0)
			word[i][0] = NULL;
	}
}