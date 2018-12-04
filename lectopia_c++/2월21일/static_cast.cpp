#include<iostream>
#include "static_cast.h"
using namespace std;

class Time
{
private:
	int hour;
	int min;
public:
	Time(int h = 0, int m = 0);   // ��, ���� �޴� �����ε�� ������
	Time(double t);           // �ð��� �Ǽ������� �ʱ�ȭ�ϴ� ������
	operator double() const;  // ����ȯ�Լ�
	void show();              // ��� ����Լ�
};

Time::Time(int h, int m)
{
	cout << "int  ������ ȣ��..." << endl;
	hour = h;
	min = m;
}

Time::Time(double t)
{
	cout << "double ������ ȣ��..." << endl;
	hour = int(t);
	min = (int)((t - hour)*60.0);
}

Time::operator double() const
{
	cout << "����ȯ�Լ� ȣ��..." << endl;
	double temp;
	temp = hour + min / 60.0;
	return temp;
}

void Time::show()
{
	cout << this->hour << "�ð� " << this->min << "��" << endl;
}

int main()
{
	Time a;
	a = 3.5;  // ������ �Լ� ȣ��
	a.show();

	double res;
	res = 1.5 + static_cast<double>(a);  // operator double() ����ȯ ����Լ� ȣ��
	cout << res << endl;

	int num;
	char ch = 'A';
	int *ip;

	num = static_cast<int>(ch);
	cout << num << endl;

	//ip = static_cast<int*>(&ch);
	return 0;
}
