class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int res = nums.size() + 1;
        for(int right = 0; right < nums.size(); ++right) {
            target -= nums[right];
            while(target <= 0 && left <= right) {
                res = min(res, right - left + 1);
                target += nums[left++];
            }
        }
        if(res == nums.size() + 1) return 0;
        return res;
    }
};