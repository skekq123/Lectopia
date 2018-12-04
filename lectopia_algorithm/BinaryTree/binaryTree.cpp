#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "binaryTree.h"

/* -------------------------------------------------------------------------------------
함수명 : initTree - 트리 관리 구조체를 초기화 하는 함수
전달인자 : tr - Tree 구조체의 주소
리턴 값 : 없음
--------------------------------------------------------------------------------------*/
void initTree(Tree *tr)
{
	tr->root = NULL;
	tr->nodeCnt = 0;
}
/* --------------------------------------------------------------------------------------
함수명 : makeNode - 새 노드를 만들어 새 노드의 주소를 리턴하는 함수
전달인자 : data - 새 노드에 저장될 값(데이터)
left - 새 노드의 left 멤버 값
right - 새 노드의 right 멤버 값
리턴 값 : 새 노드의 주소 / 메모리 할당 실패 시 NULL pointer
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
함수명 : addNode - 노드를 삽입하는 함수
전달인자 : tr - Tree 구조체의 주소
data - 새 노드에 저장될 데이터 저장 공간의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴 값 : 새 노드의 주소 / 메모리 할당 실패 시 NULL pointer
---------------------------------------------------------------------------------------*/
Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *)) // 동적할당 위에서 그냥 해버리고 반복문으로 감싼다(조건 tp != NULL)
{
	
	Node *np, *tp, *pp;
	np = makeNode(data, NULL, NULL);
	if (np == NULL) return NULL;  //할당 실패시

	if (tr->root != NULL) // 처음 만든게 아닐시
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
	else  //처음 만들때
	{
		tr->root = np;
		tr->nodeCnt++;
		return np;
	}
}
/* --------------------------------------------------------------------------------------
함수명 : inorderTraverse - 중위순회(정렬 순서로 출력)
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
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
함수명 : preorderTraverse - 전위순회
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
---------------------------------------------------------------------------------------*/
void preorderTraverse(Node *np, void(*print)(DataType *))
{
	// TODO	
}
/* --------------------------------------------------------------------------------------
함수명 : postorderTraverse - 후위순회
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
---------------------------------------------------------------------------------------*/
void postorderTraverse(Node *np, void(*print)(DataType *))
{
	// TODO	
}
/* --------------------------------------------------------------------------------------
함수명 : searchNode - data에 해당하는 노드 검색
전달인자 : tr - Tree 구조체의 주소
data - 검색할 데이터 저장 공간의 시작주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴 값 : 찾은 노드의 주소 / 못찾으면 NULL pointer
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
함수명 : deleteNode - data에 해당하는 노드 삭제
전달인자 : tr - Tree 구조체의 주소
data - 삭제할 데이터의 시작주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴 값 : 삭제한 노드의 parent 노드의 주소 / 못찾으면(삭제 실패 시) NULL pointer
---------------------------------------------------------------------------------------*/
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *tp, *pp, *resp, *temp, *tp2;
	resp = searchNode(tr, data, compareInt);
	tp = tr->root;
	pp = tp;
	
	if (resp == NULL) return NULL; // 삭제할 데이터가 있는지 검사
	else if(resp->right == NULL) // 유형1(오른쪽 자식이 없는 경우)
	{
			while (1)
			{
				if (compare(&tp->data, data) < 0)	tp = tp->right;
				else tp = tp->left;
				if (tp == resp) break;
				pp = tp;
			}
			if (tp == tr->root) tr->root = tr->root->left; //유형1은 오른쪽이 없으므로(root 삭제할때)
			if (pp->data < tp->data) pp->right = tp->left;// tp가 pp의 right일때 //삭제할게 pp의 왼쪽이냐 오른쪽이냐 
			else pp->left = tp->left;// tp가 pp의 left일때
			free(tp);
			tr->nodeCnt--;
			return pp;
			
		}
	else if (resp->right != NULL && resp->right->left == NULL) //유형2(오른쪽 자식이 있는데 그 자식이 왼쪽자식이 없는 경우)
	{
		while (1)
		{
			if (compare(&tp->data, data) < 0)	tp = tp->right;
			else tp = tp->left;
			if (tp == resp) break;
			pp = tp;
		}
		resp = resp->right;
		if (resp->right != NULL) // 오른쪽자식이 오른쪽자식이 있는경우
		{
			if (pp->data < tp->data) pp->right = resp->right;// tp가 pp의 right일때 //삭제할게 pp의 왼쪽이냐 오른쪽이냐 
			else {
				pp->left = resp->right;// tp가 pp의 left일때
				pp->left->right = resp;
			}
			pp->left->left = tp->left;
			free(tp);
			tr->nodeCnt--;
			return pp;
		}
		else if(resp->right == NULL)// 오른쪽 자식의 오른쪽자식이 없는경우
		{
			if (pp->data < tp->data) pp->right = tp->right;// tp가 pp의 right일때 //삭제할게 pp의 왼쪽이냐 오른쪽이냐 
			else pp->left = tp->right;// tp가 pp의 left일때
			pp->left->left = tp->left;
			free(tp);
			tr->nodeCnt--;
			return pp;
		}
		else if (tp == tr->root)//유형2 root를 자를때
		{
			tr->root = tp->right; 
			tp->right->left = tr->root->left;
			tr->nodeCnt--;
			return pp;
		}
	}
	else //유형3(나머지) 오른쪽 왼쪽쭉가다가 맨밑
	{
		temp = tp;
		if (resp == tr->root) // root를 삭제할 경우
		{
			tp = tp->right;
			
			while (1) //대체할거 찾기
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
		else //그 외
		{
			while (1)
			{
				if (compare(&tp->data, data) < 0)	tp = tp->right;
				else tp = tp->left;
				if (tp == resp) break;
				pp = tp;
			} //tp 는 삭제할 노드, pp는 노드의 부모노드
			tp2 = tp;
			tp2 = tp2->right;
			temp = tp2;
			while (1) //대체할거 찾기
			{
				tp2 = tp2->left;
				if (tp2->left == NULL) break;
				temp = tp2;
			} 
			
			if (tp2->right != NULL) temp->left = tp2->right; // 오른쪽에 있는거 옮기기
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

	// 유형1 : 삭제할 노드의 오른쪽 자식이 없는 경우-삭제할 노드의 왼쪽 자식이 son역할

	// 유형2 : 삭제할 노드의 오른쪽 자식의 왼쪽 자식이 없는 경우-삭제할 노드의 오른쪽 자식이 son역할

	// 유형3 : 그외 모든 경우-삭제한 노드의 오른쪽 서브트리에서 삭제할 데이터와 가장 가까운 값을 찾음

	// 삭제될 노드 대신 자식(son) 역할을 할 노드를 위치시킴
	return 0;
}
/* --------------------------------------------------------------------------------------
함수명 : destroyTree - tree 내의 모든 노드 삭제(tree 소멸)
전달인자 : tr - Tree 구조체의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
---------------------------------------------------------------------------------------*/
void destroyTree(Tree * tr, void(*print)(DataType *))
{
	postorderDelete(tr->root, print);  // 데이터 노드는 순회 하며 삭제
	tr->root = NULL;
	tr->nodeCnt = 0;
}

/* --------------------------------------------------------------------------------------
함수명 : postorderDelete - postorder(후위 순회)방식의 노드 삭제(재귀호출 함수)
전달인자 : np - 방문할 노드의 주소
print - data영역을 출력하는 보조함수의 주소
리턴 값 : 없음
---------------------------------------------------------------------------------------*/
void postorderDelete(Node *np, void(*print)(DataType *))
{

}
