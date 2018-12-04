#include <iostream>
#pragma warning (disable:4996)
using namespace std;
#include <string.h>
// ����Ŭ������ ����

class Player {
protected:
	char name[20]; // �̸�
	int salary; // ����
	double winning; // �·�
public:
	Player(const char *np = "�ƹ���", int s = 100, double w = 0);
	void exercise(); // ����
	void play(); // ���
	void view() const; // ������ ���
};

// ����Ŭ������ ����Լ� ����

Player::Player(const char *np, int s, double w)
{
	strcpy(name, np);
	salary = s;
	winning = w;
}

void Player::exercise() { cout << "������ �����Ѵ�..." << endl; }
void Player::play() { cout << "������ ����Ѵ�..." << endl; }

void Player::view() const
{
	cout << "���� �̸� : " << name << endl;
	cout << "���� ���� : " << salary << endl;
	cout << "���� �·� : " << winning << '%' << endl;
}

// ����Ŭ������ ����(private���)

class Manager : private Player {
public:
	Manager(const char *np = "�ƹ���", int s = 100, double w = 0);
	void command();
	void view() const;
};

// ����Ŭ���� ����Լ��� ����

Manager::Manager(const char *np, int s, double w)
{
	strcpy(name, np); // ����Ŭ������ ����� ���� ������ �� �ִ�.
	salary = s;
	winning = w;
}

void Manager::command()
{
	cout << "������ ���ø� ������..." << endl;
}

void Manager::view() const
{
	cout << "���� �̸� : " << name << endl;
	cout << "���� ���� : " << salary << endl;
	cout << "���� �·� : " << winning << '%' << endl;
}

int main()
{
	Player a("ȫ�浿", 2000, 70.0);

	a.exercise();
	a.play();
	a.view();
	Manager b("�̼���", 5000, 90.0);
	b.command();
	b.view();
	// b.play(); => ����!
	// b.exercise(); => ����!

	Player * p = (Player *)&b; // up-casting �� �ڵ����� �̷������ ����
	p->view();
	return 0;
}