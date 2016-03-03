#include <iostream>

class A {
private:
    int value;

public:
    // add explicit, cann't pass compile
    explicit A(int n) { value = n; }
    void print() { std::cout << value << std::endl; }
};

int main(int argc, char *argv[]) {
    A a = 10;
    A b = a;
    b.print();
    return 0;
}