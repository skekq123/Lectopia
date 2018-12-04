#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
함수명및기능: initStack() - 지정된 크기의 스택을 생성하는 함수
전달인자: sPtr -  스택의 주소
sSize - 스택의 크기
리턴값: 없음
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr, size_t sSize, size_t dataSize)
{
	sPtr->stack = calloc(sSize, dataSize);  // 메모리 할당 & 0으로 초기화(calloc)
	assert(sPtr->stack != NULL);
	sPtr->sSize = sSize;
	sPtr->top = 0;
}
/*-----------------------------------------------------------------------------------
함수명 및 기능 : isStackFull() - 스택이 꽉 차있는지 검사
전달인자 : sPtr - 스택의 주소
리턴값 : 스택이 꽉 차있으면 1, 아니면 0 리턴
-----------------------------------------------------------------------------------*/
int isStackFull(Stack *sPtr) //push할때 검사
{
	if (sPtr->top == sPtr->sSize) return 1;
	else return 0;
}
/*-----------------------------------------------------------------------------------
함수명 및 기능 : isStackEmpty() - 스택이 완전히 비어있는지 검사
전달인자 : sPtr - 스택의 주소
리턴값 : 스택이 비어있으면 1, 아니면 0 리턴
-----------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr) //pop할때 검사
{
	if (sPtr->top == 0) return 1;
	else return 0;
}
/*--------------------------------------------------------------------------------------
함수명및기능: clearStack() - 스택 초기화 함수(모든 데이터 삭제 개념)
전달인자: sPtr - 스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void clearStack(Stack *sPtr)
{
	// TODO
}
/*--------------------------------------------------------------------------------------
함수명및기능: push() - 스택에 데이터 하나를 저장함
전달인자: sPtr - 스택의 주소
inData - 스택에 저장할 데이터
리턴값: 성공적으로 저장하면1, 실패하면0 리턴
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *)) /* stack에 데이터 저장하기 , overflow check*/
{
	if (isStackFull(sPtr) == 1) return 0;
	else {

		memCpy(((char*)sPtr->stack)+ ((sPtr->top) * dataSize), pushData);
		sPtr->top++; 
		return 1;
	}
}
/*--------------------------------------------------------------------------------------
함수명및기능: pop() - 스택에서 데이터 하나를 꺼냄
전달인자: sPtr - 스택의 주소
popData -  꺼낸 데이터를 저장할 기억공간의 주소
리턴값: 성공적으로 꺼내면1, 실패하면0 리턴
--------------------------------------------------------------------------------------*/
int pop(Stack *sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *))  //underflow check
{
	if (isStackEmpty(sPtr) == 1) return 0;
	else
	{
		sPtr->top--;
		memCpy(popData , ((char*)sPtr->stack) + ((sPtr->top) * dataSize));
		memFree(((char*)sPtr->stack) + ((sPtr->top) * dataSize));
		//sPtr->sSize--;
		return 1;
	}
}
/*--------------------------------------------------------------------------------------
함수명및기능: printStack() - 스택의 모든 데이터를 출력 함
전달인자: sPtr -  스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack *sPtr, size_t dataSize, void(*memPrint)(void *)) // pop을 하지는 말기 (출력만 pop했을때 처럼top-1번부터밑으로)
{
	for (int i = sPtr->top - 1; i >= 0; i--)
	{
		memPrint(((char*)sPtr->stack) + (i * dataSize) );
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
함수명및기능: destroyStack() -  스택 소멸 함수
전달인자: sPtr -  스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr, size_t dataSize, void(*memFree)(void *)) //calloc를 한번만 했기 때문에 free도 한번만 하면됨(배열이라)
{
	int i;
	for (i = 0; i < sPtr->top; i++)
	{
		memFree(((char*)sPtr->stack) + ((sPtr->top) * dataSize)*i);
	}
	free(sPtr->stack);
	sPtr->stack = NULL;
	sPtr->sSize = 0;
	sPtr->top = 0;
	//stack은 없어지나, name인 부가메모리 삭제 안되므로, 삭제하기!!!!
} // 마지막에 stack = NULL, sSize = 0, top = 0으로 초기화하기

