#include <iostream>
using namespace std;

class Base1 {
public:
	virtual void f() { cout << "Base1:f" << endl;}
	virtual void g() { cout << "Base1:g" << endl;}
	virtual void h() { cout << "Base1:h" << endl;}
};

class Derive: public Base1
{
public:
	virtual void f1() { cout << "Derive:f1" << endl; }
	virtual void g1() { cout << "Derive:g1" << endl; }
};

typedef void (*Fun)(void);

int main() {
	Derive d;
	Base1 *b1 = new Derive();
	//b1->f1();    // this line will compile error

	Fun pFun = (Fun)*((long long*)*(long long*)(b1)+3);
	//cout << "sizeof(pFun)" << sizeof(pFun) << endl;
	//cout << "sizeof(long long)" << sizeof(long long) << endl;
	pFun();

	return 0;
}