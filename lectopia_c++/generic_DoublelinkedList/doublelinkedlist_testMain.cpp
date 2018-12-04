#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "genericLinkedlist.h"
#include "person.h"

int menu(char **mList, size_t menuCnt);
void dataFileLoad(LinkedList *lp, void(*myMemCpy)(void *, void *)); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
//void dataFileSave(LinkedList *lp); // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
void mInput(LinkedList *lp);       // �Է¸޴� ó�� �Լ�
void mSearch(LinkedList *lp);      // ���ϰ˻��޴� ó�� �Լ�
void mDupSearch(LinkedList *lp);   // ���߰˻��޴� ó�� �Լ�
void mDelete(LinkedList *lp, void(*dataFree)(void *));      // �����޴� ó�� �Լ�
								   /*----------------------------------------------------------------------------------
								   �Լ��� : main()
								   ----------------------------------------------------------------------------------*/
int main()
{
	char *menuList[] = { "�Է��ϱ�","����ϱ�","���ϰ˻��ϱ�","���߰˻��ϱ�", "�����ϱ�", "����� �����ϱ�", "���̼� �����ϱ�","��  ��" };
	// ������ *�� �̷���� �迭
	int menuNum;    //�޴���ȣ ���� ����
	int menuCnt;    //�޴����� ���� ����
	LinkedList list;  //����Ʈ���� ����ü ������(head,cur,tail,length) ���� �����Ⱚ�� �������

	menuCnt = sizeof(menuList) / sizeof(menuList[0]); //8��

	create(&list);      // ����ִ� ����Ʈ ���� �� �ʱ�ȭ
	dataFileLoad(&list, personMemCpy); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
	while (1)
	{
		menuNum = menu(menuList, menuCnt); //�޴�ȭ���� ���� �޴���ȣ�� �Է� ����
		if (menuNum == menuCnt) { break; }
		switch (menuNum)
		{
		case 1: mInput(&list); break;               // �Է¸޴� ����
		case 2: display(&list, personPrint); break; // ��¸޴� ����
		case 3: mSearch(&list); break;              // ���ϰ˻��޴� ����
		case 4: mDupSearch(&list); break;           // ���߰˻��޴� ����
		case 5: mDelete(&list, personClear); break;              // �����޴� ����
		case 6: sortList(&list, sizeof(Person) , personNameCompare, personMemCpy, personClear); break; // ����� ���ĸ޴� ����
		case 7: sortList(&list, sizeof(Person), personAgeCompare, personMemCpy, personClear); break;  // ���̼� ���ĸ޴� ����
		}
	}
	//dataFileSave(&list); // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
	destroy(&list, personClear);

	return 0;
}
/*----------------------------------------------------------------------------------
�Լ��� : menu()
----------------------------------------------------------------------------------*/
int menu(char **mList, size_t menuCnt)
{
	size_t menuNum = 0;  // �������� �ʴ� �޴� ��ȣ ���� 
	size_t i;

	printf("\n\n");
	for (i = 0; i<menuCnt; i++)  // �޴� ���
	{
		printf("%d. %s\n", i + 1, mList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt) // �޴���ȣ�� ��ȿ���� ���� ���� �ݺ�
	{
		printf("# �޴� ���� : ");
		scanf("%d", &menuNum);  // �޴� ��ȣ �Է�
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
�Լ��� : mInput()
----------------------------------------------------------------------------------*/
void mInput(LinkedList *lp)
{
	Person *inData = (Person*)calloc(1, sizeof(Person));
	assert(inData != NULL);
	printf("\n[ �Է��ϱ� �޴� ]\n\n");
	while (1)
	{
		printf("# �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", inData->name);
		if (strcmp(inData->name, "��") == 0) // "��"�Է½� ���� (inData�� Person����ü)
			break;

		printf("# ���̸� �Է��ϼ��� : ");
		scanf("%d", inData->age); //����

		printf("# �ڵ��� ��ȣ�� �Է��ϼ��� : ");
		scanf("%s", inData->phoneNumber);

		
		appendFromHead(lp, &inData, sizeof(Person), personMemCpy);
	}
	personClear(inData);
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : mSearch()
----------------------------------------------------------------------------------*/
void mSearch(LinkedList * lp)
{
	Person *sData = (Person*)calloc(1, sizeof(Person)); //ã�� ������
	assert(sData != NULL);
	Node *resp;

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while (1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", sData->name);
		if (strcmp(sData->name, "��") == 0) // "��"�Է½� ����
			break;
		resp = linearSearchUnique(lp, sData->name, personNameCompare); //���� : ã�� ����� �ּ�, ���� :NULL
		if (resp != NULL) //�����͸� ã������
		{
			printf("@ �����Ͱ� �����մϴ� : ");
			personPrint(&resp);
		}
		else //�����͸� ��ã������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}
	personClear(sData);
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : mDelete()
----------------------------------------------------------------------------------*/
void mDelete(LinkedList * lp, void(*dataFree)(void *))
{
	Person *dData = (Person*)calloc(1, sizeof(Person));
	assert(dData != NULL);
	Node *resp; // ������ ����� �ּ� ���� ����
	printf("\n[ �����ϱ� �޴�] \n\n");
	while (1)
	{
		printf("# ������ �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", dData->name);
		if (strcmp(dData->name, "��") == 0) // "��"�Է½� ����
			break;
		resp = linearSearchUnique(lp, dData, personNameCompare);
		if (resp != NULL) // ã������
		{
			deleteNode(lp, resp, dataFree); //�ش� ��带 ����
			printf("@ �����Ͽ����ϴ�.\n\n");
		}
		else //�����Ͱ� ������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}
	personClear(dData);
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : mDupSearch()
----------------------------------------------------------------------------------*/
void mDupSearch(LinkedList * lp)
{
	Node **searchPtr; // ã�� ����� �ּҵ��� ������ �迭�� �����ּҸ� ����ų ������
	int searchCnt = 0;    // ã�� ����� ��
	Person *sData = (Person*)calloc(1, sizeof(Person));
	assert(sData != NULL);
	int i;

	printf("\n[ ���� �˻��ϱ� �޴� ]\n\n");
	while (1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", sData->name);
		if (strcmp(sData->name, "��") == 0) { break; } //"��"�Է½� ����
		searchPtr = linearSearchDuplicate(lp, sData, searchCnt, personNameCompare);
		//searchCnt�� ���� ������ ���޾Ƽ� �ּҺ���, &sData�� �̸�

		if (searchPtr != NULL) //�����͸� ã������
		{
			printf("@ �����Ͱ� %d�� �����մϴ�.\n", searchCnt);
			for (i = 0; i<searchCnt; i++) // ã�� ���� ��ŭ ������ ����ϱ�
			{
				printf("%d. ", i);
				personPrint(&searchPtr[i]);
			}
			free(searchPtr);  // ã������� �ּҸ� ��� �ִ� Node *�迭 �޸� ����
		}
		else //�����͸� ��ã������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}
	personClear(sData);
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp, void(*myMemCpy)(void *, void *)) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
{
	FILE *fp;
	fp = fopen("C:\\data\\ListData.txt", "rt");
	assert(fp != NULL);
	Person inData;
	char name[20];   // ���� ����
	char phone[16];
	while (fscanf(fp, "%s", name) != EOF) // ������ ���� �ƴҵ��� ���ƶ�
	{
		fscanf(fp, "%d", &inData.age); // ���̸� ����
		strcpy(inData.name, name); // ���� �̸��� inData�� ����
		fscanf(fp, "%s", phone); // ���̸� ����
		strcpy(inData.phoneNumber, phone );

		appendFromTail(lp, &inData, sizeof(Person), myMemCpy);
	}
	fclose(fp); //�߿�
}
/*----------------------------------------------------------------------------------
�Լ��� : dataFileSave()
----------------------------------------------------------------------------------*/
/*void dataFileSave(LinkedList *lp) // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
{
	FILE *fp;
	fp = fopen("C:\\data\\ListData.txt", "wt");
	assert(fp != NULL);

	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		fprintf(fp, "%s %d\n", lp->cur->data.name, lp->cur->data.age);
		lp->cur = lp->cur->next;
	}
	fclose(fp);
}
*/