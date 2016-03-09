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
    ListNode* reverseList(ListNode* head) {
        // empty list or only one node
        if (head == NULL || head->next == NULL) return head;
        ListNode *pNode;
        ListNode *reverseHead = NULL;
        while (head != NULL) {
            pNode = head;
            head = head->next;
            
            pNode->next = reverseHead;
            reverseHead = pNode;
        }
        return reverseHead;
    }
};