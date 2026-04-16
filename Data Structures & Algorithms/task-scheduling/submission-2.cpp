class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> store(26, 0);
        vector<int> count(26, 0);
        int step = 0;
        int left = tasks.size();
    
        for(char& c: tasks) {
            ++store[c - 'A'];
        }
        priority_queue<pair<int, char>> pending;
        for(int i = 0; i < 26; ++i) {
            if(store[i] != 0) {
                pending.emplace(store[i], char('A' + i));
            }
        }
        queue<pair<int, char>> temp;
        while(left > 0) {
            int mi = INT_MAX;
            int pre_step = step;
            while(!pending.empty()) {
                pair<int,char> top = pending.top();
                pending.pop();
                mi = min(mi, count[top.second - 'A']);
                if(count[top.second - 'A'] <= step) {
                    ++step;
                    --left;
                    if(--top.first > 0) {
                        count[top.second - 'A'] += (n + 1);
                        temp.emplace(top.first, top.second);
                    }
                    break;
                } else {
                    temp.emplace(top.first, top.second);
                }
            }
            if(pre_step == step) step = mi;
            while(!temp.empty()) {
                pending.emplace(temp.front().first, temp.front().second);
                temp.pop();
            }
        }
        return step;
    }
};
