#include <iostream>
#include <string.h>
#include "Profile.h"
#include "MyString.h"
using namespace std;

void userScreen(void);
char menu(void);
void proInput(Profile *, int *profileCnt);
void proDisplay(Profile *, int *profileCnt);
void proUpdate(Profile * ary, int *profileCnt);
int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile  ary[20];   // 프로필 저장 객체 배열
	int profileCnt = 0;     // 입력 받은 프로필의 개수 카운트 변수
	char ch;          // 메뉴번호 저장 변수 

	while (1)
	{
		ch = menu();        // 입력된 메뉴의 번호를 ch에 리턴받음
		if (ch == '4') { break; }  // 4번 종료하기 메뉴 입력시 무한반복문을 탈출
		switch (ch)
		{
		case '1': proInput(ary, &profileCnt); break;
		case '2': proUpdate(ary, &profileCnt); break;
		case '3': proDisplay(ary, &profileCnt); break;
		}
	}
}
void proUpdate(Profile * ary, int *profileCnt)
{
	char name[40];
	int i;
	int select;
	int count = -1;
	char tempstr[40];
	int tempage;
	double temphei;
	MyString temp;
	while (1) {
		cout << "수정할 이름을 입력 : ";
		cin >> name;
		if (strcmp(name,"끝") == 0) break;
		
		for (i = 0; i < *profileCnt; i++)
		{
			if (strcmp(name, ary[i].getName().getStr()) == 0)
			{
				cout << "수정전 profile : ";
				count = i;
				cout << count + 1 << ". " << ary[count].getName().getStr() << " : "
					<< ary[count].getAddr().getStr() << "/" << ary[count].getAge() << "세/"
					<< ary[count].getHeight() << "cm" << endl;
			}
		}
		if (count == -1) {
			cout << "*없는 회원입니다.*" << endl;
			break;
		}
		cout << "수정 항목선택 : 1.이름 / 2.주소 / 3.나이 / 4. 신장 : ";
		cin >> select;
		switch (select)
		{
		case 1:	cout << "수정할 이름을 입력하세요 : ";
				cin >> tempstr;
				temp.setStr(tempstr);
				ary[count].setName(temp);
				break;
		case 2: cout << "수정할 주소를 입력하세요 : ";
				cin >> tempstr;
				temp.setStr(tempstr);
				ary[count].setAddr(temp);
				break;
		case 3: cout << "수정할 나이를 입력하세요 : ";
				cin >> tempage;
				ary[count].setAge(tempage);
				break;
		case 4: cout << "수정할 신장을 입력하세요 : ";
				cin >> temphei;
				ary[count].setHeight(temphei);
				break;
		}
		cout << "************************" << endl;
		cout << "수정 후 profile : ";
		cout << count + 1 << ". " << ary[count].getName().getStr() << " : "
			<< ary[count].getAddr().getStr() << "/" << ary[count].getAge() << "세/"
			<< ary[count].getHeight() << "cm" << endl;

		count = -1;
	}

}
//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "프로필 입력", "프로필 수정", "프로필 출력","종료" };

	for (i = 0; i<4; i++)   // 메뉴 문자열을 출력하는 반복문
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // 유효한 번호가 아니면 다시 입력
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
void proInput(Profile *ap, int *profileCnt)
{
	char name[50];
	char addr[80];
	int age;
	double height;
	// 입력 받은 프로필의 개수를 카운트하는 변수

	while (1)
	{
		if (*profileCnt == 20) {
			cout << "20명 넘었습니다. " << endl;
			break;
		}
		cout << "이름입력 : ";
		cin >> name;
		if (strcmp(name, "끝") == 0) { break; }
		cout << "주소입력 : ";		cin >> addr;
		cout << "나이입력 : ";		cin >> age;
		cout << "키입력 : ";		cin >> height;

		ap[*profileCnt] = Profile(name, addr, age, height); // 입력 받은 데이터로 객체 초기화
		(*profileCnt)++;
	}
}
//---------------------------------------------------------------
void proDisplay(Profile *ap, int *profileCnt)
{
	int i;
	for (i = 0; i < *profileCnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName().getStr() << " : "
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "세/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}
