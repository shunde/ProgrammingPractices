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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> result;
    	for (auto& interval: intervals) {
    		if (interval.end < newInterval.start) {
    			result.push_back(interval);
    		} 
    		else if (interval.start > newInterval.end) {
    			result.push_back(newInterval);
    			newInterval = interval;
    		} 
    		else if (newInterval.end >= interval.start || newInterval.start <= interval.end) {
    			newInterval = Interval(
    				min(interval.start, newInterval.start), 
    				max(interval.end, newInterval.end)
    				);
    		}

    	}   
    	result.push_back(newInterval);
    	return result;     
    }
};