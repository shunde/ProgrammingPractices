/**
 * Description:
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 * Supposed the linked list is 1 -> 2 -> 3 -> 4, 
 * and you are given the third node with value 3, 
 * the linked list should become 1 -> 2 -> 4 after calling your function.
 */

 // Idea
 // 将要被删除结点的下一个结点的值赋值给该结点，把问题转化为删除下一个结点


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
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        ListNode *pNode = node->next;
        node->val = pNode->val;
        node->next = pNode->next;
        delete pNode;
    }
};