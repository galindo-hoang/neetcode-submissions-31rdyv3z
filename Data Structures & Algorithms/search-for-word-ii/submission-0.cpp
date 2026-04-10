struct TreeNode {
    string isLeaf;
    int count;
    vector<TreeNode*> sub;
    TreeNode() : isLeaf(""), count(0) {
        sub = vector<TreeNode*>(26, nullptr);
    }
};

class Solution {
private:
    TreeNode* root = new TreeNode();
    void addWords(vector<string>& words) {
        for(string& str: words) {
            TreeNode* tmp = root;
            for(char& c: str) {
                if(!tmp->sub[c - 'a']) {
                    tmp->sub[c - 'a'] = new TreeNode();
                }
                tmp = tmp->sub[c - 'a'];
                ++tmp->count;
            }
            tmp->isLeaf = str;
        }
    }
    vector<pair<int,int>> direct {{0,1},{1,0},{0,-1},{-1,0}};

    void imple(vector<vector<char>>& board, int row, int col,
                TreeNode* root, 
                vector<string> &storage
            ) {
        if(root->isLeaf.size() > 0) {
            storage.emplace_back(root->isLeaf);
            root->isLeaf = "";
        }

        for(pair<int,int> &d: direct) {
            int r = d.first + row;
            int c = d.second + col;
            if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size()) {
                if(board[r][c] != '.' && root->sub[board[r][c] - 'a'] && root->sub[board[r][c] - 'a']->count > 0) {
                    char ct = board[r][c];
                    board[r][c] = '.';
                    imple(board, r, c, root->sub[ct - 'a'], storage);
                    board[r][c] = ct;
                    root->sub[board[r][c] - 'a']->count -= storage.size();
                }
            }
        }

    }

public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        addWords(words);

        for(int row = 0; row < board.size(); ++row) {
            for(int col = 0; col < board[row].size(); ++col) {
                if(root->sub[board[row][col] - 'a'] && root->sub[board[row][col] - 'a']->count > 0) {
                    TreeNode *tmp = root->sub[board[row][col] - 'a'];
                    char ct = board[row][col];
                    vector<string> storage;
                    board[row][col] = '.';
                    imple(board, row, col, tmp, storage);
                    board[row][col] = ct;
                    if(storage.size() > 0) {
                        res.insert(res.end(), storage.begin(), storage.end());
                    }
                }
            }
        }

        return res;
    }
};
