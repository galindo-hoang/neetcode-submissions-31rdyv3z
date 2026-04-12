class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> store;
        for(int &stone: stones) {
            store.emplace(stone);
        }
        while(store.size() >= 2) {
            int large = store.top();
            store.pop();
            int small = store.top();
            store.pop();
            int dis = large - small;
            if(dis != 0) store.emplace(dis);
        }
        if(store.size() == 1) return store.top();
        return 0;
    }
};
