#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "queue.h" 

/*--------------------------------------------------------------------------------------
함수명및기능 : initQueue() - 큐 초기화 함수
전달인자 : qPtr - 큐 구조체의 주소
size - 큐의 크기
리턴값 : 없음
--------------------------------------------------------------------------------------*/
void initQueue(Queue * qPtr, int size)
{
	qPtr->qSize = size;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->queue = (DataType *)calloc(qPtr->qSize, sizeof(DataType));
}
/*--------------------------------------------------------------------------------------
함수명및기능 : enqueue() - 큐에 데이터 하나를 저장함
전달인자 : qPtr - 큐 구조체의 주소
inData - 큐에 저장할 데이터
리턴값 : 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qPtr, DataType inData)//꽉찼나 확인
{
	if (isQueueFull(qPtr)) return FALSE; //포화상태
	else {
		qPtr->queue[qPtr->rear] = inData;
		qPtr->rear = ++(qPtr->rear) % qPtr->qSize;
		return TRUE;
	}

}
/*--------------------------------------------------------------------------------------
함수명 및 기능 : dequeue() - 큐에서 데이터 하나를 꺼냄
전달인자 : qPtr - 큐 구조체의 주소
getData - 꺼낸 데이터를 저장할 기억공간의 주소
리턴값 : 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qPtr, DataType * getData) //비어있는지 확인
{
	if (isQueueEmpty(qPtr)) return FALSE;
	else
	{
		*getData = qPtr->queue[qPtr->front];
		qPtr->front = ++(qPtr->front) % qPtr->qSize;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
함수명및기능 : printQueue() - 큐 내의 모든 데이터를 출력 함
전달인자 : qPtr - 큐 구조체의 주소
print -  DataType의 내용을 출력하는 출력 보조 함수
리턴값 : 없음
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qPtr, void(*print)(DataType *))
{
	int i;
	for (i = qPtr->front; i != qPtr->rear; i = ++i % qPtr->qSize) {
		print(&qPtr->queue[i]);
		printf("\n");
	}
} //front가 3이고 rear이 1일 경우도 생각해서 ! 
/*--------------------------------------------------------------------------------------
함수명및기능 : destroyQueue() - 큐 소멸 함수
전달인자 : qPtr - 큐 구조체의 주소
리턴값 : 없음
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qPtr)
{
	free(qPtr->queue);
	qPtr->queue = NULL;
	qPtr->qSize = 0;
	qPtr->front = 0;
	qPtr->rear = 0;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: isQueueEmpty() - 큐가 비어있는가 검사
전달인자: qPtr - 큐 구조체의 주소
리턴값: 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qPtr)
{
	if (qPtr->front == qPtr->rear) return TRUE;
	else return FALSE;
}
int isQueueFull(const Queue *qPtr)
{
	if (qPtr->rear == (qPtr->front + (qPtr->qSize - 1)) % qPtr->qSize) return TRUE;
	else return FALSE;
}
