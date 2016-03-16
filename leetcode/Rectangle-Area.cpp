#include <iostream>
#include <alogrithm>
using namespace std;

class Solution {
private:
    struct segment {
        int l, r, h; // left, right, high
        int flag; // 1 denote lower boundary of rectangle, -1 denote upper boundary of rectangle.
        segment(int _l, int _r, int _h, int _flag): l(_l), r(_r), h(_h), flag(_flag) {}
        bool operator < (const segment& seg) const {
            return h < seg.h;
        } 
    };
    segment ss[4];
    int x[4];
    int k;
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        ss[0] = segment(A, C, B, 1);
        ss[1] = segment(A, C, D, -1);
        ss[2] = segment(E, G, F, 1);
        ss[3] = segment(E, G, H, -1);

        x[0] = A;
        x[1] = C;
        x[2] = E;
        x[3] = G;

        sort(ss, ss+4);
        sort(x, x+4);

        
        k = 0;
        for (int i = 1; i < 4; i++)
            if (x[k] != x[i]) x[++k] = x[i];
        







    }
};