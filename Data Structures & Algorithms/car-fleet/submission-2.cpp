class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pending;
        for(int i = 0; i < position.size(); ++i) {
            pending.emplace(position[i], speed[i]);
        }
        int res = 0;
        double prev = -1;
        do {
            pair<int,int> cur = pending.top();
            double tmp = (double)(target - cur.first)/ cur.second;
            if(tmp > prev) {
                ++res;
                prev = tmp;
            }
            pending.pop();
        } while(!pending.empty());
        
        return res;
    }
};
