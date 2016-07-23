/**
 * Reference: http://bangbingsyb.blogspot.sg/2014/11/leetcode-best-time-to-buy-and-sell.html
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> leftProfit(n,0);
        
        int maxLeftProfit = 0, minPrice = prices[0];
        for(int i=1; i<n; i++) {
            if(prices[i]<minPrice)
                minPrice = prices[i];
            else
                maxLeftProfit = max(maxLeftProfit, prices[i]-minPrice);
            leftProfit[i] = maxLeftProfit;
        }
        
        int ret = leftProfit[n-1];
        int maxRightProfit = 0, maxPrice = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            if(prices[i]>maxPrice)
                maxPrice = prices[i];
            else
                maxRightProfit = max(maxRightProfit, maxPrice-prices[i]);
            ret = max(ret, maxRightProfit + leftProfit[i]);
        }
        
        return ret;
    }
};