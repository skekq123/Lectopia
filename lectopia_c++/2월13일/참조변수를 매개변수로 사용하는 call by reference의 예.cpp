#include<iostream>
using namespace std;
//int sub(int &num);
int sub(const int &num);
int main()
{
	int res;
	res = sub(10 + 20);
	cout << res << endl;

	return 0;
}
/*int sub(int &num)
{
	return num*num;
}*/
int sub(const int &num)
{
	return num*num;
}