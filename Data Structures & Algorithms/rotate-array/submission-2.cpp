class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        rever(nums, 0, nums.size() - 1);
        rever(nums, 0, k - 1);
        rever(nums, k, nums.size() - 1);
    }
    void rever(vector<int>& nums, int l, int r) {
        while(l < r) {
            swap(nums[l++], nums[r--]);
        }
    }

    // 1,2,3,4,5,6,7 = 4
    // 1,2,3,4,5,6,7 = 3
    // 1,2,3,4,5,6,7 = 2
};