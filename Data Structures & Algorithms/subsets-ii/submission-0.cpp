class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        imple(nums, tmp, 0);
        return res;
    }

    void imple(vector<int>& nums, vector<int>& tmp, int idx) {
        res.emplace_back(tmp);
        
        for(int i = idx; i < nums.size(); ++i) {
            if(i == idx || nums[i] != nums[i - 1]) {
                tmp.emplace_back(nums[i]);
                imple(nums, tmp, i + 1);
                tmp.pop_back();
            }
        }
    }
};
