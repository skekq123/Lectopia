#include <iostream>
#pragma warning (disable:4996)
using namespace std;
#include <string.h>
// 기초클래스의 선언

class Player {
protected:
	char name[20]; // 이름
	int salary; // 연봉
	double winning; // 승률
public:
	Player(const char *np = "아무개", int s = 100, double w = 0);
	void exercise(); // 연습
	void play(); // 경기
	void view() const; // 데이터 출력
};

// 기초클래스의 멤버함수 정의

Player::Player(const char *np, int s, double w)
{
	strcpy(name, np);
	salary = s;
	winning = w;
}

void Player::exercise() { cout << "선수가 연습한다..." << endl; }
void Player::play() { cout << "선수가 경기한다..." << endl; }

void Player::view() const
{
	cout << "선수 이름 : " << name << endl;
	cout << "선수 연봉 : " << salary << endl;
	cout << "선수 승률 : " << winning << '%' << endl;
}

// 유도클래스의 선언(private상속)

class Manager : private Player {
public:
	Manager(const char *np = "아무개", int s = 100, double w = 0);
	void command();
	void view() const;
};

// 유도클래스 멤버함수의 정의

Manager::Manager(const char *np, int s, double w)
{
	strcpy(name, np); // 기초클래스의 멤버에 직접 접근할 수 있다.
	salary = s;
	winning = w;
}

void Manager::command()
{
	cout << "감독이 지시를 내린다..." << endl;
}

void Manager::view() const
{
	cout << "감독 이름 : " << name << endl;
	cout << "감독 연봉 : " << salary << endl;
	cout << "감독 승률 : " << winning << '%' << endl;
}

int main()
{
	Player a("홍길동", 2000, 70.0);

	a.exercise();
	a.play();
	a.view();
	Manager b("이순신", 5000, 90.0);
	b.command();
	b.view();
	// b.play(); => 에러!
	// b.exercise(); => 에러!

	Player * p = (Player *)&b; // up-casting 이 자동으로 이루어지지 않음
	p->view();
	return 0;
}