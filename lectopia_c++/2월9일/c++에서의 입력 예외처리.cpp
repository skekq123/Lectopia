#include<iostream>
using namespace std;
void my_flush();
int main()
{
	int num;
	cin >> num;
	while (cin.fail())
	{
		my_flush();
		cin >> num;
	}
	cout << "num = " << num << endl;
	return 0;
}
void my_flush()
{
	cin.clear();
	while (cin.get() != '\n');
}