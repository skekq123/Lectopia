#pragma once 
#pragma warning(disable:4996)
#include "datatype.h"
enum { FALSE, TRUE };

typedef struct _queue {
	DataType *queue; // �����Ҵ��� �޸𸮸� ����Ű�� Q pointer
	int qSize;
	int front, rear;
}Queue;

void initQueue(Queue * qPtr, int size); // ť ���� �� �ʱ�ȭ �Լ�
int enqueue(Queue * qPtr, DataType *inData);   // ť�� ������ �ϳ��� ������
int dequeue(Queue * qPtr, DataType * getData);  // ť���� ������ �ϳ��� ����
void printQueue(const Queue * qPtr);  // ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�)
void destroyQueue(Queue * qPtr);  // ť �Ҹ� �Լ�
int isQueueEmpty(const Queue *qPtr); // ť�� ����ִ°� �˻�
int isQueueFull(const Queue *qPtr);//ť�� �����ִ��� �˻�
