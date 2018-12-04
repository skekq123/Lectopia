#include<stdio.h>
#include<assert.h>
#include "graph.h"

/*--------------------------------------------------------------------------------------
�Լ��� �� ���: initGraph() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
�׷����� �ʱ�ȭ�ϴ� �Լ�
��������:  gm : �׷��� ���� ����ü�� �ּ�
fileName : �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initGraph(GraphMatrix *gm, char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */
	int weight;      /* ����ġ ���� ���� */

	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &gm->vertexCnt, &gm->edgeCnt);  /* ������ ������ ������ �б� */

														  /* ������ ������ ���� ���� ��� ���� �ʱ�ȭ */
	for (i = 0; i<gm->vertexCnt; ++i)
		for (j = 0; j<gm->vertexCnt; ++j)
			gm->graph[i][j] = WEIGHT_MAX;                //1000���� �� �ʱ�ȭ (����Ǿ� ���� �ʴ�,)

	/* ������ �׷��������� �ݻ���(Reflexive) ǥ�� */
	for (i = 0; i<gm->vertexCnt; ++i)   //�ڱ⿡�� �ڱⰡ�°�
		gm->graph[i][i] = 0;

	/* ������ �׷��������� ��Ī��(Symmetry) ����� �ʱ�ȭ ǥ�� */
	for (k = 0; k<gm->edgeCnt; ++k)
	{
		fscanf(fp, "%s %d\n", vertex, &weight);
		i = vertex[0] - 'A';   /* ������ �̸��� ����ȭ  'B'-'A' => 1�� �������� ��ȯ*/
		j = vertex[1] - 'A';   /* ������ �̸��� ����ȭ */
		gm->graph[i][j] = gm->graph[j][i] = weight;
	}
	fclose(fp);
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph() - �׷������� ������ ������ ���踦 ���� ��� ���·� ��� ��
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void outputGraph(GraphMatrix *gm)
{
	int i, j;         /* iterator */
	printf("   ");
	/* ������ ���ι��� ��� */
	for (i = 0; i<gm->vertexCnt; ++i)
		printf("%3c", 'A' + i);

	NEWL;

	for (i = 0; i<gm->vertexCnt; ++i)
	{
		printf("%3c", 'A' + i);
		for (j = 0; j<gm->vertexCnt; j++)
			if (gm->graph[i][j] == WEIGHT_MAX)
				printf("%3s", "��");
			else
				printf("%3d", gm->graph[i][j]);
		NEWL;
	}
	NEWL;
	printf("    �� : %d������ ����\n\n", WEIGHT_MAX);
}
