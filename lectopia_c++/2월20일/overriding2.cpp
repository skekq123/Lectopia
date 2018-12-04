#include<iostream>
using namespace std;
class Base { // 기초클래스
	int va;
public:
	Base() { va = 10; }
	void view() { cout << "Base view..." << va << endl; }
};
class Derived : public Base { // 유도클래스
	int vb;
public:
	Derived() { vb = 22; }
	void view() // view함수의 재정의
	{
		cout << "Derived view..." << vb << endl;
	}
};
int main()
{
	Base a;
	Derived b;

	Base *bp = &a;
	Derived *dp = &b;
	bp->view(); // 기초클래스의 view호출
	dp->view(); // 유도클래스의 재정의된 view호출

	bp = &b; // 상향 캐스팅(up-casting) - 자동(암시적) 형변환 가능
	bp->view(); // 기초클래스의 view()호출

	dp = (Derived *)&a;// 하향 캐스팅(down-casting) - 강제(명시적) 형변환 필수
	dp->view(); // 유도클래스의 view()호출 (b멤버의 자리에는 무엇이 출력될까?)

	return 0;
}