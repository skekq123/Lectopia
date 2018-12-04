#include <iostream>
#include "my_sp.h"
using namespace std;
class Light {
public:
	Light() : _stat(false) { cout << "call " << __FUNCTION__ << endl; }
	~Light() { cout << "call " << __FUNCTION__ << endl; }
	void setOn() { _stat = true; }
	void setOff() { _stat = false; }
	bool getStat() { return _stat; }
private:
	bool _stat;
};
inline void room_ctl(my_sp<Light>& r, bool on = true) {
	//on ? r->setOn() : r->setOff();
	on ? (*r).setOn() : (*r).setOff();
}