#include <cstdio>
#include <algorithm>

using namespace std;

#define L(t) ((t)<<1)
#define R(t) (((t)<<1)+1)

const int MAXN = 0x01 << 21;
const int N = 1000000+1;

struct Node {
    int left;
    int right;
    int minWeight;
    Node() {}
    Node(int l, int r): left(l), right(r), minWeight(0) {}
};

Node ST[MAXN];
int nums[N];

void build(int t, int l, int r) {
    if (r < l) return;

    ST[t] = Node(l, r);

    if (l == r) {
        ST[t].minWeight = nums[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(L(t), l, mid);
    build(R(t), mid+1, r);
    ST[t].minWeight = min(ST[L(t)].minWeight, ST[R(t)].minWeight);
    return;
}

int query(int t, int l, int r) {
    if (l <= ST[t].left && r >= ST[t].right) 
        return ST[t].minWeight;

    int mid = (ST[t].left + ST[t].right) / 2;
    if (r <= mid)
        return query(L(t), l, r);
    else if (l > mid)
        return query(R(t), l, r);
    else 
        return min(query(L(t), l, mid), query(R(t), mid+1, r));
}

void update(int t, int pos, int x) {

    if (ST[t].left == ST[t].right) {
        ST[t].minWeight = x;
        return;
    }
    int mid = (ST[t].left + ST[t].right)/2;
    if (pos <= mid)
        update(L(t), pos, x);
    else
        update(R(t), pos, x);
    
    ST[t].minWeight = min(ST[L(t)].minWeight, ST[R(t)].minWeight);
}

int main(int argc, char* argv[]) {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    build(1, 1, n);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0)
            printf("%d\n", query(1, a, b));
        else
            update(1, a, b);
    }
    return 0;
}