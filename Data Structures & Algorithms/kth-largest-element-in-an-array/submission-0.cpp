class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pend;
        for(int& num:nums) {
            pend.emplace(num);
            if(pend.size() > k) {
                pend.pop();
            }
        }
        return pend.top();
    }
};
