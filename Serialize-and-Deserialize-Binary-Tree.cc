/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	if (!root) return string("[]");
    	string codec = "[";
    	bool first = true;
    	queue<TreeNode *> workq;
    	workq.push(root);
    	int notNullCount = 1;
    	while (!workq.empty() && notNullCount > 0) {
    		TreeNode *pNode = workq.front();
    		workq.pop();
    		if (pNode) {
    			notNullCount -= 1;
    			if (first) {
    				codec += to_string(pNode->val);
    				first = false;
    			} else {
    				codec += "," + to_string(pNode->val);
    			}

    			if (pNode->left) notNullCount++;
    			workq.push(pNode->left);
    			if (pNode->right) notNullCount++;
    			workq.push(pNode->right);
    		} else { // NULL
    			codec += ",null";
    		}
    	}
    	codec += "]";
    	return codec;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	// delete '[' and ']'
    	string codec = data.substr(1, data.length()-2);
    	if (codec.empty()) return NULL;
    	queue<TreeNode *> workq;
    	TreeNode * root = NULL;
    	size_t npose = 0;
    	size_t index = codec.find_first_of(',', npose);
    	string token = codec.substr(npose, index-npose);
    	
    	if (token.compare("null") == 0) return NULL;
    
    	int val = stoi(token);
    	root = new TreeNode(val);
    	workq.push(root);

    	while (index != string::npos) {
    		TreeNode *pNode = workq.front();
    		workq.pop();
    		npose = index + 1;
    		index = codec.find_first_of(',', npose);
    		token = codec.substr(npose, index - npose);
    		if (token.compare("null") != 0) {
    			int val = stoi(token);
    			pNode->left = new TreeNode(val);
    			workq.push(pNode->left);
    		}

    		if (index == string::npos) break;
    		npose = index + 1;
    		index = codec.find_first_of(',', npose);
    		token = codec.substr(npose, index - npose);
    		if (token.compare("null") != 0) {
    			int val = stoi(token);
    			pNode->right = new TreeNode(val);
    			workq.push(pNode->right);
    		}
    	}
    	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));