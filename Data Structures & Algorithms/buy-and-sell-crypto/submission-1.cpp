class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(mi > prices[i]) {
                mi = prices[i];
            } else {
                res = max(res, prices[i] - mi);
            }
        }
        return res;
    }
};
