class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> store(26, 0);
        for(char &c: s) {
            ++store[c - 'a'];
        }
        for(char &c: t) {
            if(--store[c - 'a'] < 0) {
                return false;
            }
        }
        for(int& i: store) {
            if(i != 0) return false;
        }
        return true;
    }
};
