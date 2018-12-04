#include<iostream>
using namespace std;
//#include "MyArray.h"
#include "SmartArray.h"
int main()
{
	/*cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	MyArray<double> height(3);
	
	int i;
	bool res;
	double dnum;
	double tot = 0;
	double temp;

	cout << "세 학생의 키 입력 : ";
	for (i = 0; i < 3; i++)
	{
		cin >> temp;
		height.put(i, temp);
	}
	for (i = 0; i < 3; i++)
	{
		res = height.get(i, dnum);
		if (res)
		{
			tot += dnum;
		}
		else
		{
			cout << "배열 읽기 실패" << endl;
		}
	}
	
	cout << "평균키 : " << tot / 3.0 << endl;
	
	return 0;*/
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	SmartArray chel(3), metel(5);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;

	cout << "철이의 세 과목의 점수 입력 : ";
	for (i = 0; i < chel.getSize(); i++)
	{
		cin >> temp;
		chel.put(i, temp);
		chel.get(i, num);
		tot += num;
	}
	cout << "철이의 총점 : " << tot << endl;
	cout << "철이의 평균 : " << (double)tot / chel.getSize() << endl;

	tot = 0;
	cout << "메텔의 다섯 과목의 점수 입력 : ";
	for (i = 0; i < metel.getSize(); i++)
	{
		cin >> temp;
		metel.put(i, temp);
		metel.get(i, num);
		tot += num;
	}
	cout << "메텔의 총점 : " << tot << endl;
	cout << "메텔의 평균 : " << (double)tot / metel.getSize() << endl;

	if (chel > metel) cout << "철이의 최고점은 메텔보다 크다" << endl;
	else  cout << "철이의 최고점은 메텔보다 크지 않다." << endl;

	cout << "철이의 최고점 : " << chel.getMax() << endl << "메텔의 최고점 : " << metel.getMax() << endl;

}