class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);        
    }

    // Removes the element from in front of queue.
    void pop(void) {
        _transport();
        out.pop();
    }

    // Get the front element.
    int peek(void) {
        _transport();
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if (in.empty() && out.empty()) return true;
        return false;        
    }
private:
    void _transport() {
        if (out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
private:
    stack<int> in;
    stack<int> out;
};