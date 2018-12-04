#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "queue.h" 

/*--------------------------------------------------------------------------------------
�Լ���ױ�� : initQueue() - ť �ʱ�ȭ �Լ�
�������� : qPtr - ť ����ü�� �ּ�
size - ť�� ũ��
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void initQueue(Queue * qPtr, int size)
{
	qPtr->qSize = size;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->queue = (int *)calloc(sizeof(int), qPtr->qSize);
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : enqueue() - ť�� ������ �ϳ��� ������
�������� : qPtr - ť ����ü�� �ּ�
inData - ť�� ������ ������
���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qPtr, DataType inData)
{
	if ((qPtr->rear + 1) % qPtr->qSize == qPtr->front) // rear�� �������뿡 ������ put�Ұ� 
	{

		printf("Queue Overflow !!\n");
		return FALSE;
	}

	qPtr->queue[qPtr->rear] = inData;
	qPtr->rear++;
	qPtr->rear = (qPtr->rear) % qPtr->qSize;
	return TRUE;

}
/*--------------------------------------------------------------------------------------
�Լ��� �� ��� : dequeue() - ť���� ������ �ϳ��� ����
�������� : qPtr - ť ����ü�� �ּ�
getData - ���� �����͸� ������ �������� �ּ�
���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qPtr, DataType * getData)
{
	if (isQueueEmpty(qPtr)) // ť�� ��������� dequeue �Ұ� 
	{
		printf("Queue Underflow !!\n");
		return FALSE;
	}

	*getData = qPtr->queue[qPtr->front];
	qPtr->front++;
	qPtr->front = (qPtr->front) % qPtr->qSize;

	return TRUE;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : printQueue() - ť ���� ��� �����͸� ��� ��
�������� : qPtr - ť ����ü�� �ּ�
print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qPtr, void(*print)(DataType *))
{
	if (isQueueEmpty(qPtr) == TRUE)
	{
		printf("Queue�� ����ֽ��ϴ�!!\n");
		return;
	}
	for (int i = qPtr->front; i != qPtr->rear; i = (i + 1) % qPtr->qSize)
	{
		print(&qPtr->queue[i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : destroyQueue() - ť �Ҹ� �Լ�
�������� : qPtr - ť ����ü�� �ּ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qPtr)
{
	qPtr->qSize = 0;
	free(qPtr->queue);
	qPtr->queue = NULL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: isQueueEmpty() - ť�� ����ִ°� �˻�
��������: qPtr - ť ����ü�� �ּ�
���ϰ�: ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qPtr)
{
	if (qPtr->front == qPtr->rear)
		return TRUE;
	else
		return FALSE;
}
