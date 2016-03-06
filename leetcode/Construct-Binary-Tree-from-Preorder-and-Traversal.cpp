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
    TreeNode* _buildTree_aux(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator in_begin, vector<int>::iterator in_end) {
        if (pre_begin == pre_end) return NULL;
        
        int curVal = *pre_begin;
        vector<int>::iterator iter;
        iter = find(in_begin, in_end, curVal);
        int leftNum = iter - in_begin;
        
        TreeNode *pNode = new TreeNode(curVal);
        pNode->left = _buildTree_aux(pre_begin+1, pre_begin+1+leftNum, in_begin, iter);
        pNode->right = _buildTree_aux(pre_begin+1+leftNum, pre_end, iter+1, in_end);
        
        return pNode;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree_aux(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};