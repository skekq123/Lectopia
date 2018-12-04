#include <iostream>
using namespace std;
// 기초클래스
class Base
{
public:
	void func(char ch) { cout << "Base(char) : " << ch << endl; }
	void func(int in) { cout << "Base(int) : " << in << endl; }
};
// 재정의가 없는 유도클래스
class Derived : public Base {};
// 재정의가 있는 유도클래스
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
	cout << "재정의 없는 유도클래스..." << endl;
	a.func('A');
	a.func(10);

	rDerived b;
	cout << "재정의한 유도클래스..." << endl;
	b.func('B');
	b.func(97);
	b.func(100.5);

	cout << "기본클래스의 멤버함수 호출..." << endl;
	b.Base::func('C');
	b.Base::func(98);
	return 0;
}