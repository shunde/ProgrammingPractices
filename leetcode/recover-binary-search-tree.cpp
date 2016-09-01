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
	TreeNode *prev;
	TreeNode *first;
	TreeNode *second;
private:
	void inorder(TreeNode* root) {
		if (root == NULL) return;

		inorder(root->left);

		if (prev == NULL) {
			prev = root;
		} else {
			if (root->val < prev->val) {
				if (first == NULL) {
					first = prev;
				} 
				// !!!
				second = root;
			}
			prev = root;
		}
		inorder(root->right);
	}
public:
	// inorder bst -> ascending order
	// case: [1, 2, 6, 4, 5, 3, 7] -> (3,6) swapped
	// if an element is less than its previous element, the previous element is a swapped node.
    void recoverTree(TreeNode* root) {
    	// initialize
    	prev = first = second = NULL;

    	inorder(root);

    	if (second != NULL && first != NULL) {
    		std::swap(first->val, second->val);
    	}

        
    }
};