#include<iostream>
using namespace std;
void my_flush();
int main()
{
	int intNumber;
	double doubleNumber;
	char ch;
	char str[100];

	cout << "정수값 입력 : ";
	cin >> intNumber;

	cout << "실수값 입력 : ";
	cin >> doubleNumber;

	cout << "문자입력 : ";
	cin >> ch;

	cout << "문자열입력 : ";
	cin >> str;

	cout << "intNumber = " << intNumber << endl;
	cout << "doublenumber = " << doubleNumber << endl;
	cout << "ch = " << ch << endl;
	cout << "str = " << str << endl;

	my_flush();
	
	cout << "중간에 여백있는 문자열을 입력하세요 : ";

	cin.getline(str, sizeof(str));
	cout << "입력 받은 문자열 : " << str << endl;

	cout << "여백문자를 입력하세요(space, tab, enter : )";
	ch = cin.get();
	cout << "입력한 여백문자의 아스키코드 값 : " << (int)ch << endl;
	return 0;
}
void my_flush()
{
	while (cin.get() != '\n');
}