#include <cstdio>

using namespace std;

#define L(t) ((t)<<1)
#define R(t) (((t)<<1)+1)

#define MAXN (0x01 << 18)
#define N 100001

struct Node {
    int left;
    int right;
    int sum;
    int lazyAdd;
    int lazySet;
    Node(): sum(0), lazyAdd(0), lazySet(0) {}
    Node(int l, int r): left(l), right(r), sum(0), lazyAdd(0), lazySet(0) {}
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

void update(int t, int l, int r, int x, bool set) {
    // 不是叶子节点，下放 lazyTag
    if (ST[t].left < ST[t].right) {
        if (ST[t].lazySet != 0) {
            ST[L(t)].sum = (ST[L(t)].right - ST[L(t)].left+1) * ST[t].lazySet;
            ST[L(t)].lazySet = ST[t].lazySet;
            ST[L(t)].lazyAdd = 0;  // clear lazyAddTag

            ST[R(t)].sum = (ST[R(t)].right - ST[R(t)].left+1) * ST[t].lazySet;
            ST[R(t)].lazySet = ST[t].lazySet;
            ST[R(t)].lazyAdd = 0;  // clear lazyAddTag

            ST[t].lazySet = 0;
        }

        if (ST[t].lazyAdd != 0) {
            ST[L(t)].sum += (ST[L(t)].right - ST[L(t)].left+1) * ST[t].lazyAdd;
            ST[L(t)].lazyAdd += ST[t].lazyAdd;

            ST[R(t)].sum += (ST[R(t)].right - ST[R(t)].left+1) * ST[t].lazyAdd;
            ST[R(t)].lazyAdd += ST[t].lazyAdd;

            ST[t].lazyAdd = 0;
        }
    }
    if (ST[t].left == l && ST[t].right == r) {
        if (set) {
            ST[t].sum = (ST[t].right - ST[t].left + 1) * x;
            ST[t].lazySet = x;
        } else {
            ST[t].sum += (ST[t].right - ST[t].left + 1) * x;
            ST[t].lazyAdd = x;            
        }
        return;
    }
    int mid = (ST[t].left + ST[t].right) / 2;
    if (r <= mid) 
        update(L(t), l, r, x, set);
    else if (l > mid)
        update(R(t), l, r, x, set);
    else {
        update(L(t), l, mid, x, set);
        update(R(t), mid+1, r, x, set);
    }
    ST[t].sum = ST[L(t)].sum + ST[R(t)].sum;
}

int priceSum() {
    return ST[1].sum;
}

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%d", &nums[i]);
    build(1, 0, n);
    for (int i = 0; i < m; i++) {
        int cmd, l, r, x;
        scanf("%d %d %d %d", &cmd, &l, &r, &x);
        if (cmd == 0) {
            update(1, l, r, x, false);
        } else {
            update(1, l, r, x, true);
        }
        printf("%d\n", priceSum());
    }
    return 0;
}