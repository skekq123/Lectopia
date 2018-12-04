#pragma once
template<typename Type>
class MyArray
{
private:
	Type *ary;
	int size;
public:
	MyArray() { Type ary = 0; Type size = 0; }
	MyArray(int s);
	MyArray(const Type &br);
	~MyArray() { delete[] ary; };
	MyArray &operator=(const Type &br);
	bool put(int index, Type val);
	bool get(int index, Type &getdata);

	Type getSize();
	Type *getAry(void);
};
template<typename Type>
MyArray<Type>::MyArray(int s)
{
	this->ary = new double[s];
	this->size = s;
}
template<typename Type>
MyArray<Type>::MyArray(const Type &br)
{
	this->ary = new Type[sizeof(br.ary) / sizeof(br.ary[0])];
	this->size = br.size;
}
template<typename Type>
MyArray<Type>& MyArray<Type>::operator=(const Type &br)
{
	if (this == &br) return *this;
	delete[] this->ary;
	this->ary = new int[sizeof(br.ary) / sizeof(br.ary[0])];
	this->size = br.size;

	return *this;
}
template<typename Type>
bool MyArray<Type>::put(int index, Type val)
{
	if (this->size - 1 < index) return false;
	else
	{
		this->ary[index] = val;
		return true;
	}
}
template<typename Type>
bool MyArray<Type>::get(int index, Type &getdata)
{
	if (this->size - 1 < index) return false;
	else
	{
		getdata = this->ary[index];
		return true;
	}
}
template<typename Type>
Type MyArray<Type>::getSize()
{
	return this->size;
}
template<typename Type>
Type* MyArray<Type>::getAry(void)
{
	return this->ary;
}