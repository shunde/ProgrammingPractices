/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	ListNode* reverse(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *remain, *newlist;
		newlist = NULL;
		remain = head;
		while (remain) {
			ListNode *pNode = remain;
			remain = remain->next;
			pNode->next = newlist;
			newlist = pNode;
		}
		return newlist;
	}
public:
    bool isPalindrome(ListNode* head) {
    	if (head == NULL || head->next == NULL) return true;
    	ListNode *slow, *fast;
    	slow = fast = head;
    	while (fast) {
    		if (fast->next && fast->next->next) {
    			fast = fast->next->next;
    			slow = slow->next;
    		} else break;
    	}
    	ListNode* latter = slow->next;
    	slow->next = NULL;
    	latter = reverse(latter);
    	ListNode *pNodeA, *pNodeB;
    	pNodeA = head; 
    	pNodeB = latter;
    	while (pNodeA && pNodeB) {
    		if (pNodeA->val != pNodeB->val) return false;
    		pNodeA = pNodeA->next;
    		pNodeB = pNodeB->next;
    	}

    	if (pNodeB) return false;

    	if (pNodeA && pNodeA->next) return false;

    	return true;        
    }
};