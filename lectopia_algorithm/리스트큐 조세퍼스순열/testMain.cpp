#include "listQueue.h"
#include <stdio.h>
//--------------------------------------------------------------------------------
//   main()
//--------------------------------------------------------------------------------
int main()
{
	Queue que; /* 큐생성*/
	int N, M;   /* N : 인원수, M : 간격 수 */
	int i;
	int getData;   /* deueue한 데이터 저장 변수 */

	createQueue(&que); /* 큐 생성 및 초기화*/

	printf("N(인원수)와 M(간격수)를 입력하시오 (M<=N) : ");
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

