class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if(nums[left] <= nums[right]) {
                return nums[left];
            } else {
                int mid = (left + right) >> 1;
                if(nums[mid] > nums[right]) {
                    left = mid + 1;
                } else {
                    if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]) {
                        return nums[mid];
                    }
                    right = mid - 1;
                }
            }
        }
        return left;
    }
};
