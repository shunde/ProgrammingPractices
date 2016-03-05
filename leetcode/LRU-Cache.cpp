class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        cache.clear();        
    }
    
    int get(int key) {
        // todo
    }
    
    void set(int key, int value) {
        // todo
    }
private:
    struct DListNode {
        int val;
        DListNode *prev;
        DListNode *next;
    };
    unordered_map<int, DListNode*> cache;
    int _capacity;
};