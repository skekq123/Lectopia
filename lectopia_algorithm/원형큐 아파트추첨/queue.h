#pragma once 
#pragma warning(disable:4996)
#include "datatype.h"
enum { FALSE, TRUE };

typedef struct _queue {
	DataType *queue; // 동적할당할 메모리를 가리키는 Q pointer
	int qSize;
	int front, rear;
}Queue;

void initQueue(Queue * qPtr, int size); // 큐 생성 및 초기화 함수
int enqueue(Queue * qPtr, DataType *inData);   // 큐에 데이터 하나를 저장함
int dequeue(Queue * qPtr, DataType * getData);  // 큐에서 데이터 하나를 꺼냄
void printQueue(const Queue * qPtr);  // 큐 내의 모든 데이터를 출력(dequeue하는 것은 아님)
void destroyQueue(Queue * qPtr);  // 큐 소멸 함수
int isQueueEmpty(const Queue *qPtr); // 큐가 비어있는가 검사
int isQueueFull(const Queue *qPtr);//큐가 꽉차있는지 검사
