#pragma once
#pragma warning(disable : 4996)

#include <string.h>
#include <malloc.h>
#include <stdio.h>

typedef struct _person
{
	char *name;   // ���� ���� ����
	int  age;  // ���� ���� ����
	char phoneNumber[16]; // �ڵ��� ��ȣ ���� �迭
}Person;

void personMemCpy(void *p1, void *p2); // p2�� ����Ű�� ����ü�� ��� ����� p1�� ����Ű�� ����ü�� ����
void personFree(void *p);  // ����ü ��� �� ������ ����� �����޸� �Ҵ��� �Ǿ��ִ� ��� �� �޸𸮸� ������
void personPrint(void *p);  // ����ü ����� ����  ���ٿ� ����� ��
int personNameCompare(void *p1, void *p2);  // ������ ���Ͽ� p1�� ����Ű�� ������ ũ�� 1, ������ 0, ������ 1 ����
int personAgeCompare(void *p1, void *p2);   // ���̸� ���Ͽ� p1�� ����Ű�� ���̰� ũ�� 1, ������ 0, ������ 1 ����
int personCompare(void *p1, void *p2);      // ����� ���̰� ��Ȯ�ϰ� ������ 0, ���� �ϳ��� �ٸ��� -1 ����
