class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(count[nums[i]] == 0) {
                count[nums[i]] = count[nums[i] - 1] + count[nums[i] + 1] + 1;
                count[nums[i] + count[nums[i] + 1]] = count[nums[i]];
                count[nums[i] - count[nums[i] - 1]] = count[nums[i]];
                res = max(res, count[nums[i]]);
            }
        }
        return res;
    }
};
