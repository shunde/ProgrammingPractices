/**
 * 使用辅助栈保存最小元素。
 * 入栈的时候将当前最小元素压入栈，出栈时也弹出辅助栈的栈顶元素。
 */


class MinStack {
public:
    void push(int x) {
        _stack.push(x);
        if (_minStack.empty())
            _minStack.push(x);
        else {
            int _min = _minStack.top();
            if (x < _min)
                _minStack.push(x);
            else
                _minStack.push(_min);
        }
        
    }

    void pop() {
        _stack.pop();
        _minStack.pop();        
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return _minStack.top();
    }
private:
    stack<int> _stack;
    stack<int> _minStack;
};