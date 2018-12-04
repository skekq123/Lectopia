#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "doublelinkedlist.h"

//void mSearch(LinkedList *lp);      // ���ϰ˻��޴� ó�� �Լ�
//void mDelete(LinkedList *lp);      // �����޴� ó�� �Լ�
void displayPattern(LinkedList *lp, void(*print)(DataType *));
int patternNumCheck(char *pattern);
int main()
{
	LinkedList list;  //����Ʈ���� ����ü ������(head,cur,tail,length) ���� �����Ⱚ�� �������
	FILE *fp;
	int num, patLength, i, j, k;
	DataType Data;
	Node *temp;
	char pattern[100];
	

	printf("* �˻��� ������ ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &num);

	fp = fopen("C:\\data\\patternData.txt", "rt");
	assert(fp != NULL);

	while (fgets(pattern, sizeof(pattern)/ sizeof(pattern[0]), fp) != NULL) // ������ ���� �ƴҵ��� ���ƶ�
	{	
		create(&list);
		patLength = patternNumCheck(pattern);
		printf("**��Ʈ�� : [%s] �� �˻� ���\n", pattern);
		for (i = 0; i < patLength-(num-1); i++) //���ϱ��� �������κб���
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
	fclose(fp); //�߿�*/
	
	

	return 0;
}
void displayPattern(LinkedList *lp, void(*print)(DataType *))
{
	lp->cur = lp->head->next; // ��1�� data�� �ִ� ù ��� ����Ű�� �ڵ�
	while (lp->cur != lp->tail)//��length��ŭ ������ ������, length�� ���ٴ� �����Ͽ�
	{
		print(&lp->cur->data); // 2�� ��¹�
		lp->cur = lp->cur->next; // 3�� ���� ���� �̵�
	}
	return;
}//�ϼ�
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
�Լ��� : mInput()
----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------
�Լ��� : mSearch()
----------------------------------------------------------------------------------*/
int comparePattern(DataType *p1, DataType *p2)
{
	return (strcmp(p1->pattern, p2->pattern));  // strcmp()�Լ��� ���ϰ��� �ٷ� ����
}
void printPerson(DataType *p)  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
{
	printf("[ %s ] : %d��\n", p->pattern, p->num);
}