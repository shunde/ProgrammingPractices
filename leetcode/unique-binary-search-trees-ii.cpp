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
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return f(1, n);
    }
private:
	vector<TreeNode*> f(int lo, int hi) {
		vector<TreeNode*> subTrees;
		if (lo > hi) {
			subTrees.push_back(NULL);			
		} else if (lo == hi) {
			subTrees.push_back(new TreeNode(lo));
		} else {
			for (int k = lo; k <= hi; k++) {
				vector<TreeNode*> leftSubTrees = f(lo, k-1);
				vector<TreeNode*> rightSubTrees = f(k+1, hi);
				for (int i = 0; i < leftSubTrees.size(); i++) {
					for (int j = 0; j < rightSubTrees.size(); j++) {
						TreeNode* pNode = new TreeNode(k);
						pNode->left = leftSubTrees[i];
						pNode->right = rightSubTrees[j];
						subTrees.push_back(pNode);
					}
				}
			}			
		}

		return subTrees;
	}
};