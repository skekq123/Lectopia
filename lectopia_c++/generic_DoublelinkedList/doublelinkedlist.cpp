#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "genericLinkedlist.h"
/*--------------------------------------------------------------------------------------
함수명 및 기능: create() - 링크드리스트 초기화
전달인자:  lp - 링크드리스트 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/

void create(LinkedList * linkedList)
{
	linkedList->head = (Node *)calloc(1,sizeof(Node)); //Head Node 생성
	assert(linkedList->head != NULL); //실패할 경우 대비
	linkedList->tail = (Node *)calloc(1,sizeof(Node)); //Tail Node 생성
	assert(linkedList->tail != NULL); //실패할 경우 대비

	linkedList->head->next = linkedList->tail; //1번 연결
	linkedList->tail->prev = linkedList->head; //2번 연결
	linkedList->head->prev = linkedList->head; //3번 연결 NULL로 하면, process kill 당해 강제종료 당함
	linkedList->tail->next = linkedList->tail; //4번 연결

	linkedList->cur = NULL; // 처음에 특별히 가리킬게 없음
	linkedList->length = 0; //아직 데이터 하나도 없음

	return;
} // 완성
  /*--------------------------------------------------------------------------------------
  함수명 및 기능: makeNode() - 새 노드 생성 함수
  전달인자:  dataPtr - 새 노드에 저장할 데이터 영역의 주소
  prev - 새 노드의 앞 노드의 주소
  next - 새 노드의 뒷 노드의 주소
  리턴값: 생성된 노드의 주소
  --------------------------------------------------------------------------------------*/
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size ,void(*myMemCpy)(void *, void *))
{
	Node *np = (Node*)calloc(1,sizeof(Node)+size);
	np->prev = prev;
	np->next = next;
	np->prev->next = np; // 앞에 np생략 가능
	np->next->prev = np; // 앞에 np생략 가능
	myMemCpy(np + 1,dataPtr);
	//np->data = *dataPtr;  이거는 generic 이아님
	return np;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: appendFromHead() - 헤드노드 뒤에 새 노드 추가(역순 저장)
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 새 노드에 저장할 데이터 영역의 주소
리턴값: 추가한 노드의 주소
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(dataPtr, lp->head, lp->head->next, size, myMemCpy);
	lp->cur = (Node*)calloc(1,sizeof(Node)); //작업용 cur에 동적할당
	lp->cur->prev = lp->head; // 1번
	lp->cur->next = lp->head->next; // 2번
	lp->head->next->prev = lp->cur; //3번
	lp->head->next = lp->cur; // 4번
	lp->length++; 
	return lp->cur;
}//완료
 /*--------------------------------------------------------------------------------------
 함수명 및 기능: appendFromTail() - 테일노드 앞에 새 노드 추가(정순 저장)
 전달인자: lp - 링크드리스트 정보 구조체의 주소
 dataPtr - 새 노드에 저장할 데이터 영역의 주소
 리턴값: 추가한 노드의 주소
 --------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *)) //뒤에서부터 데이터를 하나 씩 추가하므로 추가한 순서로 됨
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail, size, myMemCpy);

	lp->cur = (Node*)malloc(sizeof(Node)); //작업용 cur에 동적할당
	lp->cur->prev = lp->tail->prev; // 1번★cur의 prev를 head로 가리키지 말고, tail의 prev로 가리키기!!
	lp->cur->next = lp->tail; // 2번
	lp->tail->prev->next = lp->cur; // 3번★
	lp->tail->prev = lp->cur; // 4번
	lp->length++; // 6번
	return lp->cur; // 7번
} // 완성
  /*--------------------------------------------------------------------------------------
  함수명 및 기능: display() - 리스트내의 모드 데이터 노드 출력
  전달인자: lp - 링크드리스트 정보 구조체의 주소
  print - 노드 내 data영역 출력을 위한 보조함수의 시작주소
  리턴값: 없음
  --------------------------------------------------------------------------------------*/
void display(LinkedList *lp, void(*dataPrint)(void *))
{
	if (lp->length == 0) return; 

	lp->cur = lp->head->next; // ★1번 data가 있는 첫 노드 가리키는 코드
	while (lp->cur != lp->tail)//★length만큼 돌려도 되지만, length가 없다는 전제하에
	{
		personPrint(lp->cur+1); // 2번 출력문
		lp->cur = lp->cur->next; // 3번 다음 노드로 이동
	}
	return;
}//완성
 /*--------------------------------------------------------------------------------------
 함수명 및 기능: searchUnique() - 전달된 데이터와 일치하는 노드 검색 함수
 전달인자: lp - 링크드리스트 정보 구조체의 주소
 dataPtr - 검색할 데이터가 저장된 영역의 주소
 compare - data영역 비교를 위한 보조함수의 시작주소
 리턴값: 찾은 노드의 주소 리턴/없을 시 NULL pointer 리턴
 --------------------------------------------------------------------------------------*/
Node * linearSearchUnique(LinkedList *lp, void *target, int(*compare)(void *, void *))
{
	lp->cur = lp->head->next; // ★1번 data가 있는 첫 노드 가리키는 코드
	while (lp->cur != lp->tail)//★length만큼 돌려도 되지만, length가 없다는 전제하에
	{
		if (compare(lp->cur+1, target) == 0)
			return lp->cur;
		lp->cur = lp->cur->next; // 3번 다음 노드로 이동
	}
	return NULL;
}// 메뉴 2번인 함수와 비슷(확인할때 첫사람, 중간사람, 마지막사람)
 /*--------------------------------------------------------------------------------------
 함수명 및 기능: searchDuplicate() - 전달된 데이터와 일치하는 모든 노드를 다중 검색하는 함수
 전달인자: lp - 링크드리스트 정보 구조체의 주소
 searchCnt - 찾은 노드의 개수를 저장할 영역의 주소
 dataPtr - 검색할 데이터가 저장된 영역의 주소
 compare - data영역 비교를 위한 보조함수의 시작주소
 리턴값: 찾은 노드의 주소목록배열의 시작 주소 리턴/없을 시 NULL pointer 리턴
 --------------------------------------------------------------------------------------*/
Node ** linearSearchDuplicate(LinkedList *lp, void *target, int searchNodeCount, int(*compare)(void*, void*))
// dataPtr과 일치하는 노드의 주소를 담고 있는 Node *배열의 시작주소 리턴/없을 시 NULL pointer 리턴
{
	Node **searchPtr = NULL;
	searchNodeCount = 0;
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail) {
		if (compare(lp->cur+1, target) == 0) {
			(searchNodeCount)++; // 갯수 찾기
			searchPtr = (Node**)realloc(searchPtr, sizeof(Node));
			assert(searchPtr != NULL); // 동적할당 실패시 오류표시
			searchPtr[(searchNodeCount) - 1] = lp->cur;
		}
		lp->cur = lp->cur->next;
	}
	return searchPtr;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: deleteNode() - 리스트내에서 target 노드 삭제
전달인자: lp - 링크드리스트 정보 구조체의 주소
target - 삭제할 노드의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
Node * deleteNode(LinkedList *lp, Node *index, void(*dataFree)(void *)) // lp, 찾은노드의 주소
{
	if (index == NULL) return NULL;
	index->prev->next = index->next;
	dataFree(index + 1);
	index->next->prev = index->prev;
	free(index);
	lp->length--;
	return index;
	
} //완료
  /*--------------------------------------------------------------------------------------
  함수명 및 기능: destroy() - 리스트내에서 모든 노드 삭제(head, tail 노드 포함)
  전달인자: lp - 링크드리스트 정보 구조체의 주소
  리턴값: 없음
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
함수명 및 기능: sortList() - 리스트내의 노드를 보조함수의 기준대로 정렬하는 함수
전달인자: lp - 링크드리스트 정보 구조체의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *lp, size_t size, int(*compare)(void *, void *), void (*myMemCpy)(void*, void*), void (*dataFree)(void*))  // 노드 정렬
{
	Node *temp;
	void *temp2;
	int res, i, j;
	temp2 = calloc(1, size); //Person크기만 잡음
	
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
	dataFree(temp2); //메모리 누수 방지
	free(temp2);

}
