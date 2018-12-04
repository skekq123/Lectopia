#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "queue.h" 
#include<cstring>

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
	qPtr->queue = (DataType *)calloc(qPtr->qSize, sizeof(DataType));
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : enqueue() - ť�� ������ �ϳ��� ������
�������� : qPtr - ť ����ü�� �ּ�
inData - ť�� ������ ������
���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qPtr, DataType *inData)//��á�� Ȯ��
{
	if (isQueueFull(qPtr)) return FALSE; //��ȭ����
	else {
		qPtr->queue[qPtr->rear] = *inData;
		qPtr->rear = ++(qPtr->rear) % qPtr->qSize;
		/*strcpy(qPtr->queue[qPtr->front].name, inData.name);
		strcpy(qPtr->queue[qPtr->front].num, inData.num);
		strcpy(qPtr->queue[qPtr->front].pnum, inData.pnum);*/
		return TRUE;
	}

}
/*--------------------------------------------------------------------------------------
�Լ��� �� ��� : dequeue() - ť���� ������ �ϳ��� ����
�������� : qPtr - ť ����ü�� �ּ�
getData - ���� �����͸� ������ �������� �ּ�
���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qPtr, DataType * getData) //����ִ��� Ȯ��
{
	if (isQueueEmpty(qPtr)) return FALSE;
	else
	{
		*getData = qPtr->queue[qPtr->front];
		/*printf("%s\n", qPtr->queue[qPtr->front].name);
		printf("%s\n", qPtr->queue[qPtr->front].num);
		printf("%s\n", qPtr->queue[qPtr->front].pnum);*/
		qPtr->front = ++(qPtr->front) % qPtr->qSize;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : printQueue() - ť ���� ��� �����͸� ��� ��
�������� : qPtr - ť ����ü�� �ּ�
print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qPtr)
{
	int i;
	for (i = qPtr->front; i != qPtr->rear; i = ++i % qPtr->qSize) {
		printf("%s\n", qPtr->queue[i].name);
		printf("%s\n", qPtr->queue[i].num);
		printf("%s\n", qPtr->queue[i].pnum);	
	}
} //front�� 3�̰� rear�� 1�� ��쵵 �����ؼ� ! 
  /*--------------------------------------------------------------------------------------
  �Լ���ױ�� : destroyQueue() - ť �Ҹ� �Լ�
  �������� : qPtr - ť ����ü�� �ּ�
  ���ϰ� : ����
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
�Լ��� �� ���: isQueueEmpty() - ť�� ����ִ°� �˻�
��������: qPtr - ť ����ü�� �ּ�
���ϰ�: ��������� TRUE ����, ������� ������ FALSE ����
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
