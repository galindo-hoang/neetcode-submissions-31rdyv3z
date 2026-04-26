class Solution {
public:
    vector<vector<char>> mapping{{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string tmp;
        impl(digits, 0, tmp);
        return res;
    }

    void impl(string digits, int cur, string tmp) {
        if(cur == digits.size()) {
            res.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < mapping[digits[cur] - '2'].size(); ++i) {
            impl(digits, cur + 1, tmp + mapping[digits[cur] - '2'][i]);
        }
    }
};
