class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> store(26, 0);
        vector<int> store1(26, 0);
        int remain = s1.size();
        for(char& c: s1) {
            ++store[c - 'a'];
        }
        int left = 0, right = 0;
        for(; right < s1.size(); ++right) {
            if(++store1[s2[right] - 'a'] <= store[s2[right] - 'a']) {
                --remain;
            }
        }
        if(remain == 0) return true;
        for(; right < s2.size(); ++right) {
            if(--store1[s2[left] - 'a'] < store[s2[left] - 'a']) ++remain;
            if(++store1[s2[right] - 'a'] <= store[s2[right] - 'a']) --remain;
            ++left;
            if(remain == 0) return true;
        }
        return false;
    }
};
