class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> count(26, 0);
        unordered_map<string,vector<string>> store;
        vector<vector<string>> res;
        for(string& str: strs) {
            for(char& ch: str) {
                ++count[ch - 'a'];
            }
            string tmp = "";
            for(int i = 0; i < 26; ++i) {
                if(count[i] != 0) {
                    tmp += to_string(count[i]) + char('a' + i);
                    count[i] = 0;
                }
            }
            store[tmp].push_back(str);
        }
        for (const auto& pair : store) {
            res.push_back(pair.second);
        }
        return res;
    }
};
