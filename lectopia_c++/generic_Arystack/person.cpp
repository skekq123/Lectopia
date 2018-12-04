#include "person.h"


void personMemCpy(void *p1, void *p2)
{
	personFree(p1);  // name����� �޸� ����
	if (((Person *)p2)->name != NULL)
	{
		((Person *)p1)->name = (char *)calloc(strlen(((Person *)p2)->name) + 1, sizeof(char));
		strcpy(((Person *)p1)->name, ((Person *)p2)->name);
	}


	((Person *)p1)->age = ((Person *)p2)->age;

	strcpy(((Person *)p1)->phoneNumber, ((Person *)p2)->phoneNumber);

}


void personFree(void *p) // Person����ü�� ����� �����ִ� �ΰ� �޸� �����ϱ�
{
	if (((Person *)p)->name != NULL)
		free(((Person *)p)->name);
	((Person *)p)->name = NULL;  // �޸� ���� �� name����� NULL �����ͷ� �����س���
}

void personPrint(void *p)
{
	printf("���� : %s / ���� : %d / ����ȣ : %s\n", ((Person *)p)->name, ((Person *)p)->age, ((Person *)p)->phoneNumber);
}

int personNameCompare(void *p1, void *p2)
{
	return strcmp(((Person *)p1)->name, ((Person *)p2)->name);
}

int personAgeCompare(void *p1, void *p2)
{
	if (((Person *)p1)->age > ((Person *)p2)->age)
	{
		return 1;
	}
	else if (((Person *)p1)->age == ((Person *)p2)->age)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int personPhoneNumberCompare(void *p1, void *p2)
{
	return strcmp(((Person *)p1)->phoneNumber, ((Person *)p2)->phoneNumber);
}

int personCompare(void *p1, void *p2)
{
	int res1, res2, res3;

	res1 = personNameCompare(p1, p2);
	res2 = personAgeCompare(p1, p2);
	res3 = personPhoneNumberCompare(p1, p2);
	if (res1 == 0 && res2 == 0 && res3)
	{
		return 0;  // ��� ����� �����ϸ� 0 ����
	}
	else
	{
		return -1;  // ��� ����� ��ġ���� ������ -1 ����
	}
}
