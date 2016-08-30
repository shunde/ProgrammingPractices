/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> result;
    	if (intervals.empty()) return result;

    	auto comp = [](const Interval& lhs, const Interval& rhs) {
    		return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end);
    	}; 
    	sort(intervals.begin(), intervals.end(), comp);
    	Interval currInterval = intervals[0];
    	for (int i = 1; i < intervals.size(); i++) {
    		if (currInterval.end < intervals[i].start) {
    			result.push_back(currInterval);
    			currInterval = intervals[i];    			
    		} 
    		else if (currInterval.end <= intervals[i].end) {
    			currInterval.end = intervals[i].end;
    		}
    	}
    	result.push_back(currInterval);
    	return result;
    }
};