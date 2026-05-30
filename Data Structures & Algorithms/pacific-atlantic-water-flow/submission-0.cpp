class Solution {
public:
    vector<pair<int,int>> directs {{1,0},{-1,0},{0,1},{0,-1}};
    void scan(queue<pair<int,int>> &pending, vector<vector<bool>> &flags, vector<vector<int>> heights) {
        while(!pending.empty()) {
            pair<int,int> cur = pending.front();
            pending.pop();
            if(flags[cur.first][cur.second]) continue;
            flags[cur.first][cur.second] = true;
            for(pair<int,int> &d: directs) {
                int r = d.first + cur.first;
                int c = d.second + cur.second;
                if(c < 0 || r < 0 || c >= flags[0].size() || r >= flags.size() || flags[r][c] || heights[r][c] < heights[cur.first][cur.second]) continue;
                pending.emplace(r,c);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> p(heights.size(), vector<bool>(heights[0].size(),false)), a(heights.size(), vector<bool>(heights[0].size(),false));
        queue<pair<int,int>> pendingP, pendingA;
        for(int r = 0; r < heights.size(); ++r) {
            pendingP.emplace(r, 0);
            pendingA.emplace(r, heights[0].size() - 1);
        }
        for(int c = 0; c < heights[0].size(); ++c) {
            pendingP.emplace(0, c);
            pendingA.emplace(heights.size() - 1, c);
        }
        scan(pendingP, p, heights);
        scan(pendingA, a, heights);
        vector<vector<int>> res;
        for(int r = 0; r < heights.size(); ++r) {
            for(int c = 0; c < heights[0].size(); ++c) {
                if(p[r][c] && a[r][c]) {
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }
};
