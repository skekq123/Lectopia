#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "doublelinkedlist.h"

//void mSearch(LinkedList *lp);      // 단일검색메뉴 처리 함수
//void mDelete(LinkedList *lp);      // 삭제메뉴 처리 함수
void displayPattern(LinkedList *lp, void(*print)(DataType *));
int patternNumCheck(char *pattern);
int main()
{
	LinkedList list;  //리스트관리 구조체 변수★(head,cur,tail,length) 각각 쓰레기값이 들어있음
	FILE *fp;
	int num, patLength, i, j, k;
	DataType Data;
	Node *temp;
	char pattern[100];
	

	printf("* 검사할 패턴의 길이를 입력하시오 : ");
	scanf("%d", &num);

	fp = fopen("C:\\data\\patternData.txt", "rt");
	assert(fp != NULL);

	while (fgets(pattern, sizeof(pattern)/ sizeof(pattern[0]), fp) != NULL) // 파일의 끝이 아닐동안 돌아라
	{	
		create(&list);
		patLength = patternNumCheck(pattern);
		printf("**비트열 : [%s] 의 검사 결과\n", pattern);
		for (i = 0; i < patLength-(num-1); i++) //패턴길이 마지막부분까지
		{
			k = 0;
			for (j = i; j < num+i; j++)
			{
				(Data.pattern)[k] = pattern[j];
				k++;
			}
			(Data.pattern)[k] = '\0';
			Data.num = 1;
			temp = searchUnique(&list, &Data, comparePattern);
			if (temp == NULL)
			{
				appendFromTail(&list, &Data);
			}
			else temp->data.num++;
			
			temp = NULL;
		}
		sortList(&list, comparePattern);
		displayPattern(&list, printPerson);
		printf("\n");
		destroy(&list);
	}
	fclose(fp); //중요*/
	
	

	return 0;
}
void displayPattern(LinkedList *lp, void(*print)(DataType *))
{
	lp->cur = lp->head->next; // ★1번 data가 있는 첫 노드 가리키는 코드
	while (lp->cur != lp->tail)//★length만큼 돌려도 되지만, length가 없다는 전제하에
	{
		print(&lp->cur->data); // 2번 출력문
		lp->cur = lp->cur->next; // 3번 다음 노드로 이동
	}
	return;
}//완성
int patternNumCheck(char *pattern)
{
	int i = 0;
	while (1)
	{
		if (pattern[i] == '\n')
		{
			pattern[i] = NULL;
			return i;
		}
		i++;
	}
}
/*----------------------------------------------------------------------------------
함수명 : mInput()
----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------
함수명 : mSearch()
----------------------------------------------------------------------------------*/
int comparePattern(DataType *p1, DataType *p2)
{
	return (strcmp(p1->pattern, p2->pattern));  // strcmp()함수의 리턴값을 바로 리턴
}
void printPerson(DataType *p)  // Person 구조체의 모든 멤버를 출력하는 함수 
{
	printf("[ %s ] : %d개\n", p->pattern, p->num);
}