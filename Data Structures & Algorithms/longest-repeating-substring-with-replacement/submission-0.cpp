class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, res = 0, maxf = 0;
        unordered_map<char, int> store;
        for(; r < s.size(); ++r) {
            maxf = max(maxf,++store[s[r]]);
            if(r - l + 1 - maxf <= k) {
                res = max(res, r - l + 1);
            } else {
                --store[s[l++]];
                if(r - l + 1 - store[s[l]] <= k) {
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    }
};
