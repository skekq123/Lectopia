#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

int check[MAX_VERTEX];  /* 방문된 정점은 1로 미방문 정점은 0으로 저장 */
						/*--------------------------------------------------------------------------------------
						함수명 및 기능: initGraph() - 데이터파일에서 그래프의 정점과 간선 정보를 입력 받아 '
						그래프를 인접 행렬법으로 초기화하는 함수
						전달인자:  gm - 그래프 정보 구조체의 주소
						fileName - 그래프의 정점 및 간선 정보가 저장된 데이터 파일명
						리턴값: 없음
						--------------------------------------------------------------------------------------*/
void initGraph(GraphMatrix *gm, char *fileName)
{
	char vertex[3];  /* 간선정보 입력을 위한 공간 "AB" 형태의 데이터 저장 char 배열 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* 그래프 정보 저장 파일의 파일포인터 */

	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &gm->vertexCnt, &gm->edgeCnt);  /* 정점과 간선의 개수를 읽기 */
	for (i = 0; i < gm->vertexCnt; i++)
	{
		for (j = 0; j < gm->vertexCnt; j++)
			gm->graph[i][j] = 0;
	} // 0초기화
	for (i = 0; i <gm->edgeCnt; i++)
	{
		fscanf(fp, "%s", vertex);
		for (j = 0; j < gm->vertexCnt; j++) {
			for (k = 0; k < gm->vertexCnt; k++)
			{
				if (j == vertex[0] - 'A' && k == vertex[1] - 'A') {
					gm->graph[j][k] = 1;
					gm->graph[k][j] = 1;
				}
			}
		}
	}
	// TODO vertex에는 'A''B''\0' 그래서 3개
	/*A는 0번 B는1번 이런식으로 정점번호 'A' - 'A' = 0, 'B' - 'A' = 1 이런식으로*/
	fclose(fp);
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: outputGraph() - 그래프내의 정점과 간선의 관계를 인접 행렬 형태로 출력
전달인자:  gm : 그래프 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void outputGraph(GraphMatrix *gm)
{
	int i, j;         /* iterator */

					  /* 정점명 가로방향 출력 */
	printf("   ");
	for (i = 0; i<gm->vertexCnt; ++i)
		printf("%3c", 'A' + i);

	NEWL;  // 개행 매크로 

	for (i = 0; i<gm->vertexCnt; ++i)
	{
		printf("%3c", 'A' + i);
		for (j = 0; j<gm->vertexCnt; j++)
			printf("%3d", gm->graph[i][j]);
		NEWL;
	}
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: DFS_Matrix() - 여러 개의 연결 요소로 구성된 그래프를 깊이 우선 탐색
하기 위한 함수(재귀판)
전달인자:  gm : 그래프 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void DFS_Matrix(GraphMatrix *gm)
{
	int i;
	for (i = 0; i<gm->vertexCnt; ++i)  /* 정점의 방문상태 정보를 저장할 check배열 초기화 */
		check[i] = 0;
	for (i = 0; i<gm->vertexCnt; ++i)
		if (check[i] == 0)
			DFS_recursive(gm, i);
	return;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: DFS_recursive() - 연결되어있는 하나의 그래프 내의 모든 정점을
재귀호출기법으로 방문하는 함수
전달인자:  gm : 그래프 정보 구조체의 주소
vNum : 방문하고자 하는 정점 번호
리턴값: 없음
--------------------------------------------------------------------------------------*/
void DFS_recursive(GraphMatrix *gm, int vNum) //연결되있는 하나로 재귀호출로 연결되있는거 다 방문(stack 사용 x)
{
	int start, i;

	start = vNum;
	check[start] = 1;
	printf("%3c", start + 'A');
	for (i = 0; i < gm->vertexCnt; i++) {
		if (gm->graph[start][i] == 1 && check[i] == 0)
		{
			check[i] = 1;
			DFS_recursive(gm,i);
		}

	}
	return;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: visit() - 방문된 정점을 처리하는 함수(이 함수에서는 방문된 정점을 출력 함)
전달인자: vNum : 방문하고자 하는 정점 번호
리턴값: 없음
--------------------------------------------------------------------------------------*/
void visit(int vNum)
{
	printf("%3c", 'A' + vNum);
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: nrDFS_Matrix() - 여러 개의 연결 요소로 구성된 그래프를 깊이 우선 탐색
하기 위한 함수(비 재귀판)
전달인자:  gm : 그래프 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void nrDFS_Matrix(GraphMatrix *gm)  //not recursive (비재귀판)
{
	Stack sPtr;
	int start, data, i, end=0;
	initStack(&sPtr);
	
	for (i = 0; i < gm->vertexCnt; i++) check[i] = 0; //check방 사용하기전에 0으로 초기화
	
	start = 0; //A부터 시작
	while (1) {
		push(&sPtr, start);
		check[start] = 1; 
		pop(&sPtr, &data);
		printf("%3c", data + 'A');
		while (1) {
			for (i = 0; i < gm->vertexCnt; i++) {
				if (gm->graph[start][i] == 1)  // start랑 연결되어있으면
				{
					if (check[i] == 0) {
						push(&sPtr, i);
						check[i] = 1;
					}
				}
			}
			if (isStackEmpty(&sPtr) == 1) break;
			pop(&sPtr, &data);
			printf("%3c", data + 'A');
			start = data;
			
		}
		for (i = 0; i < gm->vertexCnt; i++) {
			if (check[i] == 0) {
				start = i;
				break;
			}
		}
	for(i = 0; i < gm->vertexCnt;i++) end += check[i];

		if (end == gm->vertexCnt) break;
		else end = 0;
	}
	destroyStack(&sPtr);
	return;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: nrBFS_Matrix() - 여러 개의 연결 요소로 구성된 그래프를 너비 우선 탐색
하기 위한 함수(비 재귀판)
전달인자:  gm : 그래프 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void BFS_Matrix(GraphMatrix *gm)
{

	int i, j;
	int enData; /* pop한 데이터 저장 */
	Queue que;
	initQueue(&que, MAX_VERTEX); /* 비재귀 처리를 위해 사용될 스택 초기화 */

	for (i = 0; i<gm->vertexCnt; ++i) /* 정점의 방문상태 정보를 저장할 check배열 초기화 */
		check[i] = 0;

	for (i = 0; i<gm->vertexCnt; ++i) /* 순차적으로 정점을 방문함 */
	{
		if (check[i] == 0) /* 방문하지 않은 정점을 발견 하면 */
		{
			enqueue(&que, i);
			check[i] = 1; /* 방문상태를 1로 변경 */
			while (!isQueueEmpty(&que)) /* 스택이 비면 한 연결 요소에 대한 순회가 끝난것을 의미함 */
			{
				dequeue(&que, &enData);
				visit(enData); /* 정점 방문 */

				for (j = 0; j<gm->vertexCnt; ++j)
					if (gm->graph[enData][j] != 0 && check[j] == 0) /* (!!)pop한 정점과 연결된 j정점이 있고 j정점이 스택에 들어있지 않으면 */
					{
						enqueue(&que, j); /* j정점을 스택에 저장하고 */
						check[j] = 1; /* 방문상태를 1로 변경 */
					}
			}
		}
	}
	destroyQueue(&que);
	return;
	return;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: countGraphComponents() - 인접 행렬법으로 표기되 그래프 내의 연결 요소별로
정점들을 출력하고 연결 요소의 개수 리턴
전달인자:  gm : 그래프 정보 구조체의 주소
리턴값: 그래프내의 연결 요소의 개수
--------------------------------------------------------------------------------------*/
int countGraphComponents(GraphMatrix *gm)  //떨어져있는 그래프 몇개인지 카운트
{
	int componetsCount = 0;  /* 그래프 내의 연결 요소 카운트 변수 */

	Stack sPtr;
	int start, data, i, end = 0;
	initStack(&sPtr);

	for (i = 0; i < gm->vertexCnt; i++) check[i] = 0; //check방 사용하기전에 0으로 초기화

	start = 0; //A부터 시작
	while (1) {
		componetsCount++;
		printf("연결요소 %d :  ",componetsCount);
		push(&sPtr, start);
		check[start] = 1;
		pop(&sPtr, &data);
		printf("%3c", data + 'A');
		while (1) {
			for (i = 0; i < gm->vertexCnt; i++) {
				if (gm->graph[start][i] == 1)  // start랑 연결되어있으면
				{
					if (check[i] == 0) {
						push(&sPtr, i);
						check[i] = 1;
					}
				}
			}
			if (isStackEmpty(&sPtr) == 1) break;
			pop(&sPtr, &data);
			printf("%3c", data + 'A');
			start = data;

		}
		
		for (i = 0; i < gm->vertexCnt; i++) {
			if (check[i] == 0) {
				start = i;
				break;
			}
		}
		for (i = 0; i < gm->vertexCnt; i++) end += check[i];

		if (end == gm->vertexCnt) break;
		else {
			printf("\n");
			end = 0;
		}
	}
	destroyStack(&sPtr);

	return componetsCount;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: initGraph_L() - 데이터파일에서 그래프의 정점과 간선 정보를 입력 받아 '
그래프를 인접 리스트법으로 초기화하는 함수
전달인자:  g : 그래프 정보 구조체의 주소
fileName : 그래프의 정점 및 간선 정보가 저장된 데이터 파일명
리턴값: 없음
--------------------------------------------------------------------------------------*/
void initGraph_List(GraphList *g, char *fileName)
{
	char vertex[3];  /* 간선정보 입력을 위한 공간 "AB" 형태의 데이터 저장 char 배열 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* 그래프 정보 저장 파일의 파일포인터 */
	
	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &g->vertexCnt, &g->edgeCnt);  /* 정점과 간선의 개수를 읽기 */
	
	for (i = 0; i < g->vertexCnt; i++) {
		g->graph[i] = (Node*)malloc(sizeof(Node));
		assert(g->graph[i] != NULL);
		g->graph[i]->vertex = i + 'A';
		g->graph[i]->next = NULL;
	}

	for (i = 0; i < g->edgeCnt; i++)
	{
		fscanf(fp, "%s", vertex);
		for (j = 0; j < g->vertexCnt; j++) 
		{
			for (k = 0; k < g->vertexCnt; k++)
			{
				if (j == vertex[0] - 'A' && k == vertex[1] - 'A')
				{
					addNode(g,j, k);
				}
			}
		}
	}
	fclose(fp);
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: addNode() - 두 정점의 관계를 리스트에 등록함
전달인자:  g - 그래프 정보 구조체의 주소
vNum1 - 첫번째 정점의 번호
vNum2 - 두번째 정점이 번호
리턴값: 정점 등록이 성공하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int addNode(GraphList *g, int vNum1, int vNum2)
{
	Node *N1, *N2;
	N1 = (Node*)malloc(sizeof(Node));
	if (N1 == NULL) return FALSE;
	N2 = (Node*)malloc(sizeof(Node));
	if (N2 == NULL) return FALSE;

	N1->vertex = vNum2+'A';
	N1->next = NULL;
	N2->vertex = vNum1+'A';
	N2->next = NULL;

	if (g->graph[vNum1]->next == NULL) {
		g->graph[vNum1]->next = N1; //첫노드면
	}
	else {
		N1->next = g->graph[vNum1]->next;
		g->graph[vNum1]->next = N1;
	}
	
	if (g->graph[vNum2]->next == NULL) g->graph[vNum2]->next = N2; //첫노드면
	else {
		N2->next = g->graph[vNum2]->next;
		g->graph[vNum2]->next = N2;
	}
	return TRUE;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: outputGraph_L() - 그래프내의 정점과 간선의 관계를 인접 리스트 형태로 출력
전달인자:  g : 그래프 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void outputGraph_List(GraphList *g)
{
	int i;
	Node *temp;
	for (i = 0; i < g->vertexCnt; i++)
	{
		temp = g->graph[i];
		printf("%c :\t", g->graph[i]->vertex);
		while (1) {
			temp = temp->next;
			printf("%c", temp->vertex);
			if (temp->next == NULL) break;
			else printf(" -> ");
		}
		printf("\n");
	}

}
/*--------------------------------------------------------------------------------------
함수명 및 기능: destroyGraph_L() - 그래프내의 정점 노드 모두 삭제
전달인자:  g : 그래프 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void destroyGraph_List(GraphList *g)
{
	int i;
	Node *temp, *remove;
	for (i = 0; i < g->vertexCnt; i++)
	{
		temp = g->graph[i];
		while (1)
		{
			remove = temp;
			temp = temp->next;
			if (temp == NULL) break;
			free(remove);
		}
		g->graph[i] = NULL;
	}
}