/**
 * 涂鸦移动笔试题
 * 将二叉搜索树转换为双向链表
 * 下面的思路是需要新建节点；
 * 直接将二叉搜索树原地转换成双向链表，不建立新节点的思路见《剑指 Offer》
 **/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *prev, *next;
    ListNode(int val): val(val), prev(NULL), next(NULL) {}
};

ListNode* transform (TreeNode* root, ListNode* prev) {
    if (root == NULL) return prev;
    ListNode* curr = new ListNode(root->val);

    curr->prev = transform(root->left, prev);
    if (curr->prev) {
        curr->prev->next = curr;
    }

    return transform(root->right, curr);
}

// ======================
// test
// ======================
TreeNode* bst_insert(TreeNode* root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
    }
    else {
        if (val < root->val)
            root->left = bst_insert(root->left, val);
        else
            root->right = bst_insert(root->right, val);

    }
    return root;
}
TreeNode* buildBST(const vector<int>& nums) {
    TreeNode* root = NULL;
    for (auto x: nums) {
        root = bst_insert(root, x);
    }
    return root;
}

void inorder_traverse(TreeNode* root) {
    if (root == NULL) return;
    inorder_traverse(root->left);
    cout << root->val << " ";
    inorder_traverse(root->right);
}

void print_dlist(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums{4, 1, 5, 9, 2, 3};
    TreeNode* tree = buildBST(nums);
    ListNode fakeHead(0);
    transform(tree, &fakeHead);
    inorder_traverse(tree);
    cout << endl;
    print_dlist(fakeHead.next);
    return 0;
}
