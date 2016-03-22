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
    ListNode *detectCycle(ListNode *head) {
        // empty list or cycle list with only one node.
        if (head == NULL || head->next == head) return head;

        ListNode *slow, *fast;
        slow = fast = head;
        while (fast != NULL) {
            slow = slow->next;

            fast = fast->next;
            if (fast) fast = fast->next;
            else break;

            if (fast == slow) break;
        }

        // no cycle
        if (!fast) return NULL;

        ListNode *pNode = head;
        while (pNode != slow) {
            pNode = pNode->next;
            slow = slow->next;
        }

        return pNode;
        
    }
};