#ifndef _MY_SP_H
#define _MY_SP_H
#include "ISmartPointer.h"
template<typename T>
class my_sp : public Isp<T> {
public:
	my_sp(T * p) : ptr(p) {}
	virtual ~my_sp() { delete ptr; }
	T * operator->() const { return ptr; }
	T * operator&() const { return ptr; }
	T & operator*() const { return *ptr; }
private:
	T * ptr;
};
#endif