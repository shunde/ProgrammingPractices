class NumArray {
private:
    struct node {
        int left, right;
        int sum;
    };

public:
    NumArray(vector<int> &nums) {
        nums_ = nums;
        int n = nums.size();
        n = bound_up(n);
        segTree_.reserve(n * 2);
        build(1, 0, nums_.size() - 1);
    }

    void update(int i, int val) {
        int delta = val - nums_[i];
        nums_[i] = val;
        updateDelta(1, i, delta);
    }

    int sumRange(int i, int j) {
        return query(1, i, j);
    }
private:
    int L(int t) {
        return t << 1;
    }
    int R(int t) {
        return (t << 1) + 1;
    }

    int query(int t, int l, int r) {
        if (l <= segTree_[t].left && r >= segTree_[t].right) return segTree_[t].sum;
        if (r <= segTree_[L(t)].right)
            return query(L(t), l, r);
        else if (l >= segTree_[R(t)].left)
            return query(R(t), l, r);
        else 
            return query(L(t), l, r) + query(R(t), l, r);
    }
    void updateDelta(int t, int x, int delta) {
        if (x < segTree_[t].left || x > segTree_[t].right)
            return;

        segTree_[t].sum += delta;
        if (x == segTree_[t].left && x == segTree_[t].right)
            return;

        if (x <= segTree_[L(t)].right) {
            updateDelta(L(t), x, delta);
        } else {
            updateDelta(R(t), x, delta);
        }
    }
    void build(int t, int l, int r) {
        if (r < l) return;

        segTree_[t].left = l;
        segTree_[t].right = r;

        if (l == r) {
            segTree_[t].sum = nums_[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(L(t), l, mid);
        build(R(t), mid + 1, r);
        segTree_[t].sum = segTree_[L(t)].sum + segTree_[R(t)].sum;
        return;
    }
    int bound_up(int n) {
        n -= 1;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return n + 1;
    }
private:
    vector<node> segTree_;
    vector<int> nums_;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
