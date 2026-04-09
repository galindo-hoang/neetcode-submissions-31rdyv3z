struct TreeNode {
    bool isLeaf;
    vector<TreeNode*> sub;
    TreeNode() : isLeaf(false) {
        sub = vector<TreeNode*>(26, nullptr);
    }
};

class WordDictionary {
public:
    TreeNode* root = nullptr;
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* temp = root;
        for(char c: word) {
            if(!temp->sub[c - 'a']) {
                temp->sub[c - 'a'] = new TreeNode();
            }
            temp = temp->sub[c - 'a'];
        }
        temp->isLeaf = true;
    }
    
    bool search(string word) {
        TreeNode* temp = root;
        return implSearch(temp, word, 0);
    }
    bool implSearch(TreeNode* cur, string word, int pos) {
        if(cur == nullptr && pos < word.size()) return false;
        if(pos == word.size()) {
            return cur != nullptr && cur->isLeaf;
        }
        if(word[pos] == '.') {
            bool isLeaf = false;
            for(int i = 0; i < 26; ++i) {
                isLeaf = isLeaf || implSearch(cur->sub[i], word, pos + 1);
            }
            return isLeaf;
        } else {
            return implSearch(cur->sub[word[pos] - 'a'], word, pos + 1);
        }
    }
};
