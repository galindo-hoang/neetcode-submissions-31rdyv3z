class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(int &i: nums) {
            if(store.contains(i)) {
                return true;
            }
            store.emplace(i);
        }
        return false;
    }
};