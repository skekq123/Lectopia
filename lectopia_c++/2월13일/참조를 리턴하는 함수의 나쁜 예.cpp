#include<iostream>
using namespace std;
int &func();
int main()
{
	int num = 7;
	num = func();
	cout << num << endl;
	return 0;
}
int &func()
{
	int a = 10;
	return a;
}