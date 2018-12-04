#include<iostream>
using namespace std;
class BaseClass
{
public:
	BaseClass() { cout << "[BaseClass] 持失切\n\n"; }
	virtual ~BaseClass() { cout << "[BaseClass] 社瑚切\n\n"; }
};
class DerivedClass : public BaseClass
{
public:
	DerivedClass() { cout << "[DerivedClass] 持失切\n\n"; }
	~DerivedClass() { cout << "[DerivedClass] 社瑚切\n\n"; }
};
int main()
{
	BaseClass *base = new DerivedClass;
	DerivedClass ob;
	delete base;
	return 0;
}