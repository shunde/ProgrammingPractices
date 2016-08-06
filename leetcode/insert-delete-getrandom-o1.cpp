class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (kv.find(val) != kv.end())
            return false;
        else {
            int idx = data.size();
            kv[val] = idx;
            data.push_back(val);
            return true;
        }

    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto got = kv.find(val);
        if (got == kv.end())
            return false;
        else {
            int idx = got->second;
            kv.erase(got);
            if (idx < data.size()-1) {
                kv[data.back()] = idx;    // important
                swap(data[idx], data[data.size()-1]);
            }
            data.pop_back();
            return true;
        }        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % data.size();
        return data[idx];        
    }
private:
    vector<int> data;
    unordered_map<int, int> kv;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */