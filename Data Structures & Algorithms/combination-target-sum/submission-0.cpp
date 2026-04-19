class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        impl(nums, nums.size() - 1, target, tmp);
        return res;
    }
    void impl(vector<int>& nums, int pos, int &target, vector<int> &tmp) {
        for(int i = pos; i >= 0; --i) {
            if(nums[i] <= target) {
                target -= nums[i];
                tmp.push_back(nums[i]);
                if(target == 0) {
                    res.push_back(tmp);
                } else {
                    impl(nums, i, target, tmp);
                }
                tmp.pop_back();
                target += nums[i];
            }
        }
    }
};
