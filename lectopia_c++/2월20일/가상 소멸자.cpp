#include<iostream>
using namespace std;
class BaseClass
{
public:
	BaseClass() { cout << "[BaseClass] ������\n\n"; }
	virtual ~BaseClass() { cout << "[BaseClass] �Ҹ���\n\n"; }
};
class DerivedClass : public BaseClass
{
public:
	DerivedClass() { cout << "[DerivedClass] ������\n\n"; }
	~DerivedClass() { cout << "[DerivedClass] �Ҹ���\n\n"; }
};
int main()
{
	BaseClass *base = new DerivedClass;
	DerivedClass ob;
	delete base;
	return 0;
}