class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> pending;
        int l = 0;
        for(int i = 0; i < nums.size(); ++i) {
            while(!pending.empty() && pending.back() < nums[i]) {
                pending.pop_back();
            }
            pending.push_back(nums[i]);
            if(i - l + 1 == k) {
                res.push_back(pending.front());
                if(nums[l++] == pending.front()) {
                    pending.pop_front();
                }
            }
        }
        return res;
    }
};
