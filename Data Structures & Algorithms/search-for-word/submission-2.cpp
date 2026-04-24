class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(word[0] == board[i][j]) {
                    bool check = imple(board, word, 0, i, j);
                    if(check) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool imple(vector<vector<char>>& board, string word, int cur, int r, int c) {
        if(cur == word.size()) return true;
        if(!(r >= 0 && r < board.size() && c >= 0 && c < board[0].size())) return false;
        if(word[cur] == board[r][c]) {
            char tmp = board[r][c];
            board[r][c] = '.';
            bool a = imple(board, word, cur + 1, r + 1, c) ||
                    imple(board, word, cur + 1, r - 1, c) ||
                    imple(board, word, cur + 1, r, c + 1) ||
                    imple(board, word, cur + 1, r, c - 1);
            board[r][c] = tmp;
            return a;
        } else return false;
    }
};
