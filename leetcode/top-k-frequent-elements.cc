class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> counters;
		for (auto x : nums) {
			counters[x]++;
		}

		vector<int> topk;
		// 引用捕获，不然会超时
		auto comp = [&counters](const int& lhs, const int& rhs) -> bool {
			return counters.at(lhs) > counters.at(rhs);
		};
		bool firstFull = true;
		for (auto& kv : counters) {
			if (topk.size() < k) {
				topk.push_back(kv.first);
			} else {
			    if (firstFull) {
			        make_heap(topk.begin(), topk.end(), comp);
			        firstFull = false;
			    }
				if (kv.second > counters[topk.front()]) {
				    topk.push_back(kv.first);
					pop_heap(topk.begin(), topk.end(), comp);
					topk.pop_back();
					
				}
			}
		}
		return topk;
	}
};