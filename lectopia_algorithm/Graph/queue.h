#pragma once 
#pragma warning(disable:4996)
#include "datatype.h"

typedef struct _queue {
	DataType *queue;
	int qSize;
	int front, rear;
}Queue;

void initQueue(Queue * qPtr, int size); // ť ���� �� �ʱ�ȭ �Լ�
int enqueue(Queue * qPtr, DataType inData);   // ť�� ������ �ϳ��� ������
int dequeue(Queue * qPtr, DataType * getData);  // ť���� ������ �ϳ��� ����
void printQueue(const Queue * qPtr, void(*print)(DataType *));  // ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�)
void destroyQueue(Queue * qPtr);  // ť �Ҹ� �Լ�
int isQueueEmpty(const Queue *qPtr); // ť�� ����ִ°� �˻�

