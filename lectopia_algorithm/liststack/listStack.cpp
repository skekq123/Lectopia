#include "liststack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : initStack() -  ��ũ�帮��Ʈ�� �����Ǵ� ���� ���� �Լ�
�������� : sPtr - ���ð��� ����ü�� �ּ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr)
{
	sPtr->head = (Snode *)calloc(1, sizeof(Snode)); //��� ��� ���� calloc(�Ҵ�氹��,�Ҵ����ũ��)
	assert(sPtr->head != NULL);
	sPtr->tail = (Snode *)calloc(1, sizeof(Snode)); //���� ��� ����
	assert(sPtr->tail != NULL);
	/*����尡 ���ϳ�带, ���ϳ�尡 ���ϳ�带 ����Ű�� ��*/
	sPtr->head->next = sPtr->tail;
	sPtr->tail->next = sPtr->tail;
	sPtr->cur = NULL;
	return;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : push() - ���ÿ� ������ �ϳ��� ������
�������� : sPtr - ���ñ���ü�� �ּ�
inData - ���ÿ� ������ ������
���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, DataType inData) /* stack�� ������ �����ϱ� */
{
	sPtr->cur = (Snode*)calloc(1, sizeof(Snode));
	if (sPtr->cur == NULL) return FALSE;
	else {
		sPtr->cur->data = inData;
		sPtr->cur->next = sPtr->head->next;
		sPtr->head->next = sPtr->cur;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ��� : pop() - ���ÿ��� ������ �ϳ��� ����
�������� : sPtr - ���ñ���ü�� �ּ�
popData - ���� �����͸� ������ �������� �ּ�
���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int pop(Stack *sPtr, DataType *popData)
{
	if (isStackEmpty(sPtr)) return FALSE;
	else 
	{
		*popData = sPtr->head->next->data; //������ ����
		sPtr->cur = sPtr->head->next;
		sPtr->head->next = sPtr->head->next->next; // �������� ����
		free(sPtr->cur);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : printStack() - ������ ��� �����͸� ��� ��
�������� : sPtr - ���ñ���ü�� �ּ�
print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printStack(Stack *sPtr, void(*print)(DataType *))
{
	
	for (sPtr->cur = sPtr->head->next; sPtr->cur != sPtr->tail; sPtr->cur= sPtr->cur->next)
	{
		print(&sPtr->cur->data);
		printf("\n");
	}
	
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : destroyStack() - ���� �Ҹ� �Լ�
�������� : sPtr - ���ñ���ü�� �ּ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr)
{
	for (sPtr->cur = sPtr->head->next; sPtr->cur != sPtr->tail; )
	{
		Snode *temp = sPtr->cur;
		sPtr->cur = sPtr->cur->next;
		free(temp);
	}
	free(sPtr->head);
	free(sPtr->tail);
	sPtr->head = NULL;
	sPtr->tail = NULL;
	sPtr->cur = NULL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: getStackTop() - ���ó��� �ֻ���� ���� �о���� �Լ�(pop������ ����)
��������: sPtr - ���ñ���ü�� �ּ�
getData - ���� �����͸� ������ �������� �ּ�
���ϰ�: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int getStackTop(Stack *sPtr, DataType *getData)
{
	if (isStackEmpty(sPtr))  // stack�� ��������� pop����
	{
		return FALSE;
	}
	*getData = sPtr->head->next->data;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: isStackEmpty() - ������ ����ִ°� �˻�
��������: sPtr - ���ñ���ü�� �ּ�
���ϰ�: ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr) //sPtr->head->next�� sPtr->tail �� ������?
{
	if (sPtr->head->next == sPtr->tail) return TRUE;
	else return FALSE;
}
