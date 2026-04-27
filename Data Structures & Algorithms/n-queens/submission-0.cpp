class Solution {
public:
    vector<pair<int,int>> directions{{0,-1},{-1,-1},{1,-1}};
    bool isCollision(int r, int c, vector<string>& str) {
        for(pair<int,int> direct: directions) {
            int count = 1;
            while(true) {
                pair<int,int> tmp = {direct.first * count + r, direct.second * count + c};
                if(tmp.first >= 0 && tmp.first < str.size() && tmp.second >= 0) {
                    if(str[tmp.first][tmp.second] == 'Q') return true;
                } else break;
                ++count;
            }
        }
        return false;
    }
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        string init;
        for(int i = 0; i < n; ++i) {
            init += '.';
        }
        vector<string> tmp(n, init);
        imple(tmp, 0);
        return res;
    }

    void imple(vector<string>& str, int c) {
        if(c == str.size()) {
            res.emplace_back(str);
            return;
        }

        for(int row = 0; row < str.size(); ++row) {
            if(c == 0 || !isCollision(row, c, str)) {
                str[row][c] = 'Q';
                imple(str, c + 1);
                str[row][c] = '.';
            }
        }
    }
};
