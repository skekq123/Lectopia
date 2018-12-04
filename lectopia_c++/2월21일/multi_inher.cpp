#include<iostream>
using namespace std;

class Base {
private:
	int a;
public:
	Base(int n = 10) { a = n; }  // ������
	void view() { cout << "Base(" << a << ')' << endl; } // ��� ����Լ�
};

class BaseA : public Base {
public:
	BaseA() : Base(20) { cout << "BaseA������ ������" << endl; }
};

class BaseB : public Base {
public:
	BaseB() : Base(30) { cout << "BaseB������ ������" << endl; }
};

class Derived : public BaseA, public BaseB
{
public:
	Derived() : BaseA(), BaseB()
	{
		cout << "Derived ������ ������" << endl;
	}
};  // ���߻��

int main()
{
	Derived d;

	//d.view(); //��ȣ��
	d.BaseA::view(); //20
	d.BaseB::view(); //30 ��ȣ�� x ���� ��� �������� ��������
	return 0;
}
