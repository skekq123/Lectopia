#include <iostream>
#include <string.h>
#include "Profile.h"
#include "MyString.h"
using namespace std;

void userScreen(void);
char menu(void);
void proInput(Profile *, int *profileCnt);
void proDisplay(Profile *, int *profileCnt);
void proUpdate(Profile * ary, int *profileCnt);
int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile  ary[20];   // ������ ���� ��ü �迭
	int profileCnt = 0;     // �Է� ���� �������� ���� ī��Ʈ ����
	char ch;          // �޴���ȣ ���� ���� 

	while (1)
	{
		ch = menu();        // �Էµ� �޴��� ��ȣ�� ch�� ���Ϲ���
		if (ch == '4') { break; }  // 4�� �����ϱ� �޴� �Է½� ���ѹݺ����� Ż��
		switch (ch)
		{
		case '1': proInput(ary, &profileCnt); break;
		case '2': proUpdate(ary, &profileCnt); break;
		case '3': proDisplay(ary, &profileCnt); break;
		}
	}
}
void proUpdate(Profile * ary, int *profileCnt)
{
	char name[40];
	int i;
	int select;
	int count = -1;
	char tempstr[40];
	int tempage;
	double temphei;
	MyString temp;
	while (1) {
		cout << "������ �̸��� �Է� : ";
		cin >> name;
		if (strcmp(name,"��") == 0) break;
		
		for (i = 0; i < *profileCnt; i++)
		{
			if (strcmp(name, ary[i].getName().getStr()) == 0)
			{
				cout << "������ profile : ";
				count = i;
				cout << count + 1 << ". " << ary[count].getName().getStr() << " : "
					<< ary[count].getAddr().getStr() << "/" << ary[count].getAge() << "��/"
					<< ary[count].getHeight() << "cm" << endl;
			}
		}
		if (count == -1) {
			cout << "*���� ȸ���Դϴ�.*" << endl;
			break;
		}
		cout << "���� �׸��� : 1.�̸� / 2.�ּ� / 3.���� / 4. ���� : ";
		cin >> select;
		switch (select)
		{
		case 1:	cout << "������ �̸��� �Է��ϼ��� : ";
				cin >> tempstr;
				temp.setStr(tempstr);
				ary[count].setName(temp);
				break;
		case 2: cout << "������ �ּҸ� �Է��ϼ��� : ";
				cin >> tempstr;
				temp.setStr(tempstr);
				ary[count].setAddr(temp);
				break;
		case 3: cout << "������ ���̸� �Է��ϼ��� : ";
				cin >> tempage;
				ary[count].setAge(tempage);
				break;
		case 4: cout << "������ ������ �Է��ϼ��� : ";
				cin >> temphei;
				ary[count].setHeight(temphei);
				break;
		}
		cout << "************************" << endl;
		cout << "���� �� profile : ";
		cout << count + 1 << ". " << ary[count].getName().getStr() << " : "
			<< ary[count].getAddr().getStr() << "/" << ary[count].getAge() << "��/"
			<< ary[count].getHeight() << "cm" << endl;

		count = -1;
	}

}
//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "������ �Է�", "������ ����", "������ ���","����" };

	for (i = 0; i<4; i++)   // �޴� ���ڿ��� ����ϴ� �ݺ���
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
void proInput(Profile *ap, int *profileCnt)
{
	char name[50];
	char addr[80];
	int age;
	double height;
	// �Է� ���� �������� ������ ī��Ʈ�ϴ� ����

	while (1)
	{
		if (*profileCnt == 20) {
			cout << "20�� �Ѿ����ϴ�. " << endl;
			break;
		}
		cout << "�̸��Է� : ";
		cin >> name;
		if (strcmp(name, "��") == 0) { break; }
		cout << "�ּ��Է� : ";		cin >> addr;
		cout << "�����Է� : ";		cin >> age;
		cout << "Ű�Է� : ";		cin >> height;

		ap[*profileCnt] = Profile(name, addr, age, height); // �Է� ���� �����ͷ� ��ü �ʱ�ȭ
		(*profileCnt)++;
	}
}
//---------------------------------------------------------------
void proDisplay(Profile *ap, int *profileCnt)
{
	int i;
	for (i = 0; i < *profileCnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName().getStr() << " : "
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "��/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}
