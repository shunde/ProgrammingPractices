#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define L(t) ((t)<<1)
#define R(t) (((t)<<1)+1)

struct EndPoint {
    int no;    // order
    int value; // position
    bool left; // true -> left endpoint, false -> right endpoint.
    EndPoint() {}
    EndPoint(int n, int v, bool flag): no(n), value(v), left(flag) {}
};

struct Poster {
    int left;
    int right;
};

struct Comp {
    bool operator() (const EndPoint& lhs, const EndPoint& rhs) {
        return lhs.value < rhs.value;
    }
};

struct Node {
    int left;
    int right;
    int type; // 0 -> no segment, 1 -> whole segment[left, right], 2 -> others.
    int no; // means only when type == 1
    bool lazy; //
    Node(): type(0), no(-1), lazy(false) {}
    Node(int l, int r): left(l), right(r), type(0), no(-1), lazy(false) {}
};

#define MAXN (0x01 << 18)
Node ST[MAXN];


void build(int t, int l, int r) {
    if (r <= l) return;
    ST[t] = Node(l, r);
    if (r == l + 1)
        return;

    int mid = (l + r) / 2;
    build(L(t), l, mid);
    build(R(t), mid, r);
}

void insert(int t, int l, int r, int no) {
    if (r <= l) return;

    if (ST[t].left == l && ST[t].right == r) {
        ST[t].type = 1;
        ST[t].no = no;
        ST[t].lazy = true;
        return;
    }

    if (ST[t].type == 1 && ST[t].lazy) {
        ST[L(t)].type = 1;
        ST[L(t)].no = ST[t].no;
        ST[L(t)].lazy = true;

        ST[R(t)].type = 1;
        ST[R(t)].no = ST[t].no;
        ST[R(t)].lazy = true;

        ST[t].lazy = false;
    }

    ST[t].type = 2;

    int mid = (ST[t].left + ST[t].right) / 2;

    if (r <= mid) {
        insert(L(t), l, r, no);
    } else if (l >= mid) {
        insert(R(t), l, r, no);
    } else {
        insert(L(t), l, mid, no);
        insert(R(t), mid, r, no);
    }
    
}

void query(int t, unordered_set<int> &nums) {
    
    if (ST[t].type == 0) 
        return;
    else if (ST[t].type == 1) {
        nums.insert(ST[t].no);
        return;        
    } else if (ST[t].left < ST[t].right - 1){
        query(L(t), nums);
        query(R(t), nums);
    }
}

int main(int argc, char* argv[]) {
    int n, l;
    vector<EndPoint> points;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        points.push_back(EndPoint(i, l, true));
        points.push_back(EndPoint(i, r, false));
    }
    sort(points.begin(), points.end(), Comp());

    // 离散化
    int count = 1;
    int prev = points[0].value;
    points[0].value = count;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].value != prev)
            ++count;

        prev = points[i].value;
        points[i].value = count;
    }

  

    build(1, 1, count);

    vector<Poster> posters(n);
    for (auto &endpoint : points) {
        if (endpoint.left)
            posters[endpoint.no].left = endpoint.value;
        else
            posters[endpoint.no].right = endpoint.value;
    }

    for (int i = 0; i < posters.size(); i++) {        
        insert(1, posters[i].left, posters[i].right, i);
    }

    unordered_set<int> nums;
    query(1, nums);
    printf("%d\n", nums.size());

    return 0;
}

