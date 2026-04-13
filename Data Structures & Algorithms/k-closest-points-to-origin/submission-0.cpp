class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k == points.size()) return points;
        priority_queue<pair<double, int>> store;
        for(int i = 0 ;i < points.size(); ++i) {
            double tmp = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            store.emplace(tmp, i);
            if(store.size() > k) {
                store.pop();
            }
        }
        vector<vector<int>> res;
        while(!store.empty()) {
            res.emplace_back(points[store.top().second]);
            store.pop();
        }
        return res;
    }
};
