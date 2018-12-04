#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "binaryTree.h"

/* -------------------------------------------------------------------------------------
�Լ��� : initTree - Ʈ�� ���� ����ü�� �ʱ�ȭ �ϴ� �Լ�
�������� : tr - Tree ����ü�� �ּ�
���� �� : ����
--------------------------------------------------------------------------------------*/
void initTree(Tree *tr)
{
	tr->root = NULL;
	tr->nodeCnt = 0;
}
/* --------------------------------------------------------------------------------------
�Լ��� : makeNode - �� ��带 ����� �� ����� �ּҸ� �����ϴ� �Լ�
�������� : data - �� ��忡 ����� ��(������)
left - �� ����� left ��� ��
right - �� ����� right ��� ��
���� �� : �� ����� �ּ� / �޸� �Ҵ� ���� �� NULL pointer
---------------------------------------------------------------------------------------*/
Node * makeNode(DataType *data, Node * left, Node *right)
{
	Node *np;
	np = (Node *)malloc(sizeof(Node));
	if (np != NULL) {
		np->data = *data;
		np->left = left;
		np->right = right;
	}
	return np;
}

/* --------------------------------------------------------------------------------------
�Լ��� : addNode - ��带 �����ϴ� �Լ�
�������� : tr - Tree ����ü�� �ּ�
data - �� ��忡 ����� ������ ���� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : �� ����� �ּ� / �޸� �Ҵ� ���� �� NULL pointer
---------------------------------------------------------------------------------------*/
Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *)) // �����Ҵ� ������ �׳� �ع����� �ݺ������� ���Ѵ�(���� tp != NULL)
{
	
	Node *np, *tp, *pp;
	np = makeNode(data, NULL, NULL);
	if (np == NULL) return NULL;  //�Ҵ� ���н�

	if (tr->root != NULL) // ó�� ����� �ƴҽ�
	{
		tp = tr->root;
		while (1)
		{
			pp = tp;
			if (compare(&tp->data, data) < 0)
			{
				tp = tp->right;
				if (tp == NULL)
				{
					pp->right = np;
					break;
				}
			}
			else {
				tp = tp->left;
				if (tp == NULL)
				{
					pp->left = np;
					break;
				}
			}
		}
		tr->nodeCnt++;
		return np;
	}
	else  //ó�� ���鶧
	{
		tr->root = np;
		tr->nodeCnt++;
		return np;
	}
}
/* --------------------------------------------------------------------------------------
�Լ��� : inorderTraverse - ������ȸ(���� ������ ���)
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void inorderTraverse(Node *np, void(*print)(DataType *))
{
     if (np != NULL) {
         inorderTraverse(np->left, print);
         print(&np->data);
         inorderTraverse(np->right, print);
     }
}

/* --------------------------------------------------------------------------------------
�Լ��� : preorderTraverse - ������ȸ
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void preorderTraverse(Node *np, void(*print)(DataType *))
{
	// TODO	
}
/* --------------------------------------------------------------------------------------
�Լ��� : postorderTraverse - ������ȸ
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void postorderTraverse(Node *np, void(*print)(DataType *))
{
	// TODO	
}
/* --------------------------------------------------------------------------------------
�Լ��� : searchNode - data�� �ش��ϴ� ��� �˻�
�������� : tr - Tree ����ü�� �ּ�
data - �˻��� ������ ���� ������ �����ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : ã�� ����� �ּ� / ��ã���� NULL pointer
---------------------------------------------------------------------------------------*/
Node * searchNode(Tree *tr, DataType  *data, int(*compare)(DataType *, DataType *))
{
	Node *tp;
	tp = tr->root;
	while (tp != NULL) {
		if (compare(&tp->data, data) == 0)	return tp;
		else if (compare(&tp->data, data) < 0) tp = tp->right;
		else tp = tp->left;
	}
	return NULL;
}

/* --------------------------------------------------------------------------------------
�Լ��� : deleteNode - data�� �ش��ϴ� ��� ����
�������� : tr - Tree ����ü�� �ּ�
data - ������ �������� �����ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���� �� : ������ ����� parent ����� �ּ� / ��ã����(���� ���� ��) NULL pointer
---------------------------------------------------------------------------------------*/
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *tp, *pp, *resp, *temp, *tp2;
	resp = searchNode(tr, data, compareInt);
	tp = tr->root;
	pp = tp;
	
	if (resp == NULL) return NULL; // ������ �����Ͱ� �ִ��� �˻�
	else if(resp->right == NULL) // ����1(������ �ڽ��� ���� ���)
	{
			while (1)
			{
				if (compare(&tp->data, data) < 0)	tp = tp->right;
				else tp = tp->left;
				if (tp == resp) break;
				pp = tp;
			}
			if (tp == tr->root) tr->root = tr->root->left; //����1�� �������� �����Ƿ�(root �����Ҷ�)
			if (pp->data < tp->data) pp->right = tp->left;// tp�� pp�� right�϶� //�����Ұ� pp�� �����̳� �������̳� 
			else pp->left = tp->left;// tp�� pp�� left�϶�
			free(tp);
			tr->nodeCnt--;
			return pp;
			
		}
	else if (resp->right != NULL && resp->right->left == NULL) //����2(������ �ڽ��� �ִµ� �� �ڽ��� �����ڽ��� ���� ���)
	{
		while (1)
		{
			if (compare(&tp->data, data) < 0)	tp = tp->right;
			else tp = tp->left;
			if (tp == resp) break;
			pp = tp;
		}
		resp = resp->right;
		if (resp->right != NULL) // �������ڽ��� �������ڽ��� �ִ°��
		{
			if (pp->data < tp->data) pp->right = resp->right;// tp�� pp�� right�϶� //�����Ұ� pp�� �����̳� �������̳� 
			else {
				pp->left = resp->right;// tp�� pp�� left�϶�
				pp->left->right = resp;
			}
			pp->left->left = tp->left;
			free(tp);
			tr->nodeCnt--;
			return pp;
		}
		else if(resp->right == NULL)// ������ �ڽ��� �������ڽ��� ���°��
		{
			if (pp->data < tp->data) pp->right = tp->right;// tp�� pp�� right�϶� //�����Ұ� pp�� �����̳� �������̳� 
			else pp->left = tp->right;// tp�� pp�� left�϶�
			pp->left->left = tp->left;
			free(tp);
			tr->nodeCnt--;
			return pp;
		}
		else if (tp == tr->root)//����2 root�� �ڸ���
		{
			tr->root = tp->right; 
			tp->right->left = tr->root->left;
			tr->nodeCnt--;
			return pp;
		}
	}
	else //����3(������) ������ �����߰��ٰ� �ǹ�
	{
		temp = tp;
		if (resp == tr->root) // root�� ������ ���
		{
			tp = tp->right;
			
			while (1) //��ü�Ұ� ã��
			{
				tp = tp->left;
				if (tp->left == NULL) break;
				temp = tp;
			}
			if (tp->right != NULL) temp->left = tp->right;
			else temp->left = NULL;
			tp->left = tr->root->left;
			tp->right = tr->root->right;
			tr->root = tp;
			
			free(resp);
			tr->nodeCnt--;
			return pp;
		}
		else //�� ��
		{
			while (1)
			{
				if (compare(&tp->data, data) < 0)	tp = tp->right;
				else tp = tp->left;
				if (tp == resp) break;
				pp = tp;
			} //tp �� ������ ���, pp�� ����� �θ���
			tp2 = tp;
			tp2 = tp2->right;
			temp = tp2;
			while (1) //��ü�Ұ� ã��
			{
				tp2 = tp2->left;
				if (tp2->left == NULL) break;
				temp = tp2;
			} 
			
			if (tp2->right != NULL) temp->left = tp2->right; // �����ʿ� �ִ°� �ű��
			else temp->left = NULL;
			tp2->left = tp->left;
			tp2->right = tp->right;
			if (pp->data < tp->data) pp->right = tp2;
			else pp->left = tp2;
			free(tp);
			tr->nodeCnt--;
			return pp;
		}
	}

	// ����1 : ������ ����� ������ �ڽ��� ���� ���-������ ����� ���� �ڽ��� son����

	// ����2 : ������ ����� ������ �ڽ��� ���� �ڽ��� ���� ���-������ ����� ������ �ڽ��� son����

	// ����3 : �׿� ��� ���-������ ����� ������ ����Ʈ������ ������ �����Ϳ� ���� ����� ���� ã��

	// ������ ��� ��� �ڽ�(son) ������ �� ��带 ��ġ��Ŵ
	return 0;
}
/* --------------------------------------------------------------------------------------
�Լ��� : destroyTree - tree ���� ��� ��� ����(tree �Ҹ�)
�������� : tr - Tree ����ü�� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void destroyTree(Tree * tr, void(*print)(DataType *))
{
	postorderDelete(tr->root, print);  // ������ ���� ��ȸ �ϸ� ����
	tr->root = NULL;
	tr->nodeCnt = 0;
}

/* --------------------------------------------------------------------------------------
�Լ��� : postorderDelete - postorder(���� ��ȸ)����� ��� ����(���ȣ�� �Լ�)
�������� : np - �湮�� ����� �ּ�
print - data������ ����ϴ� �����Լ��� �ּ�
���� �� : ����
---------------------------------------------------------------------------------------*/
void postorderDelete(Node *np, void(*print)(DataType *))
{

}
