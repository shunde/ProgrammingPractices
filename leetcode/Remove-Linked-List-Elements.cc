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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pNode = &dummy;
        while (pNode->next) {
            if (pNode->next->val == val) {
                ListNode* del =pNode->next;
                pNode->next = del->next;
                delete del;
            } else {
                pNode = pNode->next;
            }
        }
        
        return dummy.next;
    }
};