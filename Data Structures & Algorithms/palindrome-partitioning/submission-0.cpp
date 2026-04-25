class Solution {
public:
    bool isPalin(string &str) {
        for(int i = 0; i < str.size() / 2; ++i) {
            if(str[i] != str[str.size() - 1 - i]) return false;
        }
        return true;
    }
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        imple(s, 0, tmp);
        return res;
    }
    void imple(string s, int pos, vector<string> &tmp) {
        if(pos == s.size()) {
            res.emplace_back(tmp);
        }
        string str;
        for(int i = pos; i < s.size(); ++i) {
            str += s[i];
            if(isPalin(str)) {
                tmp.emplace_back(str);
                imple(s, i + 1, tmp);
                tmp.pop_back();
            }
        }
    }
};
