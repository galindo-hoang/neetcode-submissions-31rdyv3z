class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string &str: strs) {
            int shift = str.size();
            if(shift >= 100) {
                res += to_string(shift);
            } else if(shift >= 10) {
                res += ('0' + to_string(shift));
            } else {
                res += ("00" + to_string(shift));
            }
            for(char ch: str) {
                int tmp = ((int)ch + shift) % 256;
                res += (char)tmp;
            }
        }
        return res;
    }
    // (15 + 20) % 26 = 9
    // (9 - 20) % 26 = 15

    vector<string> decode(string s) {
        if(s == "") return {};
        vector<string> res;
        int cur = stoi(s.substr(0, 3));
        int shift = cur;
        string tmp = "";
        for(int i = 3; i < s.size(); ++i) {
            if(cur > 0) {
                tmp += (char)(((int) s[i] - shift) % 256);
                --cur;
            } else {
                cur = stoi(s.substr(i, 3));
                shift = cur;    
                res.push_back(tmp);
                tmp = "";
                i += 2;
            }
        }

        res.push_back(tmp);
        return res;
    }
};
