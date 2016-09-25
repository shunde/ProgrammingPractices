#include <iostream>
using namespace std;

/*
 * 输入一个整数N，找出所有连续整数和等于N的整数，并输出
 * 例如，输入N = 15
 * 输出
 * 15 = 7 + 8
 * 15 = 4 + 5 + 6
 * 15 = 1 + 2 + 3 + 4 + 5
 */
void doit(int n) {
    int count = 2;
    while (true) {
        if (count % 2 == 0 && (n*1.0/count) == (n/count + 0.5)) {
            int start = n / count - count/2 + 1;
            if (start <= 0) break;
            cout << n << " = " << start;
            for (int i = 1; i < count; i++) {
                cout << " + " << start + i;
            }
            cout << endl;
        } else if (count % 2 == 1 && n % count == 0) {
            int start = n / count - count / 2;
            if (start <= 0) break;
            cout << n << " = " << start;
            for (int i = 1; i < count; i++) {
                cout << " + " << start + i;
            }
            cout << endl;
        }
        count++;
    }
}

int main() {
    //int n;
    //cin >> n;
    //doit(n);
    for (int i = 3; i <= 100; i++)
        doit(i);
    return 0;
}
