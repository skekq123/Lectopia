#include<iostream>
using namespace std;
void square(int);
void square(double);

int main()
{
	char ch = 'A';
	short sh = 10;
	float ft = 3.4f;
	double db = 3.4;

	square(ch);
	square(sh);
	square(ft);
	square(db);

	return 0;
}
void square(int a)
{

	cout << "int형으로 호출 : " << a*a << endl;
}
void square(double a)
{

	cout << "double형으로 호출 : " << a*a << endl;
}