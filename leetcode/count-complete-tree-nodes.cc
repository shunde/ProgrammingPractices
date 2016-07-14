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
	int leftMostHeight(TreeNode* root) {
		int height = 0;
		TreeNode *pNode = root;
		while (pNode != NULL) {
			height++;
			pNode = pNode->left;
		}
		return height;
	}
	int rightMostHeight(TreeNode* root) {
		int height = 0;
		TreeNode *pNode = root;
		while (pNode != NULL) {
			height++;
			pNode = pNode->right;
		}
		return height;
	}
public:
    int countNodes(TreeNode* root) {
                
    }
};