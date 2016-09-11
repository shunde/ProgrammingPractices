#include <iostream>

// x64
struct A {
    void (*func)(int);
    long a;
    char* p;
    int b;
    char c;
};

// 函数声明
struct B {
    int add(int, int);
};

// 函数指针
struct C {
    int (*add)(int, int);
};

int main() {
    std::cout << sizeof(struct A) << std::endl;
    std::cout << sizeof(struct B) << std::endl;
    std::cout << sizeof(struct C) << std::endl;
    return 0;
}
