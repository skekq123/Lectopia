#pragma once
#pragma warning(disable:4996) /* VS2005 이상에서 발생하는 콘솔 함수 경고 제거 */
#include "person.h"

typedef struct _node Node;    // 구조체 노드 형명재지정(미리 해도 가능!)

struct _node {         // 데이터를 보관할 노드(자기참조 구조체)
	Node *prev;               // 앞 노드를 가리키는 멤버
	Node *next;               // 뒷 노드를 가리키는 멤버
};

typedef struct _linkedList {   // 리스트 관리 구조체
	Node *head;               // 헤드포인터 (헤드노드 가리킴)
	Node *cur;                // 특정 작업 시 노드를 가리키기 위한 포인터
	Node *tail;               // 테일포인터 (테일노드 가리킴)
	int length;               // 실제 데이터노드의 갯수
}LinkedList;  //★전달인자 여러개 안보내기위해 그냥 구조체로 만듦, cur은 작업용 포인터

			  //-------------------------------------------------------------------------------------------
			  //                                 링크드리스트 관리 함수 
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
