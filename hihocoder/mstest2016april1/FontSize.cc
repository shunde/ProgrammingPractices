#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int charactersPerPage(int s, int w, int h) {
    int cols = w / s;
    int rows = h / s;
    return cols * rows;
}

int upperBound(int n, int w, int h, int p) {
    int minCountPerPage = (n - 1)/p + 1;
    return (int)sqrt(w * h / minCountPerPage);
}

int upperAlign(int n, int align) {
    return ((n-1)/align + 1) * align;
}

int maxSize(const vector<int> &iv, int w, int h, int p) {
    int total = accumulate(iv.begin(), iv.end(), 0);
    int fontsize = upperBound(total, w, h, p);

    for(; fontsize >= 1; fontsize--) {

        if (w / fontsize == 0) {            
            continue;
        }

        int alignTotal = 0;
        for (int i = 0; i < iv.size(); i++) {
            alignTotal += upperAlign(iv[i], w/fontsize);
        }

        if (alignTotal <= p * charactersPerPage(fontsize, w, h)) 
            break;
    }
    return fontsize;
}

int main(int argc, char *argv[]) {
    int tasks;
    
    cin >> tasks;
    while (tasks-- > 0) {
        int N, P, W, H;
        cin >> N >> P >> W >> H;
        vector<int> iv(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> iv[i];
        }
        cout << maxSize(iv, W, H, P) << endl;
    }
    return 0;

}