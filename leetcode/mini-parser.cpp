/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger*> mystack;
        int val = 0;
        bool negsign = false;
        NestedInteger* pInt = NULL;
        int idx = 0;
        for (; idx < s.length(); ) {
            if (s[idx] == '[') {
                pInt = new NestedInteger();
                mystack.push(pInt);
                pInt = NULL;
                ++idx;
            } else if (s[idx] == '-' || (s[idx] >= '0' && s[idx] <= '9')) {
                if (s[idx] == '-') {
                    negsign = true;
                    ++idx;
                }
                while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
                    val = val * 10 + s[idx] - '0';
                    ++idx;
                }
                if (negsign) val = -val;
                pInt = new NestedInteger(val);
                
                val = 0; negsign = false;
            } else if (s[idx] == ',') {
                if (pInt != NULL) {
                    mystack.top()->add(*pInt);
                    delete pInt;
                    pInt = NULL;
                }
                ++idx;
            } else { // case ']' 
                if (pInt != NULL) {
                    mystack.top()->add(*pInt);
                    delete pInt;
                } 
                pInt = mystack.top();
                mystack.pop();
                ++idx;
            }
        }
        NestedInteger ret = *pInt;
        delete pInt;
        return ret;
    }
};