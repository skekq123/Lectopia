#include<iostream>
#include<cstring>
#pragma warning (disable : 4996)
using namespace std;
void prn(char(&chr)[10]);
void prn(int(&aaa)[3][4]);
int main()
{
	char str[10] = "Star";
	int ary[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//char str2[20] = "Moon";
	//prn(str2); ������ (�� 20��¥�� �޴� �Լ��� ���� 20��¥�� �ް� �� ��������) (�����迭�� ������ ��)
	prn(str);
	prn(ary);
	cout << "After : " << ary[2][3] << endl;

	return 0;
}
void prn(char(&chr)[10])
{
	cout << chr << endl;
	cout << sizeof(chr) << endl;
	strcpy(chr,"Dream");
}
void prn(int(&aaa)[3][4])
{
	cout << aaa[2][3] << endl;
	cout << sizeof(aaa) << endl;
	aaa[2][3] = 20;
}