class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        impl(nums, 0, tmp);
        return res;
    }
    void impl(vector<int>& nums, int s, vector<int>& tmp) {
        if(s == nums.size()) {
            res.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != -11) {
                int save = nums[i];
                tmp.emplace_back(nums[i]);
                nums[i] = -11;
                impl(nums, s + 1, tmp);
                nums[i] = save;
                tmp.pop_back();
            }
        }
    }
};
