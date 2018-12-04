#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
#include <string.h>
class Teacher {
private:
	char name[20];
	int pay;
public:
	Teacher(const char *np = "�ƹ���", int p = 0) {
		strcpy(name, np);
		pay = p;
	}
	virtual void teach() = 0;// { cout << "����ģ��..." << endl; }
	void view() {
		cout << "�̸� : " << name << ", ������ : " << pay << endl;
	}
	virtual ~Teacher() { cout << "~Teacher ������..." << endl; }

};

class kTeacher : public Teacher {
public:
	kTeacher(const char *np = "�ƹ���", int p = 0) : Teacher(np, p) {}
	void teach() { cout << "��� ����ģ��..." << endl; }
	~kTeacher() { cout << "~kTeacher ������..." << endl; }
};

class eTeacher : public Teacher {
public:
	eTeacher(const char *np = "�ƹ���", int p = 0) : Teacher(np, p) {}
	void teach() { cout << "��� ����ģ��..." << endl; }
	~eTeacher() { cout << "~eTeacher ������..." << endl; }
};

class mTeacher : public Teacher {
public:
	mTeacher(const char *np = "�ƹ���", int p = 0) : Teacher(np, p) {}
	void teach() { cout << "������ ����ģ��..." << endl; }
	~mTeacher() { cout << "~mTeacher ������..." << endl; }
};

int main()
{
	//Teacher tob;  //�Ұ�
	Teacher *cheoli[2];
	cheoli[0] = new kTeacher("ȫ�浿", 70);
	cheoli[1] = new mTeacher("�̼���", 80);

	Teacher *metel[3];
	metel[0] = new kTeacher("�Ż��Ӵ�", 200);
	metel[1] = new eTeacher("�Ӳ���", 50);
	metel[2] = new mTeacher("������", 90);

	int i;
	cout << "ö���� ������..." << endl;
	for (i = 0; i<2; i++) {
		cheoli[i]->view();
		cheoli[i]->teach();
	}
	//cout << "������ ������..." << endl;
	//for(i=0; i<3; i++){
	//	metel[i]->view();
	//	metel[i]->teach();
	//}
	for (i = 0; i<2; i++) {
		delete cheoli[i];
	}
	return 0;
}