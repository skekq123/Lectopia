#include<iostream>
using namespace std;
#include "lectopia.h"
#include "ioacademy.h"

//using lectopia::number;
//using lectopia::print;
using namespace lectopia;
//using namespace ioacademy;
int main()
{
	cout << "main()���� ����ϴ� lectopia ���ӽ����̽��� numver = "
		<<number << endl;
	lectopia::print();

	cout << "main()���� ����ϴ� ioacademy ���ӽ����̽��� numver = "
		<< ioacademy::number << endl;
	ioacademy::print();

	return 0;
}