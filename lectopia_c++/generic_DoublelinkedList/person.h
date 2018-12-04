#pragma once //헤더파일 중복 예방 명령어 (전처리기)
#pragma warning(disable : 4996)
#include<string.h>
#include<malloc.h>
#include<stdio.h>
typedef struct _person
{
	char *name;
	int age;
	char phoneNumber[16];
}Person; // 새형명

							  //-------------------------------------
							  //   Person 구조체 보조 함수
							  //-------------------------------------
void personMemCpy(void *p1, void *p2); 
void personClear(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);  
int personAgeCompare(void *p1, void *p2);  
int personCompare(void *p1, void *p2); 

