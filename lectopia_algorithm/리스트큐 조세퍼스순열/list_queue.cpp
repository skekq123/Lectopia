#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "listQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ť �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
--------------------------------------------------------------------------------------*/
BOOL createQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp ������ NULL check */
		return FALSE;
	}

	qp->head = (Node *)calloc(1, sizeof(Node));	/* ��� ��� ���� */
	if (qp->head == NULL) {
		return FALSE;
	}
	qp->tail = (Node *)calloc(1, sizeof(Node));	/* ���� ��� ���� */
	if (qp->tail == NULL) {
		free(qp->head);
		return FALSE;
	}
	else { /* ����尡 ���ϳ�带, ���ϳ�尡 ���ϳ�带 ����Ű�� �� */
		qp->head->next = qp->tail;
		qp->tail->next = qp->tail;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - ť�� ����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp ������ NULL check */
		return FALSE;
	}
	/* ť�� ������ ��������� TRUE, �ƴϸ� FALSE ���� */
	if (qp->head->next == qp->tail)
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
enqueData - ť�� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL enqueue(Queue * qp, int enqueData)
{
	Node *cur;
	if (qp == NULL) {  /* qp ������ NULL check */
		return FALSE;
	}

	Node *np = (Node *)calloc(1, sizeof(Node)); /* ���ο� ��� ���� */
	if (np == NULL)		/* �޸� �Ҵ� �����ϸ� enqueue���� */
	{
		return FALSE;
	}
	/* ��带 ���� ��� �ٷ� �տ� ��� �߰� */
	cur = qp->head;
	while (cur->next != qp->tail)  /* ���� ��� �ٷ� �ճ�带 cur�� ����Ű�� �̵� ��Ŵ */
		cur = cur->next;

	cur->next = np;
	np->next = qp->tail;
	np->data = enqueData;	/* ������ ���� */

	return TRUE;

}
/*--------------------------------------------------------------------------------------
Function name	: dequeue - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, int * dequeData)
{
	Node *cur;
	if (qp == NULL) {  /* qp ������ NULL check */
		return FALSE;
	}

	if (isQueueEmpty(qp))	/* ť�� ��������� dequeue �Ұ� */
	{
		return FALSE;
	}
	else {	/* head node �ڿ��� �����͸� ���� �� ������ ��� ���� */
		*dequeData = qp->head->next->data;
		cur = qp->head->next;
		qp->head->next = qp->head->next->next;
		free(cur);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	Node *cur;
	if (qp == NULL) {  /* qp ������ NULL check */
		return;
	}

	if (isQueueEmpty(qp) == TRUE)
	{
		printf("Queue�� ����ֽ��ϴ�!!\n");
		return;
	}
	/* dequeue ������� ����ϱ� - ������ dequeue �Ǵ� ���� �ƴ� */
	cur = qp->head->next;
	while (cur != qp->tail) {
		printf("%5d\n", cur->data);
		cur = cur->next;
	}
	printf("\n\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	Node *cur;
	if (qp == NULL) {  /* qp ������ NULL check */
		return;
	}
	/* ������ ù ������ �� ���� ������ ��� ���� */
	cur = qp->head->next;
	while (cur != qp->tail) {
		qp->head->next = qp->head->next->next;
		free(cur);
		cur = qp->head->next;
	}
	free(qp->head);	/* ����� ���� */
	free(qp->tail);	/* ���ϳ�� ���� */
	qp->head = qp->tail = NULL;	/* head, tail �����͸� NULL�� �ʱ�ȭ */
}