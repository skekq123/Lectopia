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
	BaseA(int n, int m) : Base(n), ba(m) {}  // Base부분 초기화
	void view() {  // view함수의 재정의
		Base::view();  // Base부분 출력
		cout << "BaseA(" << ba << ')' << endl;  // 추가부분 출력
	}
};

class BaseB : virtual public Base {
private:
	int bb;
public:
	BaseB(int n, int m) : Base(n), bb(m) {}  // Base부분 초기화
	void view() {  // view함수의 재정의
		Base::view();  // Base부분 초기화
		cout << "BaseB(" << bb << ')' << endl;  // 추가부분 출력
	}
};

class Derived : public BaseA, public BaseB {
private:
	int dd;
public:
	Derived(int n, int ma, int mb, int l)
		: Base(n), BaseA(99, ma), BaseB(88, mb), dd(l) {}
	void view() {
		BaseA::view();  // BaseA 부분 출력
		BaseB::view();  // BaseB 부분 출력
		cout << "Derived(" << dd << ')' << endl;
	}
};

int main()
{
	BaseA a(10, 20);  // Base(10), BaseA::ba=20
	BaseB b(30, 40);  // Base(30), BaseB::bb=40
	cout << "BaseA의 객체 출력..." << endl;
	a.view();
	cout << "BaseB의 객체 출력..." << endl;
	b.view();

	Derived d(77, 20, 30, 40);
	// Base(10), BaseA(10, 20), BaseB(10, 30), Derived::dd=40
	cout << "Derived의 객체 출력..." << endl;
	d.view();

	return 0;
}
