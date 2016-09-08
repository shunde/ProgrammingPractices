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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *oddHead = NULL, *oddTail = NULL;
        ListNode *evenHead = NULL, *evenTail = NULL;

        int i = 1;
        while (head) {
            ListNode* pNode = head;
            head = head->next;
            pNode->next = NULL;
            
            if (i & 0x01) {
                if (oddTail) {
                    oddTail->next = pNode;
                }
                oddTail = pNode;
                if (!oddHead) {
                    oddHead = oddTail;
                }
            } else {
                if (evenTail) {
                    evenTail->next = pNode;
                }
                evenTail = pNode;
                if (!evenHead) {
                    evenHead = evenTail;
                }
            }
            i++;
        }
        if (oddHead) {
            oddTail->next = evenHead;
            return oddHead;
        } else {
            return evenHead;
        }
    }
};