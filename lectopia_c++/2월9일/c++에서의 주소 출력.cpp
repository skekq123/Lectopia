#include<iostream>
using namespace std;
int main()
{
	int i;
	int intArray[5] = { 1, 3, 5, 7, 9 };
	char charArray[10] = "apple";

	cout << intArray << endl;
	cout << charArray << endl;
	cout << (void*)charArray << endl;   //char*�� (void*)�� ĳ���� �ؾ���

	for (i = 0; i < sizeof(intArray)/ sizeof(intArray[0]); i++) cout << intArray[i] << endl;

	return 0;
}