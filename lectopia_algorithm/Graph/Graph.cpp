#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

int check[MAX_VERTEX];  /* �湮�� ������ 1�� �̹湮 ������ 0���� ���� */
						/*--------------------------------------------------------------------------------------
						�Լ��� �� ���: initGraph() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
						�׷����� ���� ��Ĺ����� �ʱ�ȭ�ϴ� �Լ�
						��������:  gm - �׷��� ���� ����ü�� �ּ�
						fileName - �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
						���ϰ�: ����
						--------------------------------------------------------------------------------------*/
void initGraph(GraphMatrix *gm, char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */

	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &gm->vertexCnt, &gm->edgeCnt);  /* ������ ������ ������ �б� */
	for (i = 0; i < gm->vertexCnt; i++)
	{
		for (j = 0; j < gm->vertexCnt; j++)
			gm->graph[i][j] = 0;
	} // 0�ʱ�ȭ
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
	// TODO vertex���� 'A''B''\0' �׷��� 3��
	/*A�� 0�� B��1�� �̷������� ������ȣ 'A' - 'A' = 0, 'B' - 'A' = 1 �̷�������*/
	fclose(fp);
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph() - �׷������� ������ ������ ���踦 ���� ��� ���·� ���
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void outputGraph(GraphMatrix *gm)
{
	int i, j;         /* iterator */

					  /* ������ ���ι��� ��� */
	printf("   ");
	for (i = 0; i<gm->vertexCnt; ++i)
		printf("%3c", 'A' + i);

	NEWL;  // ���� ��ũ�� 

	for (i = 0; i<gm->vertexCnt; ++i)
	{
		printf("%3c", 'A' + i);
		for (j = 0; j<gm->vertexCnt; j++)
			printf("%3d", gm->graph[i][j]);
		NEWL;
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: DFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž��
�ϱ� ���� �Լ�(�����)
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void DFS_Matrix(GraphMatrix *gm)
{
	int i;
	for (i = 0; i<gm->vertexCnt; ++i)  /* ������ �湮���� ������ ������ check�迭 �ʱ�ȭ */
		check[i] = 0;
	for (i = 0; i<gm->vertexCnt; ++i)
		if (check[i] == 0)
			DFS_recursive(gm, i);
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: DFS_recursive() - ����Ǿ��ִ� �ϳ��� �׷��� ���� ��� ������
���ȣ�������� �湮�ϴ� �Լ�
��������:  gm : �׷��� ���� ����ü�� �ּ�
vNum : �湮�ϰ��� �ϴ� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void DFS_recursive(GraphMatrix *gm, int vNum) //������ִ� �ϳ��� ���ȣ��� ������ִ°� �� �湮(stack ��� x)
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
�Լ��� �� ���: visit() - �湮�� ������ ó���ϴ� �Լ�(�� �Լ������� �湮�� ������ ��� ��)
��������: vNum : �湮�ϰ��� �ϴ� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void visit(int vNum)
{
	printf("%3c", 'A' + vNum);
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: nrDFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž��
�ϱ� ���� �Լ�(�� �����)
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void nrDFS_Matrix(GraphMatrix *gm)  //not recursive (�������)
{
	Stack sPtr;
	int start, data, i, end=0;
	initStack(&sPtr);
	
	for (i = 0; i < gm->vertexCnt; i++) check[i] = 0; //check�� ����ϱ����� 0���� �ʱ�ȭ
	
	start = 0; //A���� ����
	while (1) {
		push(&sPtr, start);
		check[start] = 1; 
		pop(&sPtr, &data);
		printf("%3c", data + 'A');
		while (1) {
			for (i = 0; i < gm->vertexCnt; i++) {
				if (gm->graph[start][i] == 1)  // start�� ����Ǿ�������
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
�Լ��� �� ���: nrBFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� �ʺ� �켱 Ž��
�ϱ� ���� �Լ�(�� �����)
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void BFS_Matrix(GraphMatrix *gm)
{

	int i, j;
	int enData; /* pop�� ������ ���� */
	Queue que;
	initQueue(&que, MAX_VERTEX); /* ����� ó���� ���� ���� ���� �ʱ�ȭ */

	for (i = 0; i<gm->vertexCnt; ++i) /* ������ �湮���� ������ ������ check�迭 �ʱ�ȭ */
		check[i] = 0;

	for (i = 0; i<gm->vertexCnt; ++i) /* ���������� ������ �湮�� */
	{
		if (check[i] == 0) /* �湮���� ���� ������ �߰� �ϸ� */
		{
			enqueue(&que, i);
			check[i] = 1; /* �湮���¸� 1�� ���� */
			while (!isQueueEmpty(&que)) /* ������ ��� �� ���� ��ҿ� ���� ��ȸ�� �������� �ǹ��� */
			{
				dequeue(&que, &enData);
				visit(enData); /* ���� �湮 */

				for (j = 0; j<gm->vertexCnt; ++j)
					if (gm->graph[enData][j] != 0 && check[j] == 0) /* (!!)pop�� ������ ����� j������ �ְ� j������ ���ÿ� ������� ������ */
					{
						enqueue(&que, j); /* j������ ���ÿ� �����ϰ� */
						check[j] = 1; /* �湮���¸� 1�� ���� */
					}
			}
		}
	}
	destroyQueue(&que);
	return;
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: countGraphComponents() - ���� ��Ĺ����� ǥ��� �׷��� ���� ���� ��Һ���
�������� ����ϰ� ���� ����� ���� ����
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: �׷������� ���� ����� ����
--------------------------------------------------------------------------------------*/
int countGraphComponents(GraphMatrix *gm)  //�������ִ� �׷��� ����� ī��Ʈ
{
	int componetsCount = 0;  /* �׷��� ���� ���� ��� ī��Ʈ ���� */

	Stack sPtr;
	int start, data, i, end = 0;
	initStack(&sPtr);

	for (i = 0; i < gm->vertexCnt; i++) check[i] = 0; //check�� ����ϱ����� 0���� �ʱ�ȭ

	start = 0; //A���� ����
	while (1) {
		componetsCount++;
		printf("������ %d :  ",componetsCount);
		push(&sPtr, start);
		check[start] = 1;
		pop(&sPtr, &data);
		printf("%3c", data + 'A');
		while (1) {
			for (i = 0; i < gm->vertexCnt; i++) {
				if (gm->graph[start][i] == 1)  // start�� ����Ǿ�������
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
�Լ��� �� ���: initGraph_L() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
�׷����� ���� ����Ʈ������ �ʱ�ȭ�ϴ� �Լ�
��������:  g : �׷��� ���� ����ü�� �ּ�
fileName : �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initGraph_List(GraphList *g, char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */
	
	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &g->vertexCnt, &g->edgeCnt);  /* ������ ������ ������ �б� */
	
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
�Լ��� �� ���: addNode() - �� ������ ���踦 ����Ʈ�� �����
��������:  g - �׷��� ���� ����ü�� �ּ�
vNum1 - ù��° ������ ��ȣ
vNum2 - �ι�° ������ ��ȣ
���ϰ�: ���� ����� �����ϸ� TRUE ����, �����ϸ� FALSE ����
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
		g->graph[vNum1]->next = N1; //ù����
	}
	else {
		N1->next = g->graph[vNum1]->next;
		g->graph[vNum1]->next = N1;
	}
	
	if (g->graph[vNum2]->next == NULL) g->graph[vNum2]->next = N2; //ù����
	else {
		N2->next = g->graph[vNum2]->next;
		g->graph[vNum2]->next = N2;
	}
	return TRUE;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph_L() - �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ���
��������:  g : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
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
�Լ��� �� ���: destroyGraph_L() - �׷������� ���� ��� ��� ����
��������:  g : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
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