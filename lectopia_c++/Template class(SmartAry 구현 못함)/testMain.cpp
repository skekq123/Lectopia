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

	cout << "�� �л��� Ű �Է� : ";
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
			cout << "�迭 �б� ����" << endl;
		}
	}
	
	cout << "���Ű : " << tot / 3.0 << endl;
	
	return 0;*/
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	SmartArray chel(3), metel(5);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;

	cout << "ö���� �� ������ ���� �Է� : ";
	for (i = 0; i < chel.getSize(); i++)
	{
		cin >> temp;
		chel.put(i, temp);
		chel.get(i, num);
		tot += num;
	}
	cout << "ö���� ���� : " << tot << endl;
	cout << "ö���� ��� : " << (double)tot / chel.getSize() << endl;

	tot = 0;
	cout << "������ �ټ� ������ ���� �Է� : ";
	for (i = 0; i < metel.getSize(); i++)
	{
		cin >> temp;
		metel.put(i, temp);
		metel.get(i, num);
		tot += num;
	}
	cout << "������ ���� : " << tot << endl;
	cout << "������ ��� : " << (double)tot / metel.getSize() << endl;

	if (chel > metel) cout << "ö���� �ְ����� ���ں��� ũ��" << endl;
	else  cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�." << endl;

	cout << "ö���� �ְ��� : " << chel.getMax() << endl << "������ �ְ��� : " << metel.getMax() << endl;

}