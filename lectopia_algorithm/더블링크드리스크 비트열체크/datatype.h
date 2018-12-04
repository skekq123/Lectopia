#pragma once //헤더파일 중복 예방 명령어 (전처리기)
#define Size 10
typedef struct _person
{
	char pattern[Size];
	int num;
}Person; // 새형명

typedef  Person DataType;     // 노드내의 데이터 영역의 형명 재지정  (중요한부분★)

							  //-------------------------------------
							  //   Person 구조체 보조 함수
							  //-------------------------------------
int comparePattern(DataType *p1, DataType *p2); 
void printPerson(DataType *p);  // Person 구조체의 모든 멤버를 출력하는 함수 

								//이 코드가 존재하는이유 : 쓰려는 자료형태가 구조체 형이어서 8line이 필요

