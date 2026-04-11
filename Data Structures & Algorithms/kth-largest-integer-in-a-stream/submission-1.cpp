class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> store;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int &val: nums) {
            store.emplace(val);
            if(store.size() > k) {
                store.pop();
            }
        }
    }
    
    int add(int val) {
        store.emplace(val);
        if(store.size() > k) {
            store.pop();
        }
        return store.top();
    }
};
