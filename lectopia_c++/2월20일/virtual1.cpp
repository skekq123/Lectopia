#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void show()
	{
		cout << "동물입니다.\n";
	}
};
class Cat : public Animal
{
public:
	void show() // virtual 자동추가
	{
		cout << "고양이입니다.\n";
	}
};
int main()
{
	Animal a_ob;
	Cat c_ob;
	a_ob.show();
	c_ob.show();
	Animal * a_ptr;
	a_ptr = &a_ob;
	a_ptr->show();
	a_ptr = &c_ob;
	a_ptr->show();
	return 0;
}
