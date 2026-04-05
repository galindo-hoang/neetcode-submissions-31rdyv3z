class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0], ma = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > ma) {
                res = max(res, prices[i] - mi);
                ma = prices[i];
            } else if(mi > prices[i]) {
                ma = mi = prices[i];
            }
        }
        return res;
    }
};
