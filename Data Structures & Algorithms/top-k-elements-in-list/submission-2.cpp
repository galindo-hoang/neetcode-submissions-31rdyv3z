class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res;
        for(int& i: nums) {
            ++count[i];
        }
        vector<vector<int>> store(nums.size());
        for(const auto& co: count) {
            store[co.second - 1].push_back(co.first);
        }
        for(int i = store.size() - 1; i >= 0 && res.size() < k; --i) {
            for(int j = 0; j < store[i].size() && res.size() < k; ++j) {
                res.push_back(store[i][j]);
            }
        }
        return res;
    }
};
