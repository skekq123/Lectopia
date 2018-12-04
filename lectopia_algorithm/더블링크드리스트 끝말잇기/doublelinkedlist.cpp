#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "doublelinkedlist.h"
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: create() - ��ũ�帮��Ʈ �ʱ�ȭ
��������:  lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void create(LinkedList * lp)
{
	lp->head = (Node *)malloc(sizeof(Node)); //Head Node ����
	assert(lp->head != NULL); //������ ��� ���
	lp->tail = (Node *)malloc(sizeof(Node)); //Tail Node ����
	assert(lp->tail != NULL); //������ ��� ���

	lp->head->next = lp->tail; //1�� ����
	lp->tail->prev = lp->head; //2�� ����
	lp->head->prev = lp->head; //3�� ���� NULL�� �ϸ�, process kill ���� �������� ����
	lp->tail->next = lp->tail; //4�� ����

	lp->cur = NULL; // ó���� Ư���� ����ų�� ����
	lp->length = 0; //���� ������ �ϳ��� ����

	return;
} // �ϼ�
  /*--------------------------------------------------------------------------------------
  �Լ��� �� ���: makeNode() - �� ��� ���� �Լ�
  ��������:  dataPtr - �� ��忡 ������ ������ ������ �ּ�
  prev - �� ����� �� ����� �ּ�
  next - �� ����� �� ����� �ּ�
  ���ϰ�: ������ ����� �ּ�
  --------------------------------------------------------------------------------------*/
Node * makeNode(DataType *dataPtr, Node *prev, Node *next)
{
	Node *np = (Node*)malloc(sizeof(Node));
	np->prev = prev;
	np->next = next;
	np->prev->next = np; // �տ� np���� ����
	np->next->prev = np; // �տ� np���� ����
	np->data = *dataPtr;
	return np;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: appendFromHead() - ����� �ڿ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->head, lp->head->next);
	/*lp->cur = (Node*)malloc(sizeof(Node)); //�۾��� cur�� �����Ҵ�
	lp->cur->prev = lp->head; // 1��
	lp->cur->next = lp->head->next; // 2��
	lp->head->next->prev = lp->cur; //3��
	lp->head->next = lp->cur; // 4��
	lp->cur->data = *dataPtr; // 5��*/
	lp->length++; // 6��
	return lp->cur;
}//�Ϸ�
 /*--------------------------------------------------------------------------------------
 �Լ��� �� ���: appendFromTail() - ���ϳ�� �տ� �� ��� �߰�(���� ����)
 ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
 dataPtr - �� ��忡 ������ ������ ������ �ּ�
 ���ϰ�: �߰��� ����� �ּ�
 --------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *lp, DataType *dataPtr) //�ڿ������� �����͸� �ϳ� �� �߰��ϹǷ� �߰��� ������ ��
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail);

	/*lp->cur = (Node*)malloc(sizeof(Node)); //�۾��� cur�� �����Ҵ�
	lp->cur->prev = lp->tail->prev; // 1����cur�� prev�� head�� ����Ű�� ����, tail�� prev�� ����Ű��!!
	lp->cur->next = lp->tail; // 2��
	lp->tail->prev->next = lp->cur; // 3����
	lp->tail->prev = lp->cur; // 4��
	lp->cur->data = *dataPtr; // 5�� ����ü���� ���� �о ����*/
	lp->length++; // 6��
	return lp->cur; // 7��
} // �ϼ�
  /*--------------------------------------------------------------------------------------
  �Լ��� �� ���: display() - ����Ʈ���� ��� ������ ��� ���
  ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
  print - ��� �� data���� ����� ���� �����Լ��� �����ּ�
  ���ϰ�: ����
  --------------------------------------------------------------------------------------*/
void display(LinkedList *lp, void(*print)(DataType *))
{
	lp->cur = lp->head->next; // ��1�� data�� �ִ� ù ��� ����Ű�� �ڵ�
	while (lp->cur != lp->tail)//��length��ŭ ������ ������, length�� ���ٴ� �����Ͽ�
	{
		print(&lp->cur->data); // 2�� ��¹�
		lp->cur = lp->cur->next; // 3�� ���� ���� �̵�
	}
	return;
}//�ϼ�
 /*--------------------------------------------------------------------------------------
 �Լ��� �� ���: searchUnique() - ���޵� �����Ϳ� ��ġ�ϴ� ��� �˻� �Լ�
 ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
 dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
 compare - data���� �񱳸� ���� �����Լ��� �����ּ�
 ���ϰ�: ã�� ����� �ּ� ����/���� �� NULL pointer ����
 --------------------------------------------------------------------------------------*/
Node * searchUnique(LinkedList *lp, DataType *dataPtr, int(*compare)(DataType *, DataType *))
{
	lp->cur = lp->head->next; // ��1�� data�� �ִ� ù ��� ����Ű�� �ڵ�
	while (lp->cur != lp->tail)//��length��ŭ ������ ������, length�� ���ٴ� �����Ͽ�
	{
		if (compare(dataPtr, &lp->cur->data) == 0)
			return lp->cur;
		lp->cur = lp->cur->next; // 3�� ���� ���� �̵�
	}
	return NULL;
}// �޴� 2���� �Լ��� ���(Ȯ���Ҷ� ù���, �߰����, ���������)
 /*--------------------------------------------------------------------------------------
 �Լ��� �� ���: searchDuplicate() - ���޵� �����Ϳ� ��ġ�ϴ� ��� ��带 ���� �˻��ϴ� �Լ�
 ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
 searchCnt - ã�� ����� ������ ������ ������ �ּ�
 dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
 compare - data���� �񱳸� ���� �����Լ��� �����ּ�
 ���ϰ�: ã�� ����� �ּҸ�Ϲ迭�� ���� �ּ� ����/���� �� NULL pointer ����
 --------------------------------------------------------------------------------------*/
Node ** searchDuplicate(LinkedList *lp, int *searchCnt, DataType *dataPtr, int(*compare)(DataType *, DataType *))
// dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
{
	Node **searchPtr = NULL;
	*searchCnt = 0;
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail) {
		if (compare(dataPtr, &lp->cur->data) == 0) {
			(*searchCnt)++; // ���� ã��
			searchPtr = (Node**)realloc(searchPtr, sizeof(Node));
			assert(searchPtr != NULL); // �����Ҵ� ���н� ����ǥ��
			searchPtr[(*searchCnt) - 1] = lp->cur;
		}
		lp->cur = lp->cur->next;
	}
	return searchPtr;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: deleteNode() - ����Ʈ������ target ��� ����
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
target - ������ ����� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void deleteNode(LinkedList *lp, Node *target) // lp, ã������� �ּ�
{
	target->prev->next = target->next;
	target->next->prev = target->prev;
	free(target);
	lp->length--;
	return;
} //�Ϸ�
  /*--------------------------------------------------------------------------------------
  �Լ��� �� ���: destroy() - ����Ʈ������ ��� ��� ����(head, tail ��� ����)
  ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
  ���ϰ�: ����
  --------------------------------------------------------------------------------------*/
void destroy(LinkedList *lp)
{
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		Node *temp;
		temp = lp->cur;
		lp->cur = lp->cur->next;
		free(temp);
	} //�ӽó�� temp�� �����ؼ� ���� �����ϰ�, free�ϰ� �ٽ� �����Ҷ� ����ǵ���
	free(lp->head);
	free(lp->tail);

	lp->head = NULL;
	lp->cur = NULL;
	lp->tail = NULL;
	lp->length = 0;
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: sortList() - ����Ʈ���� ��带 �����Լ��� ���ش�� �����ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *lp, int(*compare)(DataType *, DataType *))  // ��� ����
{
	DataType temp;
	for (lp->cur = lp->head->next; lp->cur->next != lp->tail; lp->cur = lp->cur->next)
	{
		for (Node *tp = lp->cur->next; tp != lp->tail; tp = tp->next)
		{
			if (compare(&lp->cur->data, &tp->data) == 1)
			{
				temp = lp->cur->data;
				lp->cur->data = tp->data;
				tp->data = temp;
			}
		}
	}
	return;
}
