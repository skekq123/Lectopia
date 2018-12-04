#pragma once
#pragma warning (disable : 4996)
#define MAX_VERTEX 100
#define WEIGHT_MAX 1000 /* ���� ���Ǵ� ����ġ���� ������ ���� å��, INT_MAX(���� ������������)�� ����ϸ� �� ��*/
#define NEWL printf("\n")

/*----------------------------------------------
GraphMatrix ó�� ����ü �� Ȱ�� �Լ�
-----------------------------------------------*/
typedef struct
{
	int graph[MAX_VERTEX][MAX_VERTEX]; /* ���� ��Ĺ� ǥ�� �迭 - 2���� �迭 */  //����ġ�� ����
	int vertexCnt;    /* ���� ���� */
	int edgeCnt;      /* ���� ���� */
}GraphMatrix;

void initGraph(GraphMatrix *gm, char *fileName); /*���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� �׷����� �ʱ�ȭ�ϴ� �Լ� */
void outputGraph(GraphMatrix *gm); /* �׷������� ������ ������ ���踦 ���� ��� ���·� ��� �� */


