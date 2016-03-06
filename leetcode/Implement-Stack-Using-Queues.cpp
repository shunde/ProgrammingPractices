class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        myQueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = myQueue.size();
        for (int i = 0; i < n-1; i++) {
            int val = myQueue.front();
            myQueue.pop();
            myQueue.push(val);
        }
        myQueue.pop();
    }

    // Get the top element.
    int top() {
       int n = myQueue.size();
        for (int i = 0; i < n-1; i++) {
            int val = myQueue.front();
            myQueue.pop();
            myQueue.push(val);
        } 
        int ret = myQueue.front();
        myQueue.pop();
        myQueue.push(ret);
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return myQueue.empty();
    }
private:
    queue<int> myQueue;
};