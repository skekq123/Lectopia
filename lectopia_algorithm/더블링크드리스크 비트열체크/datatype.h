#pragma once //������� �ߺ� ���� ��ɾ� (��ó����)
#define Size 10
typedef struct _person
{
	char pattern[Size];
	int num;
}Person; // ������

typedef  Person DataType;     // ��峻�� ������ ������ ���� ������  (�߿��ѺκС�)

							  //-------------------------------------
							  //   Person ����ü ���� �Լ�
							  //-------------------------------------
int comparePattern(DataType *p1, DataType *p2); 
void printPerson(DataType *p);  // Person ����ü�� ��� ����� ����ϴ� �Լ� 

								//�� �ڵ尡 �����ϴ����� : ������ �ڷ����°� ����ü ���̾ 8line�� �ʿ�

