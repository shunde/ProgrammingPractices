// Idea: 
// The relation between subsets of Sn and Sn-1 is as follows:
// {subset of Sn-1} U {each element in Sn-1 + one more element}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> result;
    	for (auto x: nums) {
    		vector<vector<int>> temp;

    		// get sets that already in result
    		// add x to existing sets
    		for (auto subset: result) {
    			subset.push_back(x);
    			temp.push_back(subset);
    		}

    		// {x} as a single set
    		temp.push_back(vector<int> {x});

    		result.insert(result.end(), temp.begin(), temp.end());
    	}

    	// add empty set
    	result.push_back(vector<int>());
    	return result;    	        
    }
};