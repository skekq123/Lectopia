#include "liststack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
함수명및기능 : initStack() -  링크드리스트로 관리되는 스택 생성 함수
전달인자 : sPtr - 스택관리 구조체의 주소
리턴값 : 없음
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr)
{
	sPtr->head = (Snode *)calloc(1, sizeof(Snode)); //헤드 노드 생성 calloc(할당방갯수,할당방의크기)
	assert(sPtr->head != NULL);
	sPtr->tail = (Snode *)calloc(1, sizeof(Snode)); //테일 노드 생성
	assert(sPtr->tail != NULL);
	/*헤드노드가 테일노드를, 테일노드가 테일노드를 가리키게 함*/
	sPtr->head->next = sPtr->tail;
	sPtr->tail->next = sPtr->tail;
	sPtr->cur = NULL;
	return;
}
/*--------------------------------------------------------------------------------------
함수명및기능 : push() - 스택에 데이터 하나를 저장함
전달인자 : sPtr - 스택구조체의 주소
inData - 스택에 저장할 데이터
리턴값 : 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, DataType inData) /* stack에 데이터 저장하기 */
{
	sPtr->cur = (Snode*)calloc(1, sizeof(Snode));
	if (sPtr->cur == NULL) return FALSE;
	else {
		sPtr->cur->data = inData;
		sPtr->cur->next = sPtr->head->next;
		sPtr->head->next = sPtr->cur;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
함수명 및 기능 : pop() - 스택에서 데이터 하나를 꺼냄
전달인자 : sPtr - 스택구조체의 주소
popData - 꺼낸 데이터를 저장할 기억공간의 주소
리턴값 : 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int pop(Stack *sPtr, DataType *popData)
{
	if (isStackEmpty(sPtr)) return FALSE;
	else
	{
		*popData = sPtr->head->next->data; //데이터 저장
		sPtr->cur = sPtr->head->next;
		sPtr->head->next = sPtr->head->next->next; // 다음으로 연결
		free(sPtr->cur);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
함수명및기능 : printStack() - 스택의 모든 데이터를 출력 함
전달인자 : sPtr - 스택구조체의 주소
print -  DataType의 내용을 출력하는 출력 보조 함수
리턴값 : 없음
--------------------------------------------------------------------------------------*/
void printStack(Stack *sPtr, void(*print)(DataType *))
{

	for (sPtr->cur = sPtr->head->next; sPtr->cur != sPtr->tail; sPtr->cur = sPtr->cur->next)
	{
		print(&sPtr->cur->data);
	}

}
/*--------------------------------------------------------------------------------------
함수명및기능 : destroyStack() - 스택 소멸 함수
전달인자 : sPtr - 스택구조체의 주소
리턴값 : 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr)
{
	for (sPtr->cur = sPtr->head->next; sPtr->cur != sPtr->tail; )
	{
		Snode *temp = sPtr->cur;
		sPtr->cur = sPtr->cur->next;
		free(temp);
	}
	free(sPtr->head);
	free(sPtr->tail);
	sPtr->head = NULL;
	sPtr->tail = NULL;
	sPtr->cur = NULL;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: getStackTop() - 스택내의 최상단의 값을 읽어오는 함수(pop하지는 않음)
전달인자: sPtr - 스택구조체의 주소
getData - 꺼낸 데이터를 저장할 기억공간의 주소
리턴값: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int getStackTop(Stack *sPtr, DataType *getData)
{
	if (isStackEmpty(sPtr))  // stack이 비어있으면 pop실패
	{
		return FALSE;
	}
	*getData = sPtr->head->next->data;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: isStackEmpty() - 스택이 비어있는가 검사
전달인자: sPtr - 스택구조체의 주소
리턴값: 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr) //sPtr->head->next가 sPtr->tail 과 같은가?
{
	if (sPtr->head->next == sPtr->tail) return TRUE;
	else return FALSE;
}
