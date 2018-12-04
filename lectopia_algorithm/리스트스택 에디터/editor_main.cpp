#include "liststack.h"
#include <stdio.h>
#include<assert.h>

int main()
{
	FILE *fp;
	char ch, data, del;
	Stack Lstk, Rstk;     /* ���ð�������ü ����*/
	int num;
	initStack(&Lstk); /* �����ʱ�ȭ*/
	initStack(&Rstk); /* �����ʱ�ȭ*/

	fp = fopen("C:\\data\\editor2.txt", "rt");
	assert(fp != NULL);
	while (1) {
		ch = fgetc(fp);
		if (ch == '\n') break;
		push(&Lstk, ch);
	}
	fscanf(fp,"%d", &num);  //��ɰ��� �Է¹ޱ�
	ch = fgetc(fp);  //�����ִ� �������
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
		case 'P':   ch = fgetc(fp);  //���� ����
					ch = fgetc(fp);
				    push(&Lstk, ch);
					break;
		}
		ch = fgetc(fp); //���� ����
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
//   int type ���� �Լ�
//-------------------------------------
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: printInt() - �������ڷ� �Ѱ��� int���� ������ format���� ��� ��
��������: p - ����� ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printchar(DataType *p)
{
	printf("%c", *p);
}