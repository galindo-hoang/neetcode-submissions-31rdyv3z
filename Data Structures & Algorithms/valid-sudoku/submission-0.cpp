class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> hor(9); 
        vector<unordered_set<char>> ver(9); 
        vector<unordered_set<char>> box(9);
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] >= '1' && board[i][j] <= '9') {
                    bool isHor = hor[i].find(board[i][j]) != hor[i].end();
                    bool isVer = ver[j].find(board[i][j]) != ver[j].end();
                    int tmp = (i / 3) * 3 + (j / 3);
                    bool isBox = box[tmp].find(board[i][j]) != box[tmp].end();
                    if(isHor || isVer || isBox) {
                        return false;
                    }
                    hor[i].emplace(board[i][j]);
                    ver[j].emplace(board[i][j]);
                    box[tmp].emplace(board[i][j]);
                }
            }
        }
        return true;
    }
};
