class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        int ml = height[l], mr = height[r];
        while(l < r) {
            if(ml <= mr) {
                ++l;
                res += max(0, min(ml, mr) - height[l]);
                ml = max(ml, height[l]);
            } else {
                --r;
                res += max(0, min(ml, mr) - height[r]);
                mr = max(mr, height[r]);
            }
        }
        return res;
    }
};
