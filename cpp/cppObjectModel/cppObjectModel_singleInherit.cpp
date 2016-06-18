#include <iostream>
using namespace std;

class Parent {
public:
	int iparent;
	Parent (): iparent (10) {}
	virtual void f() { cout << " Parent::f()" << endl; }
	virtual void g() { cout << " Parent::g()" << endl; }
	virtual void h() { cout << " Parent::h()" << endl; }

};

class Child : public Parent {
public:
	int ichild;
	Child(): ichild(100) {}
	virtual void f() { cout << "Child::f()" << endl; }
	virtual void g_child() { cout << "Child::g_child()" << endl; }
	virtual void h_child() { cout << "Child::h_child()" << endl; }
};

class GrandChild : public Child {
public:
	int igrandchild;
	GrandChild(): igrandchild(1000) {}
	virtual void f() { cout << "GrandChild::f()" << endl; }
	virtual void g_child() { cout << "GrandChild::g_child()" << endl; }
	virtual void h_grandchild() { cout << "GrandChild::h_grandchild()" << endl; }
};

int main() {
	typedef void(*Fun)(void);

	GrandChild gc;

	long long** pVtab = (long long**)&gc;

	cout << "[0] GrandChild::_vptr->" << endl;
	for (int i = 0; (Fun)pVtab[0][i] != NULL; i++) {
		Fun pFun = (Fun)pVtab[0][i];
		cout << "    [" << i << "] ";
		pFun();
	}

	int* vars = (int*)(pVtab+1);
	cout << "[1] Parent.iparent = " << vars[0] << endl;
	cout << "[2] Child.ichild = " << vars[1] << endl;
	cout << "[3] GrandChild.igrandchild = " << vars[2] << endl;
	return 0;
}
