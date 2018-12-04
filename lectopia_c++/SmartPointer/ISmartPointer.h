#ifndef _ISmartPointer_H
#define _ISmartPointer_H
template<typename T>
struct Isp
{
	virtual ~Isp() {};
	virtual T * operator->() const = 0;
	virtual T * operator&() const = 0;
	virtual T & operator*() const = 0;
};
#endif
