#pragma once
#pragma warning(disable:4996) /* VS2005 �̻󿡼� �߻��ϴ� �ܼ� �Լ� ��� ���� */
#include "person.h"

typedef struct _node Node;    // ����ü ��� ����������(�̸� �ص� ����!)

struct _node {         // �����͸� ������ ���(�ڱ����� ����ü)
	Node *prev;               // �� ��带 ����Ű�� ���
	Node *next;               // �� ��带 ����Ű�� ���
};

typedef struct _linkedList {   // ����Ʈ ���� ����ü
	Node *head;               // ��������� (����� ����Ŵ)
	Node *cur;                // Ư�� �۾� �� ��带 ����Ű�� ���� ������
	Node *tail;               // ���������� (���ϳ�� ����Ŵ)
	int length;               // ���� �����ͳ���� ����
}LinkedList;  //���������� ������ �Ⱥ��������� �׳� ����ü�� ����, cur�� �۾��� ������

			  //-------------------------------------------------------------------------------------------
			  //                                 ��ũ�帮��Ʈ ���� �Լ� 
			  //-------------------------------------------------------------------------------------------
void create(LinkedList *linkedList); 
Node * appendFromHead(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void *));     
Node * appendFromTail(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void *));    
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *));
Node * deleteNode(LinkedList *linkedList, Node *index, void(*dataFree)(void *));
Node * linearSearchUnique(LinkedList *linkedList, void *target, int(*compare)(void *, void *)); 
Node ** linearSearchDuplicate(LinkedList *linkedList, void *target, int searchNodeCount, int(*compare)(void*, void*)); 
void sortList(LinkedList *lp, size_t size, int(*compare)(void *, void *), void(*myMemCpy)(void*, void*), void(*dataFree)(void*));
void display(LinkedList *linkedList, void(*dataPrint)(void *));       
void destroy(LinkedList *linkedList, void (*dataFree)(void *));                                