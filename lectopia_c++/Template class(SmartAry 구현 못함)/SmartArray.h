#pragma once
#include"MyArray.h"
#include<iostream>
using namespace std;

template <typename T>
class SmartArray : public MyArray<T>
{
private:
	T max;
public:
	SmartArray() {}
	SmartArray(int s) : MyArray<T>(s), max(0) {}
	void put(int index, T val);
	T getMax();
	bool operartor(const SmartArray<T> &br);
};
template<typename Type>
bool SmartArray<T>::put(int index, T val)
{

	if (MyArray::put(index, val) == false) cout << "점수 입력 실패" << endl;
	else {
		if (this->max > val) return true;
		else {
			this->max = val;
			return false;
		}
	}
}
template<typename Type>
T SmartArray<T>::getMax()
{
	return this->max;
}
template<typename Type>
bool SmartArray<T>::operator>(const SmartArray<T> &br)
{
	if (this->max > br.max) return true;
	else return false;
}