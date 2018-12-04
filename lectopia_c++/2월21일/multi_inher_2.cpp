#include <iostream>
using namespace std;
class Base {
private:
	int a;
public:
	Base(int n = 0) { a = n; }
	void view() { cout << "Base(" << a << ')' << endl; }
};

class BaseA : virtual public Base {
private:
	int ba;
public:
	BaseA(int n, int m) : Base(n), ba(m) {}  // Base�κ� �ʱ�ȭ
	void view() {  // view�Լ��� ������
		Base::view();  // Base�κ� ���
		cout << "BaseA(" << ba << ')' << endl;  // �߰��κ� ���
	}
};

class BaseB : virtual public Base {
private:
	int bb;
public:
	BaseB(int n, int m) : Base(n), bb(m) {}  // Base�κ� �ʱ�ȭ
	void view() {  // view�Լ��� ������
		Base::view();  // Base�κ� �ʱ�ȭ
		cout << "BaseB(" << bb << ')' << endl;  // �߰��κ� ���
	}
};

class Derived : public BaseA, public BaseB {
private:
	int dd;
public:
	Derived(int n, int ma, int mb, int l)
		: Base(n), BaseA(99, ma), BaseB(88, mb), dd(l) {}
	void view() {
		BaseA::view();  // BaseA �κ� ���
		BaseB::view();  // BaseB �κ� ���
		cout << "Derived(" << dd << ')' << endl;
	}
};

int main()
{
	BaseA a(10, 20);  // Base(10), BaseA::ba=20
	BaseB b(30, 40);  // Base(30), BaseB::bb=40
	cout << "BaseA�� ��ü ���..." << endl;
	a.view();
	cout << "BaseB�� ��ü ���..." << endl;
	b.view();

	Derived d(77, 20, 30, 40);
	// Base(10), BaseA(10, 20), BaseB(10, 30), Derived::dd=40
	cout << "Derived�� ��ü ���..." << endl;
	d.view();

	return 0;
}
