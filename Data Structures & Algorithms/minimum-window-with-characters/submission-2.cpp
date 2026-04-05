class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int> storeS(123, 0);
        vector<int> storeT(123, 0);
        for(char&c: t) {
            ++storeT[static_cast<int>(c)];
        }
        int left = 0, remain = t.size();
        int res = s.size() + 1, resL = -1, resR = -1;
        for(int right = 0; right < s.size(); ++right) {
            if(++storeS[static_cast<int>(s[right])] <= storeT[static_cast<int>(s[right])]) --remain;
            while(remain == 0) {
                if(res > (right - left + 1)) {
                    resL = left;
                    resR = right;
                    res = (right - left + 1);
                }
                if(--storeS[static_cast<int>(s[left])] < storeT[static_cast<int>(s[left])]) ++remain;
                ++left;
            }
        }
        if(res == s.size() + 1) return "";
        string str = "";
        for(int i = resL; i <= resR; ++i) {
            str += s[i];
        }
        return str;
    }
};
