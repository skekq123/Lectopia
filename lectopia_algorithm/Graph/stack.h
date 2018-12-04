#pragma once
#pragma warning(disable:4996)
#include "datatype.h"

typedef struct _stacknode Snode;
struct _stacknode
{
	Snode *prev;
	DataType data;
	Snode *next;
};

typedef struct _stack
{
	Snode *head;
	Snode *tail;
	Snode *cur;
}Stack;

void initStack(Stack *sPtr);  /*  ��ũ�帮��Ʈ�� �����Ǵ� ���� ���� �Լ� */
int push(Stack *sPtr, DataType indata); /*  ���ÿ� ������ �ϳ��� ������ */
int pop(Stack *sPtr, DataType *popData); /*  ���ÿ��� ������ �ϳ��� ���� */
void printStack(Stack *sPtr, void(*print)(DataType *));  /*  ������ ��� �����͸� ��� �� */
void destroyStack(Stack *sPtr); /*  ���� �Ҹ� �Լ� */
void deleteNode(Stack *sPtr, Snode *dp); /*  ��� ���� �Լ� */
int getStackTop(Stack *sPtr, DataType *getData);  /*  ���ó��� �ֻ���� ���� �о���� �Լ�(pop������ ����) */
int isStackEmpty(Stack *sPtr); /* ������ ����ִ°� �˻� */

