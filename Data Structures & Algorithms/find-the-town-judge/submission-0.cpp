class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> exists;
        vector<int> store(n, 0);
        stack<int> pending;
        for(vector<int> &t: trust) {
            exists.insert(t[0]);
            if(++store[t[1] - 1] == n - 1) {
                pending.emplace(t[1]);
            } 
        }
        while(!pending.empty()) {
            int cur = pending.top();
            if(!exists.contains(cur)) return cur;
            pending.pop();
        }
        return -1;
    }
};