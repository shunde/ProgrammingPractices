#include <iostream>

class A {};

class B {
public:
    B() {}
    ~B() {}
};

class C {
public:
    C() {}
    virtual ~C() {}
};

int main(int argc, char* argv[]) {
    A a;
    B b;
    C c;
    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl;
    return 0;
}