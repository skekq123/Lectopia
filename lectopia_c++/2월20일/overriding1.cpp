#include <iostream>
using namespace std;
// ����Ŭ����
class Base
{
public:
	void func(char ch) { cout << "Base(char) : " << ch << endl; }
	void func(int in) { cout << "Base(int) : " << in << endl; }
};
// �����ǰ� ���� ����Ŭ����
class Derived : public Base {};
// �����ǰ� �ִ� ����Ŭ����
class rDerived : public Base
{
public:
	void func(char ch)
	{
		cout << "rDerived(char) : " << ch << endl;
	}
};

int main()
{
	Derived a;
	cout << "������ ���� ����Ŭ����..." << endl;
	a.func('A');
	a.func(10);

	rDerived b;
	cout << "�������� ����Ŭ����..." << endl;
	b.func('B');
	b.func(97);
	b.func(100.5);

	cout << "�⺻Ŭ������ ����Լ� ȣ��..." << endl;
	b.Base::func('C');
	b.Base::func(98);
	return 0;
}