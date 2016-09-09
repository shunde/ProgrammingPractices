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
	int robHelper(TreeNode* root, bool canRob, unordered_map<TreeNode*, int>& dp) {
		if (root == NULL) return 0;
		if (!canRob) {
			return robHelper(root->left, true, dp) + robHelper(root->right, true, dp);
		}
		if (dp.find(root) == dp.end()) {
			int robThis = root->val;
			robThis += robHelper(root->left, false, dp) + robHelper(root->right, false, dp);
			int notRobThis = robHelper(root->left, true, dp) + robHelper(root->right, true, dp);

			dp[root] = max(robThis, notRobThis);

		}
		return dp[root];

	}
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode*, int> dp;

		return robHelper(root, true, dp);

	}
};