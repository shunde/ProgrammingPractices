#include <cstdio>
#include <algorithm>

using namespace std;

#define L(t) ((t)<<1)
#define R(t) (((t)<<1)+1)

const int MAXN = 0x01 << 18;
const int N = 100001;

struct Node {
    int left;
    int right;
    int sum;
    int newP;
    Node(): newP(0) {}
    Node(int l, int r): left(l), right(r), sum(0), newP(0) {}
};

Node ST[MAXN];
int nums[N];

void build(int t, int l, int r) {
    if (r < l) return;
    ST[t] = Node(l, r);

    if (l == r) {
        ST[t].sum = nums[l];
        return;
    }
    int mid = (l+r)/2;
    build(L(t), l, mid);
    build(R(t), mid+1, r);
    ST[t].sum = ST[L(t)].sum + ST[R(t)].sum;
    return;
}

int queryRangeSum(int t, int l, int r) {
    if (l == ST[t].left && r == ST[t].right)
        return ST[t].sum;

    int mid = (ST[t].left + ST[t].right)/2;
    if (ST[t].newP) {
        ST[L(t)].sum = ST[t].newP * (mid - ST[t].left+1);
        ST[L(t)].newP = ST[t].newP;

        ST[R(t)].sum = ST[t].newP * (ST[t].right - mid);
        ST[R(t)].newP = ST[t].newP;
        ST[t].newP = 0;
    }

    if (r <= mid)
        return queryRangeSum(L(t), l, r);
    else if (l > mid)
        return queryRangeSum(R(t), l, r);
    else
        return queryRangeSum(L(t), l, mid) + queryRangeSum(R(t), mid+1, r);
}

void updateRange(int t, int l, int r, int x) {
    if (r < l) return;
    if (ST[t].left == ST[t].right) {
        ST[t].sum = x;
        return;
    }
    if (ST[t].left == l && ST[t].right == r) {
        ST[t].sum = (r-l+1)*x;
        ST[t].newP = x;
        return;
    }
    int mid = (ST[t].left + ST[t].right)/2;
    if (ST[t].newP) {
        ST[L(t)].sum = ST[t].newP * (mid - ST[t].left+1);
        ST[L(t)].newP = ST[t].newP;

        ST[R(t)].sum = ST[t].newP * (ST[t].right - mid);
        ST[R(t)].newP = ST[t].newP;

        ST[t].newP = 0;
    }

    if (r <= mid) {
        updateRange(L(t), l, r, x);
    } else if (l > mid) {
        updateRange(R(t), l, r, x);
    } else {
        updateRange(L(t), l, mid, x);
        updateRange(R(t), mid+1, r, x);
    }
    ST[t].sum = ST[L(t)].sum + ST[R(t)].sum;
    return;
}

int main(int argc, char *argv[]) {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i]);

    build(1, 1, n);

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", queryRangeSum(1, l, r));
        } else {
            int l, r, newP;
            scanf("%d %d %d", &l, &r, &newP);
            updateRange(1, l, r, newP);
        }
    }
    return 0;
}