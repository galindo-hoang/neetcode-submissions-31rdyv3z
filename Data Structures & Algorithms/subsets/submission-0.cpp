class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.emplace_back(vector<int>());
        for(int i = 0; i < nums.size(); ++i) {
            vector<int> tmp;
            tmp.emplace_back(nums[i]);
            res.emplace_back(tmp);
            impl(nums, i, tmp);
            tmp.pop_back();
        }
        return res;
    }
    void impl(vector<int>& nums, int pos, vector<int>& tmp) {
        for(int i = pos + 1; i < nums.size(); ++i) {
            tmp.emplace_back(nums[i]);
            res.emplace_back(tmp);
            impl(nums, i, tmp);
            tmp.pop_back();
        }
    }
};
