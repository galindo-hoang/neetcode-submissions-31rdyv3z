class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size() <= 1) return s.size();
        vector<int> store(128, -1);
        int pivot = -1;
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(store[(int) s[i]] != -1) {
                pivot = max(pivot, store[(int) s[i]]);
            }
            store[(int) s[i]] = i;
            res = max(res, i - pivot);
        }
        return res;
    }
};
