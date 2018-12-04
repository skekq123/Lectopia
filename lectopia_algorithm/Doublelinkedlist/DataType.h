#pragma once //헤더파일 중복 예방 명령어 (전처리기)
typedef struct _person
{
	char name[20];
	int age;
}Person; // 새형명

typedef  Person DataType;     // 노드내의 데이터 영역의 형명 재지정  (중요한부분★)

							  //-------------------------------------
							  //   Person 구조체 보조 함수
							  //-------------------------------------
int comparePersonName(DataType *p1, DataType *p2);  // Person 구조체의 name멤버로 비교하는 함수
int comparePersonAge(DataType *p1, DataType *p2);   // Person 구조체의 age멤버로 비교하는 함수
void printPerson(DataType *p);  // Person 구조체의 모든 멤버를 출력하는 함수 

//이 코드가 존재하는이유 : 쓰려는 자료형태가 구조체 형이어서 8line이 필요
