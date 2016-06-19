/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
    	Interval new_interval(val, val);
    	for (auto ite = intervals.begin(); ite != intervals.end(); ) {
    		if (new_interval.end < ite->start - 1) {
    			intervals.insert(ite, new_interval);
    			return;    			    			
    		} else if (new_interval.end == ite->start-1) {
    			//new_interval.end = ite->end;
    			//ite = intervals.erase(ite);
    			//intervals.insert(ite, new_interval);
    			// or change in-place
    			ite->start = new_interval.start;
    			return;
    		} else if (new_interval.start >= ite->start && new_interval.end <= ite->end) {
    			return;
    		} else if (new_interval.start == ite->end + 1) {
    			new_interval.start = ite->start;
    			ite = intervals.erase(ite);
    		} else {
    			ite++;
    		}
    	}
    	intervals.push_back(new_interval);        
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
	vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */