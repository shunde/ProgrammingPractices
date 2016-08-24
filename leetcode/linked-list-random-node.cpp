/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
    	int ret = _head->val;
    	int count = 1;
    	ListNode *pNode = _head->next;
    	while (pNode) {
    		++count;
    		if (rand() % count == count - 1)
    			ret = pNode->val;
    		pNode = pNode->next;
    	}
    	return ret;       
    }
private:
	ListNode* _head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */