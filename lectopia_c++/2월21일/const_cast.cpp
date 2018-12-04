#include<iostream>
using namespace std;

class A
{
private:
	int num;
public:
	A(int n) { num = n; }
	void show();
};
void A::show()
{
	cout << "num = " << num << endl;
}

void sub(const A &r);
int main()
{
	A ob(10);
	sub(ob);

	return 0;
}
void sub(const A &r)
{
	const_cast<A &>(r).show(); //const 벗겨냄
	//r.show();  //const 객체는 const 함수만 호출 가능 그래서 error
}
