class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> pending;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i) {
            while(!pending.empty() && pending.top().first < temperatures[i]) {
                pair<int,int> cur = pending.top();
                pending.pop();
                res[cur.second] = i - cur.second;
            }
            pending.emplace(temperatures[i], i);
        }
        return res;
    }
};
