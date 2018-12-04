#pragma once
#include "datatype.h"
typedef struct _node Node;
struct _node
{
	DataType data;   // ������ ���� ���
	Node *left;      // ���� �ڽ� ��带 ����Ű�� ������ ���
	Node *right;     // ������ �ڽ� ��带 ����Ű�� ������ ���
};

typedef struct _tree
{
	Node *root;   // Ʈ���� head node�� ����Ű�� ������ ���
	int nodeCnt;  // �� ����� ����
}Tree; // tree ���� ����ü

void initTree(Tree *tr);              // Ʈ�� ���� ����ü�� �ʱ�ȭ �ϴ� �Լ�
Node * makeNode(DataType *data, Node *, Node *);   // ����带 ����� ������� �ּҸ� �����ϴ� �Լ�
Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *));    // ��带 �����ϴ� �Լ�
void inorderTraverse(Node *np, void(*print)(DataType *));    // ������ȸ(���� ������ ���)
void preorderTraverse(Node *np, void(*print)(DataType *));       // ������ȸ
void postorderTraverse(Node *np, void(*print)(DataType *));    // ������ȸ
Node * searchNode(Tree *tr, DataType  *data, int(*compare)(DataType *, DataType *));   // data�� �ش��ϴ� ��� �˻� / ã�� ����� �ּ� ����, ��ã���� NULL ����
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *));  // data�� �ش��ϴ� ��� ���� / ������ ����� parent�� �ּ� ����
void destroyTree(Tree * tr, void(*print)(DataType *));    // tree���� ��� ��� ����(tree �Ҹ�)
void postorderDelete(Node *np, void(*print)(DataType *)); // postorder(���� ��ȸ)����� ��� ���� ���ȣ�� �Լ�
