/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  TreeNode* buildTreeHelper(vector<int>::iterator inbegin,
                            vector<int>::iterator inend,
                            vector<int>::iterator postbegin,
                            vector<int>::iterator postend) {
    if (inbegin == inend) return NULL;
    int val = *(postend - 1);
    auto it = find(inbegin, inend, val);

    TreeNode* root = new TreeNode(val);
    root->left =
        buildTreeHelper(inbegin, it, postbegin, postbegin + (it - inbegin));
    root->right =
        buildTreeHelper(it + 1, inend, postbegin + (it - inbegin), postend - 1);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(),
                           postorder.end());
  }
};