#include <stdio.h> 
#include <malloc.h> 
#include "listQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - 큐 초기화 함수
Parameters		: qp - 큐 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
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
Function name	: isQueueEmpty - 큐가 비어있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns			: 완전히 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL isQueueEmpty(const Queue *qp)
{
	if (qp->head->next != qp->tail) return FALSE;
	else return TRUE;
	}
	/*--------------------------------------------------------------------------------------
	Function name	: enqueue - 큐에 데이터 하나를 저장함
	Parameters		: qp - 큐 구조체의 주소
	enqueData - 큐에 저장할 데이터
	Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
	--------------------------------------------------------------------------------------*/
	BOOL enqueue(Queue * qp, int enqueData)// tail Node 앞에
		{
			Node *temp = (Node*)calloc(1, sizeof(Node));
			Node *tp = qp->head; //tp는 head를 가리킴
			if (temp == NULL) return FALSE;

			temp->data = enqueData;
			while (tp->next != qp->tail) tp = tp -> next;

			tp->next = temp;
			temp->next = qp->tail;
			return TRUE;
		}
		/*--------------------------------------------------------------------------------------
		Function name	: dequeue - 큐에서 데이터 하나를 꺼냄
		Parameters		: qp - 큐 구조체의 주소
		dequeData - 꺼낸 데이터를 저장할 기억공간의 주소
		Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
		--------------------------------------------------------------------------------------*/
		BOOL dequeue(Queue * qp, int * dequeData) //head Node 뒤에
			{
				if (qp->head->next == qp->tail) return FALSE; //비어있음
				*dequeData = qp->head->next->data;
				qp->head->next = qp->head->next->next;
				return TRUE;
			}
			/*--------------------------------------------------------------------------------------
			Function name	: printQueue - 큐 내의 모든 데이터를 출력 함
			Parameters		: qp - 큐 구조체의 주소
			Returns			: 없음
			--------------------------------------------------------------------------------------*/
		void printQueue(const Queue * qp)
		{
			Node *tp = qp->head->next;
			if (qp->head->next == qp->tail) printf("queue가 비어있습니다. \n");
			else {
				while (tp != qp->tail)
				{
					printf("%d\n", tp->data);
					tp = tp->next;
				}
			}
		}
				/*--------------------------------------------------------------------------------------
				Function name	: destroyQueue - 큐 소멸 함수
				Parameters		: qp - 큐 구조체의 주소
				Returns			: 없음
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
