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
	cout << "main()에서 출력하는 lectopia 네임스페이스의 numver = "
		<<number << endl;
	lectopia::print();

	cout << "main()에서 출력하는 ioacademy 네임스페이스의 numver = "
		<< ioacademy::number << endl;
	ioacademy::print();

	return 0;
}