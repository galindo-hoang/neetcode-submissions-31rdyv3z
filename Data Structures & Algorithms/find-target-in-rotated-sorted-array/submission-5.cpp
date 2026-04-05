class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[left] < nums[right]) {
                if(nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // 8 1 2 3 4 5 6 7
                // 5 6 7 1 2 3 4
                // 5 6 7 1
                if(nums[mid] < target) {
                    if(target > nums[right] && nums[mid] < nums[right]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    if(nums[mid] > nums[right] && target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
