class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto found = index.find(val);
        if (found == index.end()) {
            Item item(val);
            int idx = collection.size();
            collection.push_back(item);
            index[val] = idx;
            return true;
        } else {
            int tail = found->second;
            Item item(val, tail);
            int idx = collection.size();
            collection.push_back(item);
            collection[tail].nextIdx = idx;
            found->second = idx;
            return false;
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto found = index.find(val);
        if (found == index.end()) {
            return false;
        } else {
            int idx = found->second;

            if (collection[idx].prevIdx == -1) {
                index.erase(found);
            } else {
                found->second = collection[idx].prevIdx;
            }

            if (idx < collection.size() - 1) {
                // case idx not the last one
                // move last one to collection[idx]
                collection[idx] = collection.back();
                int prevIdx = collection[idx].prevIdx;
                int nextIdx = collection[idx].nextIdx;
                if (prevIdx != -1) {
                    collection[prevIdx].nextIdx = idx;
                }
                
                if (nextIdx == -1) {
                    int val = collection[idx].val;
                    index[val] = idx;
                } else {
                    collection[nextIdx].prevIdx = idx;
                }                
            }

            collection.pop_back();

            return true;
        }
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % collection.size();
        return collection[idx].val;
    }
private:
    struct Item {
        int val;
        int nextIdx;
        int prevIdx;
        Item(int x, int prev = -1, int next = -1): val(x), prevIdx(prev), nextIdx(next) {}
    };
    unordered_map<int, int> index;
    vector<Item> collection;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */