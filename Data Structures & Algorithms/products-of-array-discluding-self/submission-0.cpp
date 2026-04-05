class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(),1);
        vector<int> suf(nums.size(),1);
        suf[nums.size() - 1] = nums[nums.size() - 1];
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            pre[i] = nums[i] * pre[i - 1];
            suf[nums.size() - 1 - i] = nums[nums.size() - 1 - i] * suf[nums.size() - i];
        }
        nums[0] = suf[1];
        nums[nums.size() - 1] = pre[nums.size() - 1 - 1]; 
        for(int i = 1; i < nums.size() - 1; ++i) {
            nums[i] = pre[i - 1] * suf[i + 1];
        }
        return nums;
    }
};
