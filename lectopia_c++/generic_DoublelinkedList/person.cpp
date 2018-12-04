#include<stdio.h>
#pragma warning (disable : 4996)
#include<malloc.h>
#include<string.h>
#include"person.h"
#include"genericLinkedlist.h"

void personMemCpy(void *p1, void *p2)
{
	personClear(p1);  // name멤버의 메모리 해제
	if (((Person *)p2)->name != NULL)
	{
		((Person *)p1)->name = (char *)calloc(strlen(((Person *)p2)->name) + 1, sizeof(char));
		strcpy(((Person *)p1)->name, ((Person *)p2)->name);
	}


	((Person *)p1)->age = ((Person *)p2)->age;

	strcpy(((Person *)p1)->phoneNumber, ((Person *)p2)->phoneNumber);
	return;
}
void personClear(void *p)
{
	if (((Person*)p)->name == NULL)  free(((Person*)p)->name);

	((Person*)p)->name = NULL; //메모리 해제 후 NULL 가리키게함
}
void personPrint(void *p)
{
	printf("성명 : %s / 나이 : %d / 폰번호 : %s\n", ((Person*)p)->name, ((Person*)p)->age, ((Person*)p)->phoneNumber);
}
int personNameCompare(void *p1, void *p2)
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}
int personAgeCompare(void *p1, void *p2)
{
	if (((Person*)p1)->age > ((Person*)p1)->age) return 1;
	else if (((Person*)p1)->age == ((Person*)p1)->age) return 0;
	else return -1;
}
int personCompare(void *p1, void *p2)
{
	if (personNameCompare(p1, p2) == 0 && personAgeCompare(p1, p2) == 0) return 0;
	else return -1;
	
}
