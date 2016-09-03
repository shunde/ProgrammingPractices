#include <iostream>

template<unsigned int N>
void print() {
    print<N-1>();
    std::cout << ", " << N;
}

template<>
void print<1>() {
    std::cout << 1;
}

int main() {
    print<100>();
    return 0;
}
