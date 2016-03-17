class NumArray {
private:
    vector<int> acc;
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        acc.resize(nums.size(), 0);
        acc[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            acc[i] = nums[i] + acc[i-1];
        }        
    }

    int sumRange(int i, int j) {
        if (i == 0) return acc[j];
        else return (acc[j] - acc[i-1]);        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);