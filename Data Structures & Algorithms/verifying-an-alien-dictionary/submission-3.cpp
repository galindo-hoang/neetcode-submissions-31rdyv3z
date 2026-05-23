class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> store(order.size(),0);
        for(int i = 0; i < order.size(); ++i) {
            store[order[i] - 'a'] = i;
        }
        int j = 0;
        for(int i = 0; i < 20; ++i) {
            int temp = -1;
            bool isGreater = true;
            for(int k = j; k < words.size(); ++k) {
                if(words[k].size() <= i) {
                    if(temp != -1) return false;
                    continue;
                }
                if(temp == -1){
                    temp = store[words[k][i] - 'a'];
                }
                else {
                    if(temp == (store[words[k][i] - 'a'])) {
                        if(isGreater) j = k - 1;
                        isGreater = false;
                    } else if(temp > (store[words[k][i] - 'a'])) {
                        return false;
                    } else temp = store[words[k][i] - 'a'];
                }
            }
            if (isGreater) return true;
        }
        return true;
    }
};