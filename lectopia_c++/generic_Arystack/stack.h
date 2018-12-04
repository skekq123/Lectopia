#pragma once
#pragma warning(disable:4996)

typedef struct _stack {  //���ð�������ü
	void *stack;       // stack���� ���Ǵ� �迭�� ����Ű�� ������ ���� (���ù迭�� �����Ҵ� �ϱ�����)
	int sSize;             // ������ ũ��
	int top;               // ������ ��,��� ��ġ���� ����
}Stack;

void initStack(Stack *sPtr, size_t sSize, size_t dataSize);     //���� �޸� �Ҵ� �� �ʱ�ȭ �Լ� top�� ��ġ�� 0�� �ʱ�ȭ
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *));           // ���ÿ� ������ �����ϴ� �Լ�
int pop(Stack *sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *));          // ���ÿ��� �����͸� ������ �Լ�
void printStack(const Stack *sPtr, size_t dataSize, void(*memPrint)(void *));    // ���� ���� ��� �����͸� ����ϴ� �Լ�
void destroyStack(Stack *sPtr, size_t dataSize, void (*memFree)(void *));       // ���� �޸� ���� �Լ�
int isStackFull(Stack *sPtr);     // ������ �� ���ִ��� �˻�
int isStackEmpty(Stack *sPtr);    // ������ ����ִ��� �˻�

