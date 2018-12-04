#include "liststack.h"
#include <stdio.h>
#include<assert.h>

int main()
{
	FILE *fp;
	char ch, data, del;
	Stack Lstk, Rstk;     /* 스택관리구조체 생성*/
	int num;
	initStack(&Lstk); /* 스택초기화*/
	initStack(&Rstk); /* 스택초기화*/

	fp = fopen("C:\\data\\editor2.txt", "rt");
	assert(fp != NULL);
	while (1) {
		ch = fgetc(fp);
		if (ch == '\n') break;
		push(&Lstk, ch);
	}
	fscanf(fp,"%d", &num);  //명령갯수 입력받기
	ch = fgetc(fp);  //남아있는 개행삭제
	while (ch != EOF) {
		ch = fgetc(fp);
		switch (ch) {
		case 'L':  if (isStackEmpty(&Lstk) == 1) break; 
				   pop(&Lstk, &data);
				   push(&Rstk, data);
					break;
		case 'D':   if (isStackEmpty(&Rstk) == 1) break;
				    pop(&Rstk, &data);
				    push(&Lstk, data);
					break;
		case 'B':   pop(&Lstk, &del);
					break;
		case 'P':   ch = fgetc(fp);  //띄어쓰기 삭제
					ch = fgetc(fp);
				    push(&Lstk, ch);
					break;
		}
		ch = fgetc(fp); //개행 삭제
	}
	while (1)
	{
		if (isStackEmpty(&Lstk) == 1)
		{
			printStack(&Rstk, printchar);
			break;
		}
		pop(&Lstk, &data);
		push(&Rstk, data);
	}
	printf("\n");
	destroyStack(&Lstk);
	destroyStack(&Rstk);
	return 0;
}
//-------------------------------------
//   int type 보조 함수
//-------------------------------------
/*--------------------------------------------------------------------------------------
함수명 및 기능: printInt() - 전달인자로 넘겨진 int값을 정해진 format으로 출력 함
전달인자: p - 출력할 정수의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void printchar(DataType *p)
{
	printf("%c", *p);
}