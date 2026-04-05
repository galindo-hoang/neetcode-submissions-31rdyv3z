class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            int tmp = numbers[left] + numbers[right];
            if(tmp < target) {
                ++left;
            } else if(tmp > target) {
                --right;
            } else{
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};
