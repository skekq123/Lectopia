#include<stdio.h>
#include<malloc.h>
#include "graph.h"
void displayTitle(char *message);
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent);
void printWeightArray(int *weightArray, int vNum, int vCnt);
void printParent(int *parent, int vCnt);
void pathPrint(int *parent, int * weightArray, int startVNum, int endVNum);

/*----------------------------------------------------------------------------------
�Լ��� : main() 
----------------------------------------------------------------------------------*/
int main()
{
	GraphMatrix g;
	int weightArray[MAX_VERTEX];  /* ����ġ�� ���������� �����ϴ� �迭 */
	int parent[MAX_VERTEX];      /* �θ� ���� ���� �迭*/
	int i;

	initGraph(&g, "d:\\data\\graphData2.txt");/* �׷��� �ʱ�ȭ */

	displayTitle("[���� �׷����� ���� ��� ���]");
	outputGraph(&g);   /* �׷��� ���� �� ����ġ ���� ���*/        
	NEWL; NEWL;

	/* ���ͽ�Ʈ�� �˰��� ���� */

	displayTitle("[����ġ ��ȭ ���� ���]");
	dijkstra(&g, 5, weightArray, parent);  /* 5���� �ش��ϴ� ������ �������� ���ͽ�Ʈ�� �˰��� ���� */

	displayTitle("[�������� �θ�, �ڽİ��� ���]");
	printParent(parent, g.vertexCnt);  /* parent �迭 ��� */

	/* ���� ����(F-5�� ����)�� ���� �׷������� ��� ����(A~K)������ ��� �� ����ġ ��� */
	displayTitle("[F(5�� ����)�������� �� ���������� path ����ϱ�]");
	for(i=0; i<g.vertexCnt; ++i)
		pathPrint(parent, weightArray, 5, i);

	return 0;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: displayTitle() - ���޵� �޽����� ��� �� 
��������:  message - ����� �޽���
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void displayTitle(char *message)
{
	printf("\n----------------------------------------\n");
	printf(" %s\n", message);
	printf("----------------------------------------\n");
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: dijkstra() - ���޵� �׷������� ���õ� �������� ���� ������ ���������� 
			�ּ� ����ġ�� ����ϰ� �θ��ڽ� ���踦 ������
��������:  g - �׷��� ���� ����ü�� �ּ�
			vNum - ���õ� ���� ��ȣ
			weightArray - ����ġ�� ������ �迭�� �����ּ�
			parent - �������� �θ��ڽİ��踦 ������ �迭�� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent)
{
	int i; /*iterator */
	int minIndex;  /* üũ���� ���� ���� �� ���� ���� ����ġ�� �����ϰ� �ִ� ������ �ε��� ���� */
	int target; /* ����ġ ���� ����� �Ǵ� ������ �ε��� ���� */
	int check[MAX_VERTEX];  /* �˻�� ������ 1�� �̰˻� ������ 0���� ���� */
	int dist;  /* ��ȸ ����ġ ���� ����*/
	int tmpWeight;  /* minIndex�� ã�� ���� ����ġ ���� �ӽ� ���� */

	/* ���� ���� vNum �������� weightArray, parent, check �迭 �ʱ�ȭ */
	for(i=0; i<g->vertexCnt; ++i)
	{
		weightArray[i] = g->graph[vNum][i]; /* ���� ���� vNum���� ���� �� ������ �̸��� ����ġ ���� */
		parent[i] = vNum;  /* �θ� ��� ������ ��� ���� �������� �صд� */		
		check[i] = 0;  /* üũ ���θ� ��� 0(üũ�ȵ�)���� �ʱ�ȭ */
	}
	parent[vNum] = -1;  /* ���� ������ �θ�� �����Ƿ� -1(������ �� ���� �ε�����ȣ)�� �ʱ�ȭ */
	check[vNum] = 1;  /* ���� ������ vNum üũ */
	
	printWeightArray(weightArray, vNum, g->vertexCnt);  /* ���� ���� �������� ����ġ �迭 ��� */

	/* ����ġ�� ���� ���� ������ �������� ����ġ �迭�� �����ϸ� �θ� �ڽ� ���踦 ���� �ϴ� �ݺ��� */
	for(int j=0; j< g->vertexCnt-1; ++j)  /* ��� ������ ���ؼ� ����ġ�� �����ϱ� ���� �ݺ� */
	{
		minIndex = 0;  /* ����ġ�� ���� ���� ������ 0�̶�� ���� */
		tmpWeight = WEIGHT_MAX+1; 
		
		for(i=0; i<g->vertexCnt; ++i)
		{
			if(check[i]==0 && weightArray[i] < tmpWeight) /* üũ���� ���� ���� �� ���� ���� ������ �ε����� ã��*/
			{	
				minIndex = i; 
				tmpWeight = weightArray[minIndex];
			}

		}
		check[minIndex] = 1;  /* ã�Ƴ� ���� ���� ����ġ ������ üũ �� */

		for(target=0; target<g->vertexCnt; ++target)  /* Ÿ�� ������ ���Ե� ����ġ�� ���� */
		{
			/* target�� üũ�Ǿ��ų�  (minIndex, target) ������ �������� �ʴ´ٸ� ���� target�˻�� �Ѿ */
			// if(minIndex==target ||   check[target] || g->graph[minIndex][target] == WEIGHT_MAX) continue;  //<== �����ص� �ǳ� �Բ� �����ϸ� ó���ӵ��� ������

			dist = weightArray[minIndex] + g->graph[minIndex][target]; /* ��ȸ ����� ����ġ ��� */
			if(dist < weightArray[target]) /* ��ȸ ����� ����ġ�� ��������� ����ġ ���� ������ ���� */
			{
				weightArray[target] = dist; /* ��ȸ ��� ����ġ�� ���� */
				parent[target] = minIndex;  /* target�� �θ���� minIndex��� ���� */
			}
		}
		printWeightArray(weightArray, minIndex, g->vertexCnt);  /* minINdex �������� ���ŵ� ����ġ �迭 ��� */
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: printWeightArray() - weight�迭�� ��� ��
��������:  weightArray - ����ġ ���� �迭�� �����ּ�
           vNum - ���� ���� ��ȣ
           vCnt - ����� ������ ����
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printWeightArray(int *weightArray, int vNum, int vCnt)
{
	int i;
	printf("%3c : ", 'A'+vNum);
	for(i=0; i<vCnt; ++i)
		printf("%5d", weightArray[i]);

	NEWL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: printParent() - �θ�, �ڽ� ��带 ǥ���ϴ� �迭 ���
��������:  parent - �θ�, �ڽ� ��� ǥ�� �迭�� �����ּ�
			vCnt - ����� ������ ����
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printParent(int *parent, int vCnt)
{
	int i;
	printf("\n---------------------------------------------------------\n");
	printf("child :  ");
	for(i=0; i<vCnt; ++i)
		printf("%3c", i+'A');
	NEWL;
	printf("Parent : ");
	for(i=0; i<vCnt; ++i)
		if(parent[i]==-1) printf("  *");
		else printf("%3c", parent[i]+'A');
		printf("\n--------------------------------------------------------\n");
		NEWL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: pathPrint() - ���� ����->�� ���������� path �� ����ġ ���
��������:  parent - �θ�, �ڽİ��踦 ������ �迭�� �����ּ�
			weightArray - ����ġ ���� �迭�� �����ּ�
			startVNum - ���� ���� ��ȣ
			endVNum - ���� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void pathPrint(int *parent, int * weightArray, int startVNum, int endVNum)
{
	int i,j=0;
	int vNum;  /* ��η� ���õ� ���� ��ȣ */
	char path[MAX_VERTEX];
	path[j] = endVNum;
	vNum = endVNum;   /* ������ ���� ��ȣ���� �˻� */
	while(vNum!=startVNum)
	{
		vNum = path[++j] = parent[vNum];
	}

	for(i=j; i>=0; --i)  /* path �迭�� ������ ����ؾ� startVNum -> endVNum�� ��ΰ� ��� �� */
		printf("%3c -> ", 'A'+path[i]);
	printf("\b\b\b (weight: %d)\n", weightArray[endVNum]);
}

/*======================================================================================================
[ ��� ��� ]
----------------------------------------
[���� �׷����� ���� ��� ���]
----------------------------------------
A  B  C  D  E  F  G  H  I  J  K
A  0  4  1  2  3 �� �� �� �� �� ��
B  4  0 �� �� ��  4 �� �� �� �� ��
C  1 ��  0  2 �� �� �� �� �� �� ��
D  2 ��  2  0 ��  4  4 �� �� �� ��
E  3 �� �� ��  0  4 �� �� �� �� ��
F ��  4 ��  4  4  0 �� �� ��  2  4
G �� �� ��  4 �� ��  0  3  3  4 ��
H �� �� �� �� �� ��  3  0  2 �� ��
I �� �� �� �� �� ��  3  2  0  2 ��
J �� �� �� �� ��  2  4 ��  2  0  1
K �� �� �� �� ��  4 �� �� ��  1  0

�� : 1000������ ����

----------------------------------------
[����ġ ��ȭ ���� ���]
----------------------------------------
F :  1000    4 1000    4    4    0 1000 1000 1000    2    4
J :  1000    4 1000    4    4    0    6 1000    4    2    3
K :  1000    4 1000    4    4    0    6 1000    4    2    3
B :     8    4 1000    4    4    0    6 1000    4    2    3
D :     6    4    6    4    4    0    6 1000    4    2    3
E :     6    4    6    4    4    0    6 1000    4    2    3
I :     6    4    6    4    4    0    6    6    4    2    3
A :     6    4    6    4    4    0    6    6    4    2    3
C :     6    4    6    4    4    0    6    6    4    2    3
G :     6    4    6    4    4    0    6    6    4    2    3
H :     6    4    6    4    4    0    6    6    4    2    3

----------------------------------------
[�������� �θ�, �ڽİ��� ���]
----------------------------------------
child :    A  B  C  D  E  F  G  H  I  J  K
Parent :   D  F  D  F  F  *  J  I  J  F  J

----------------------------------------
[F���� �� ���������� path ���]
----------------------------------------
F ->   D ->   A  (weight: 6)
F ->   B  (weight: 4)
F ->   D ->   C  (weight: 6)
F ->   D  (weight: 4)
F ->   E  (weight: 4)
F  (weight: 0)
F ->   J ->   G  (weight: 6)
F ->   J ->   I ->   H  (weight: 6)
F ->   J ->   I  (weight: 4)
F ->   J  (weight: 2)
F ->   J ->   K  (weight: 3)

*/