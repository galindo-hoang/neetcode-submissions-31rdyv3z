class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> pending;
        int res = heights[0];
        for(int i = 0; i < heights.size(); ++i) {
            int newPos = i;
            while(!pending.empty() && pending.top().first > heights[i]) {
                res = max(res, pending.top().first * (i - pending.top().second));
                newPos = pending.top().second;
                pending.pop();
            }
            pending.emplace(heights[i], newPos);
        }
        while(!pending.empty()) {
            res = max(res, ((int)heights.size() - pending.top().second) * pending.top().first);
            pending.pop();
        }
        return res;
    } 
};
