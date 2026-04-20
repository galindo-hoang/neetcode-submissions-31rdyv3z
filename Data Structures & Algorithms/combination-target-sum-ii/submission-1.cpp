class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        impl(candidates, target, candidates.size(), tmp);
        return res;
    }
    void impl(vector<int>& candidates, int &target, int pos, vector<int>& tmp) {
        if(target == 0) {
            res.emplace_back(tmp);
            return;
        }
        int prev = -1;
        for(int i = pos - 1; i >= 0; --i) {
            if(candidates[i] == prev) continue;
            prev = candidates[i];
            if(candidates[i] <= target) {
                target -= candidates[i];
                tmp.emplace_back(candidates[i]);
                impl(candidates, target, i, tmp);
                tmp.pop_back();
                target += candidates[i];
            }
        }
    }
};
