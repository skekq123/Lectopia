#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "genericLinkedlist.h"
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: create() - ��ũ�帮��Ʈ �ʱ�ȭ
��������:  lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/

void create(LinkedList * linkedList)
{
	linkedList->head = (Node *)calloc(1,sizeof(Node)); //Head Node ����
	assert(linkedList->head != NULL); //������ ��� ���
	linkedList->tail = (Node *)calloc(1,sizeof(Node)); //Tail Node ����
	assert(linkedList->tail != NULL); //������ ��� ���

	linkedList->head->next = linkedList->tail; //1�� ����
	linkedList->tail->prev = linkedList->head; //2�� ����
	linkedList->head->prev = linkedList->head; //3�� ���� NULL�� �ϸ�, process kill ���� �������� ����
	linkedList->tail->next = linkedList->tail; //4�� ����

	linkedList->cur = NULL; // ó���� Ư���� ����ų�� ����
	linkedList->length = 0; //���� ������ �ϳ��� ����

	return;
} // �ϼ�
  /*--------------------------------------------------------------------------------------
  �Լ��� �� ���: makeNode() - �� ��� ���� �Լ�
  ��������:  dataPtr - �� ��忡 ������ ������ ������ �ּ�
  prev - �� ����� �� ����� �ּ�
  next - �� ����� �� ����� �ּ�
  ���ϰ�: ������ ����� �ּ�
  --------------------------------------------------------------------------------------*/
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size ,void(*myMemCpy)(void *, void *))
{
	Node *np = (Node*)calloc(1,sizeof(Node)+size);
	np->prev = prev;
	np->next = next;
	np->prev->next = np; // �տ� np���� ����
	np->next->prev = np; // �տ� np���� ����
	myMemCpy(np + 1,dataPtr);
	//np->data = *dataPtr;  �̰Ŵ� generic �̾ƴ�
	return np;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: appendFromHead() - ����� �ڿ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(dataPtr, lp->head, lp->head->next, size, myMemCpy);
	lp->cur = (Node*)calloc(1,sizeof(Node)); //�۾��� cur�� �����Ҵ�
	lp->cur->prev = lp->head; // 1��
	lp->cur->next = lp->head->next; // 2��
	lp->head->next->prev = lp->cur; //3��
	lp->head->next = lp->cur; // 4��
	lp->length++; 
	return lp->cur;
}//�Ϸ�
 /*--------------------------------------------------------------------------------------
 �Լ��� �� ���: appendFromTail() - ���ϳ�� �տ� �� ��� �߰�(���� ����)
 ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
 dataPtr - �� ��忡 ������ ������ ������ �ּ�
 ���ϰ�: �߰��� ����� �ּ�
 --------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *)) //�ڿ������� �����͸� �ϳ� �� �߰��ϹǷ� �߰��� ������ ��
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail, size, myMemCpy);

	lp->cur = (Node*)malloc(sizeof(Node)); //�۾��� cur�� �����Ҵ�
	lp->cur->prev = lp->tail->prev; // 1����cur�� prev�� head�� ����Ű�� ����, tail�� prev�� ����Ű��!!
	lp->cur->next = lp->tail; // 2��
	lp->tail->prev->next = lp->cur; // 3����
	lp->tail->prev = lp->cur; // 4��
	lp->length++; // 6��
	return lp->cur; // 7��
} // �ϼ�
  /*--------------------------------------------------------------------------------------
  �Լ��� �� ���: display() - ����Ʈ���� ��� ������ ��� ���
  ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
  print - ��� �� data���� ����� ���� �����Լ��� �����ּ�
  ���ϰ�: ����
  --------------------------------------------------------------------------------------*/
void display(LinkedList *lp, void(*dataPrint)(void *))
{
	if (lp->length == 0) return; 

	lp->cur = lp->head->next; // ��1�� data�� �ִ� ù ��� ����Ű�� �ڵ�
	while (lp->cur != lp->tail)//��length��ŭ ������ ������, length�� ���ٴ� �����Ͽ�
	{
		personPrint(lp->cur+1); // 2�� ��¹�
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
Node * linearSearchUnique(LinkedList *lp, void *target, int(*compare)(void *, void *))
{
	lp->cur = lp->head->next; // ��1�� data�� �ִ� ù ��� ����Ű�� �ڵ�
	while (lp->cur != lp->tail)//��length��ŭ ������ ������, length�� ���ٴ� �����Ͽ�
	{
		if (compare(lp->cur+1, target) == 0)
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
Node ** linearSearchDuplicate(LinkedList *lp, void *target, int searchNodeCount, int(*compare)(void*, void*))
// dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
{
	Node **searchPtr = NULL;
	searchNodeCount = 0;
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail) {
		if (compare(lp->cur+1, target) == 0) {
			(searchNodeCount)++; // ���� ã��
			searchPtr = (Node**)realloc(searchPtr, sizeof(Node));
			assert(searchPtr != NULL); // �����Ҵ� ���н� ����ǥ��
			searchPtr[(searchNodeCount) - 1] = lp->cur;
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
Node * deleteNode(LinkedList *lp, Node *index, void(*dataFree)(void *)) // lp, ã������� �ּ�
{
	if (index == NULL) return NULL;
	index->prev->next = index->next;
	dataFree(index + 1);
	index->next->prev = index->prev;
	free(index);
	lp->length--;
	return index;
	
} //�Ϸ�
  /*--------------------------------------------------------------------------------------
  �Լ��� �� ���: destroy() - ����Ʈ������ ��� ��� ����(head, tail ��� ����)
  ��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
  ���ϰ�: ����
  --------------------------------------------------------------------------------------*/
void destroy(LinkedList *lp, void(*dataFree)(void *))
{
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		lp->cur = lp->cur->next;
		deleteNode(lp, lp->cur, dataFree);
	} 
	dataFree(lp->head);
	dataFree(lp->tail);

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
void sortList(LinkedList *lp, size_t size, int(*compare)(void *, void *), void (*myMemCpy)(void*, void*), void (*dataFree)(void*))  // ��� ����
{
	Node *temp;
	void *temp2;
	int res, i, j;
	temp2 = calloc(1, size); //Personũ�⸸ ����
	
	lp->cur = lp->head->next;
	for (i = 0; i < lp->length-1;i++)
	{
		temp = lp->cur->next;
		for (j = i+1; j<lp->length;j++)
		{
			res = compare(lp->cur + 1, temp + 1);
			if (res == 1) {
				myMemCpy(temp2, temp+1);
				myMemCpy(temp+1, lp->cur+1);
				myMemCpy(lp->cur+1, temp2);
			}
			temp = temp->next;
		}
		lp->cur = lp->cur->next;
	}
	dataFree(temp2); //�޸� ���� ����
	free(temp2);

}
