#pragma once //������� �ߺ� ���� ��ɾ� (��ó����)
typedef struct _person
{
	char name[20];
	int age;
}Person; // ������

typedef  Person DataType;     // ��峻�� ������ ������ ���� ������  (�߿��ѺκС�)

							  //-------------------------------------
							  //   Person ����ü ���� �Լ�
							  //-------------------------------------
int comparePersonName(DataType *p1, DataType *p2);  // Person ����ü�� name����� ���ϴ� �Լ�
int comparePersonAge(DataType *p1, DataType *p2);   // Person ����ü�� age����� ���ϴ� �Լ�
void printPerson(DataType *p);  // Person ����ü�� ��� ����� ����ϴ� �Լ� 

//�� �ڵ尡 �����ϴ����� : ������ �ڷ����°� ����ü ���̾ 8line�� �ʿ�
