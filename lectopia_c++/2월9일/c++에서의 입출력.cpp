#include<iostream>
using namespace std;
void my_flush();
int main()
{
	int intNumber;
	double doubleNumber;
	char ch;
	char str[100];

	cout << "������ �Է� : ";
	cin >> intNumber;

	cout << "�Ǽ��� �Է� : ";
	cin >> doubleNumber;

	cout << "�����Է� : ";
	cin >> ch;

	cout << "���ڿ��Է� : ";
	cin >> str;

	cout << "intNumber = " << intNumber << endl;
	cout << "doublenumber = " << doubleNumber << endl;
	cout << "ch = " << ch << endl;
	cout << "str = " << str << endl;

	my_flush();
	
	cout << "�߰��� �����ִ� ���ڿ��� �Է��ϼ��� : ";

	cin.getline(str, sizeof(str));
	cout << "�Է� ���� ���ڿ� : " << str << endl;

	cout << "���鹮�ڸ� �Է��ϼ���(space, tab, enter : )";
	ch = cin.get();
	cout << "�Է��� ���鹮���� �ƽ�Ű�ڵ� �� : " << (int)ch << endl;
	return 0;
}
void my_flush()
{
	while (cin.get() != '\n');
}