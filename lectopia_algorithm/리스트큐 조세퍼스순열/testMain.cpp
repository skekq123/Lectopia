#include "listQueue.h"
#include <stdio.h>
//--------------------------------------------------------------------------------
//   main()
//--------------------------------------------------------------------------------
int main()
{
	Queue que; /* ť����*/
	int N, M;   /* N : �ο���, M : ���� �� */
	int i;
	int getData;   /* deueue�� ������ ���� ���� */

	createQueue(&que); /* ť ���� �� �ʱ�ȭ*/

	printf("N(�ο���)�� M(���ݼ�)�� �Է��Ͻÿ� (M<=N) : ");
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
	{
		enqueue(&que, i);
	}
	while ((que.head)->next != (que.tail))
	{
		for (i = 0; i < M-1; i++)
		{
			dequeue(&que, &getData);
			enqueue(&que, getData);
		}
		dequeue(&que, &getData);
		printf("%4d", getData);
	}
	destroyQueue(&que);
	getchar(); getchar();
	return 0;
}

