#pragma once
#pragma warning(disable:4996)
#include "datatype.h"
typedef struct _stack {  //���ð�������ü
	DataType *stack;       // stack���� ���Ǵ� �迭�� ����Ű�� ������ ���� (���ù迭�� �����Ҵ� �ϱ�����)
	int sSize;             // ������ ũ��
	int top;               // ������ ��,��� ��ġ���� ����
}Stack;

void initStack(Stack *, int);     //���� �޸� �Ҵ� �� �ʱ�ȭ �Լ� top�� ��ġ�� 0�� �ʱ�ȭ
void clearStack(Stack *);         // ���� ���� �Լ�
int push(Stack *, DataType);           // ���ÿ� ������ �����ϴ� �Լ�
int pop(Stack *, DataType *);          // ���ÿ��� �����͸� ������ �Լ�
void printStack(const Stack*, void(*print)(DataType *));    // ���� ���� ��� �����͸� ����ϴ� �Լ�
void destroyStack(Stack *);       // ���� �޸� ���� �Լ�
int isStackFull(Stack *sPtr);     // ������ �� ���ִ��� �˻�
int isStackEmpty(Stack *sPtr);    // ������ ����ִ��� �˻�
