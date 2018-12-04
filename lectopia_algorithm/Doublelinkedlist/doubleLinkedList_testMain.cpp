#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "doublelinkedlist.h"

int menu(char **mList, size_t menuCnt);
void dataFileLoad(LinkedList *lp); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
void dataFileSave(LinkedList *lp); // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
void mInput(LinkedList *lp);       // �Է¸޴� ó�� �Լ�
void mSearch(LinkedList *lp);      // ���ϰ˻��޴� ó�� �Լ�
void mDupSearch(LinkedList *lp);   // ���߰˻��޴� ó�� �Լ�
void mDelete(LinkedList *lp);      // �����޴� ó�� �Լ�
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
	dataFileLoad(&list); // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
	while (1)
	{
		menuNum = menu(menuList, menuCnt); //�޴�ȭ���� ���� �޴���ȣ�� �Է� ����
		if (menuNum == menuCnt) { break; }
		switch (menuNum)
		{
		case 1: mInput(&list); break;               // �Է¸޴� ����
		case 2: display(&list, printPerson); break; // ��¸޴� ����
		case 3: mSearch(&list); break;              // ���ϰ˻��޴� ����
		case 4: mDupSearch(&list); break;           // ���߰˻��޴� ����
		case 5: mDelete(&list); break;              // �����޴� ����
		case 6: sortList(&list, comparePersonName); break; // ����� ���ĸ޴� ����
		case 7: sortList(&list, comparePersonAge); break;  // ���̼� ���ĸ޴� ����
		}
	}
	//dataFileSave(&list); // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
	destroy(&list);

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
	DataType inData;
	printf("\n[ �Է��ϱ� �޴� ]\n\n");
	while (1)
	{
		printf("# �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", inData.name);
		if (strcmp(inData.name, "��") == 0) // "��"�Է½� ���� (inData�� Person����ü)
			break;

		printf("# ���̸� �Է��ϼ��� : ");
		scanf("%d", &inData.age);

		//appendFromTail(lp, &inData); //tail ��� �տ� ������ �߰� 
		appendFromHead(lp, &inData); // head ��� �ڿ� ������ �߰�
	}
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : mSearch()
----------------------------------------------------------------------------------*/
void mSearch(LinkedList * lp)
{
	DataType sData; //ã�� ������
	Node *resp;

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while (1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", sData.name);
		if (strcmp(sData.name, "��") == 0) // "��"�Է½� ����
			break;
		resp = searchUnique(lp, &sData, comparePersonName); //���� : ã�� ����� �ּ�, ���� :NULL
		if (resp != NULL) //�����͸� ã������
		{
			printf("@ �����Ͱ� �����մϴ� : ");
			printPerson(&resp->data);
		}
		else //�����͸� ��ã������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : mDelete()
----------------------------------------------------------------------------------*/
void mDelete(LinkedList * lp)
{
	DataType dData;
	Node *resp; // ������ ����� �ּ� ���� ����
	printf("\n[ �����ϱ� �޴�] \n\n");
	while (1)
	{
		printf("# ������ �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", dData.name);
		if (strcmp(dData.name, "��") == 0) // "��"�Է½� ����
			break;
		resp = searchUnique(lp, &dData, comparePersonName);
		if (resp != NULL) // ã������
		{
			deleteNode(lp, resp); //�ش� ��带 ����
			printf("@ �����Ͽ����ϴ�.\n\n");
		}
		else //�����Ͱ� ������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : mDupSearch()
----------------------------------------------------------------------------------*/
void mDupSearch(LinkedList * lp)
{
	Node **searchPtr; // ã�� ����� �ּҵ��� ������ �迭�� �����ּҸ� ����ų ������
	int searchCnt;    // ã�� ����� ��
	DataType sData;
	int i;

	printf("\n[ ���� �˻��ϱ� �޴� ]\n\n");
	while (1)
	{
		printf("# ã�� �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", sData.name);
		if (strcmp(sData.name, "��") == 0) { break; } //"��"�Է½� ����
		searchPtr = searchDuplicate(lp, &searchCnt, &sData, comparePersonName);
		//searchCnt�� ���� ������ ���޾Ƽ� �ּҺ���, &sData�� �̸�

		if (searchPtr != NULL) //�����͸� ã������
		{
			printf("@ �����Ͱ� %d�� �����մϴ�.\n", searchCnt);
			for (i = 0; i<searchCnt; i++) // ã�� ���� ��ŭ ������ ����ϱ�
			{
				printf("%d. ", i);
				printPerson(&searchPtr[i]->data);
			}
			free(searchPtr);  // ã������� �ּҸ� ��� �ִ� Node *�迭 �޸� ����
		}
		else //�����͸� ��ã������
		{
			printf("@ �ش� �����Ͱ� �������� �ʽ��ϴ�.\n\n");
		}
	}
	return;
}
/*----------------------------------------------------------------------------------
�Լ��� : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp) // ������ ���ϳ��� �����͸� ����Ʈ�� ���� 
{
	FILE *fp;
	fp = fopen("C:\\data\\ListData.txt", "rt");
	assert(fp != NULL);
	DataType inData;
	char name[20];   // ���� ����

	while (fscanf(fp, "%s", name) != EOF) // ������ ���� �ƴҵ��� ���ƶ�
	{
		fscanf(fp, "%d", &inData.age); // ���̸� ����
		strcpy(inData.name, name); // ���� �̸��� inData�� ����
		appendFromTail(lp, &inData); 
	}
	fclose(fp); //�߿�
}
/*----------------------------------------------------------------------------------
�Լ��� : dataFileSave()
----------------------------------------------------------------------------------*/
void dataFileSave(LinkedList *lp) // ����Ʈ���� ��� �����͸� ���Ͽ� ���� 
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
//-------------------------------------
//   Person ����ü ���� �Լ�
//-------------------------------------
int comparePersonName(DataType *p1, DataType *p2) // Person ����ü�� name����� ���ϴ� �Լ�
{
	return (strcmp(p1->name, p2->name));  // strcmp()�Լ��� ���ϰ��� �ٷ� ����
}
int comparePersonAge(DataType *p1, DataType *p2) // Person ����ü�� age����� ���ϴ� �Լ�
{
	if (p1->age > p2->age) return 1;
	else if (p1->age == p2->age) return 0;
	else return -1;
}
void printPerson(DataType *p)  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
{
	printf(" %s : %d\n", p->name, p->age);
}