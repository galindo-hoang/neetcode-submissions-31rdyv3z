class Solution {
public:
    void scan(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') return;
        grid[r][c] = '0';
        scan(grid, r + 1, c);
        scan(grid, r - 1, c);
        scan(grid, r, c + 1);
        scan(grid, r, c - 1);

    }
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>> pending;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    pending.emplace(i,j);
                }
            }
        }
        int res = 0;
        while(!pending.empty()) {
            pair<int,int> cur = pending.top();
            pending.pop();
            if(grid[cur.first][cur.second] == '1') {
                ++res;
                scan(grid, cur.first, cur.second);
            }
        }
        return res;
    }
};
