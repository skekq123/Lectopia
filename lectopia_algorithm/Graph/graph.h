#pragma once
#pragma warning(disable:4996)
#include "datatype.h"  //stack�̶� queue���� ������
#define MAX_VERTEX 100
#define NEWL printf("\n")

extern int check[]; // extern������ ���� �ȳ� Graph.cpp�� �ִ� �迭�� �� �� �� �ְ� ��
/*----------------------------------------------
GraphMatrix ó�� ����ü �� Ȱ�� �Լ�
-----------------------------------------------*/
typedef struct
{
	int graph[MAX_VERTEX][MAX_VERTEX]; /* ���� ��Ĺ� ǥ�� �迭 - 2���� �迭 */ //������ 10000���ε� �� ������ �������� �ϱ�
	int vertexCnt;    /* ���� ���� */
	int edgeCnt;      /* ���� ���� */
}GraphMatrix;

void initGraph(GraphMatrix *gm, char *fileName); /*���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� �׷����� �ʱ�ȭ�ϴ� �Լ� */
void outputGraph(GraphMatrix *gm); /* �׷������� ������ ������ ���踦 ���� ��� ���·� ��� �� */
void DFS_Matrix(GraphMatrix *gm); /* ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž���ϱ� ���� �Լ�(�����) - DFS_recursive()�Լ��� ȣ���Ͽ� ó��(�� �Լ� ��ü�� ������� ����) */
void DFS_recursive(GraphMatrix *gm, int vNum); /* ����Ǿ��ִ� �ϳ��� �׷�Ʈ���� ��� ������ ���ȣ�������� �湮�ϴ� �Լ� */
void visit(int vNum);   /* �湮�� ������ ó�� */
void nrDFS_Matrix(GraphMatrix *gm); /* ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž���ϱ� ���� �Լ�(�� �����) */
void BFS_Matrix(GraphMatrix *gm); /* ���� ���� ���� ��ҷ� ������ �׷����� �ʺ� �켱 Ž���ϱ� ���� �Լ�(�� �����) */
int countGraphComponents(GraphMatrix *gm); /* ���� ��Ĺ����� ǥ��� �׷��� ���� ���� ��Һ��� �������� ����ϰ� ���� ����� ������ �����ϴ� �Լ� */

										   /*---------------------------------------------
										   GraphList ó�� ����ü �� Ȱ�� �Լ�
										   ----------------------------------------------*/
typedef struct _node
{
	char vertex;
	struct _node *next;
}Node;

typedef struct
{
	Node *graph[MAX_VERTEX];  /* ���� ����Ʈ ǥ�� �迭 - Node ������ �迭 */
	int vertexCnt;    /* ���� ���� */
	int edgeCnt;      /* ���� ���� */
}GraphList;

void initGraph_List(GraphList *g, char *fileName); /* ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� �׷����� ���� ����Ʈ������ �ʱ�ȭ�ϴ� �Լ� */
void outputGraph_List(GraphList *g); /* �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ��� */
int addNode(GraphList *g, int vNum1, int vNum2); /* �� ������ ���踦 ����Ʈ�� ����� */ //�ᵵ�ǰ� �Ƚᵵ��
void destroyGraph_List(GraphList *g); /* �׷������� ���� ��� ��� ���� */

