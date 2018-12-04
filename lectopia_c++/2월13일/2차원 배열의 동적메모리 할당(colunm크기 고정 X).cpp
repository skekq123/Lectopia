#include<iostream>
using namespace std;
void input(int &pnum, int &num);
void myAlloc(int &row, int &col, int** &ary);
void Print(int &row, int &col, int** &ary);
void input(int row, int col, int** &ary);
void myDelete(int &row, int &col, int** &ary);
int main()
{
	int pnum, snum;
	input(snum, pnum);
	int **ary;

	myAlloc(snum, pnum, ary);

	input(snum, pnum, ary);

	Print(snum, pnum, ary);

	myDelete(snum, pnum, ary);
	return 0;
}
void myDelete(int &row, int &col , int** &ary)
{
	int i;
	for (i = 0; i < row; i++)
		delete[] ary[i];

	delete[] ary;
}
void myAlloc(int &row, int &col, int** &ary)
{
	int i;
	ary = new int*[row];
	for (i = 0; i < row; i++)
		ary[i] = new int[col];
}
void Print(int &row, int &col, int** &ary)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < row; i++)
	{
		cout << i+1 <<"�� �л��� ���� : ";
		for (j = 0; j < col; j++)
		{
			sum += ary[i][j];
			cout << ary[i][j] << " ";
		}
		cout << "���� : " << sum << endl;
		sum = 0;
	}
}
void input(int &pnum, int &snum)
{
	cout << "�л� ���� �Է� : ";
	cin >> pnum;
	cout << "���� ���� �Է� : ";
	cin >> snum;
}
void input(int row, int col, int** &ary)
{
	int i, j;

	for (i = 0; i < row; i++)
	{
		cout << i+1 <<"���л��� ������ �Է��ϼ��� : ";
		for (j = 0; j < col; j++)
		{
			cin >> ary[i][j];
		}
	}
}