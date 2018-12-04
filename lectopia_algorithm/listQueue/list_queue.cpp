#include <stdio.h> 
#include <malloc.h> 
#include "listQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ť �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
--------------------------------------------------------------------------------------*/
BOOL createQueue(Queue * qp)
{
	if (qp == NULL) return FALSE;
	qp->head = (Node*)calloc(1,sizeof(Node));
	if (qp->head == NULL) return FALSE;
	qp->tail = (Node*)calloc(1, sizeof(Node));
	if (qp->tail == NULL) return FALSE;
	else{
	qp->head->next = qp->tail;
	qp->tail->next = qp->tail;
	return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - ť�� ����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueEmpty(const Queue *qp)
{
	if (qp->head->next != qp->tail) return FALSE;
	else return TRUE;
	}
	/*--------------------------------------------------------------------------------------
	Function name	: enqueue - ť�� ������ �ϳ��� ������
	Parameters		: qp - ť ����ü�� �ּ�
	enqueData - ť�� ������ ������
	Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
	--------------------------------------------------------------------------------------*/
	BOOL enqueue(Queue * qp, int enqueData)// tail Node �տ�
		{
			Node *temp = (Node*)calloc(1, sizeof(Node));
			Node *tp = qp->head; //tp�� head�� ����Ŵ
			if (temp == NULL) return FALSE;

			temp->data = enqueData;
			while (tp->next != qp->tail) tp = tp -> next;

			tp->next = temp;
			temp->next = qp->tail;
			return TRUE;
		}
		/*--------------------------------------------------------------------------------------
		Function name	: dequeue - ť���� ������ �ϳ��� ����
		Parameters		: qp - ť ����ü�� �ּ�
		dequeData - ���� �����͸� ������ �������� �ּ�
		Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
		--------------------------------------------------------------------------------------*/
		BOOL dequeue(Queue * qp, int * dequeData) //head Node �ڿ�
			{
				if (qp->head->next == qp->tail) return FALSE; //�������
				*dequeData = qp->head->next->data;
				qp->head->next = qp->head->next->next;
				return TRUE;
			}
			/*--------------------------------------------------------------------------------------
			Function name	: printQueue - ť ���� ��� �����͸� ��� ��
			Parameters		: qp - ť ����ü�� �ּ�
			Returns			: ����
			--------------------------------------------------------------------------------------*/
		void printQueue(const Queue * qp)
		{
			Node *tp = qp->head->next;
			if (qp->head->next == qp->tail) printf("queue�� ����ֽ��ϴ�. \n");
			else {
				while (tp != qp->tail)
				{
					printf("%d\n", tp->data);
					tp = tp->next;
				}
			}
		}
				/*--------------------------------------------------------------------------------------
				Function name	: destroyQueue - ť �Ҹ� �Լ�
				Parameters		: qp - ť ����ü�� �ּ�
				Returns			: ����
				--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	Node *tp;
	if (qp == NULL) return;
							tp = qp->head->next;
							
							while (tp != qp->tail)
							{
								qp->head->next = qp->head->next->next;
								free(tp);
								tp = qp->head->next;
							}
						free(qp->head);
						free(qp->tail);
						qp->head = NULL;
						qp->tail = NULL;
					}
