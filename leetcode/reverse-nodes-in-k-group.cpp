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
		ListNode *reversedHead = NULL;
		ListNode *remain = head;
		while (remain) {
			ListNode *pNode = remain;
			remain = remain->next;
			pNode->next = reversedHead;
			reversedHead = pNode;
		}
		return reversedHead;
	}
	ListNode* advance(ListNode* head, int k) {
		ListNode* pNode = head;
		int n = 0;
		while (++n < k && pNode) {
			pNode = pNode->next;
		}
		return pNode;
	}
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *reversedHead = NULL;
		ListNode *gHead, *gTail;
		ListNode *remain = head;
		ListNode *last = NULL;		

		do {
			gHead = remain;
			gTail = advance(gHead, k);
			if (gTail) {
				remain = gTail->next;
				gTail->next = NULL;
				ListNode *group = reverse(gHead);
				if (reversedHead == NULL) reversedHead = group;
				if (last != NULL) last->next = group;
				last = gHead;

			} else {
				// left-out nodes
				if (reversedHead == NULL) reversedHead = gHead;
				if (last != NULL) {
					last->next = gHead;
				}
				
				remain = NULL;
			}

		} while (remain);

		return reversedHead;
	}
};