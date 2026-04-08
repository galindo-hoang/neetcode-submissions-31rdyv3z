struct TreeNode {
    bool isLeaf;
    vector<TreeNode*> sub;
    TreeNode() : isLeaf(false) {
        sub = vector<TreeNode*>(26, nullptr);
    }
};

class PrefixTree {
public:
    TreeNode* root = nullptr;

    PrefixTree() {
        root = new TreeNode();     
    }
    
    void insert(string word) {
        TreeNode* temp = root;
        for(char c: word) {
            int pos = c - 'a';
            if(temp->sub[pos] == nullptr) {
                temp->sub[pos] = new TreeNode();
            }
            temp = temp->sub[pos];
        }
        temp->isLeaf = true;
    }
    
    bool search(string word) {
        TreeNode* temp = root;
        for(char c: word) {
            int pos = c - 'a';
            if(!temp->sub[pos]) {
                return false;
            }
            temp = temp->sub[pos];
        }
        return temp->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TreeNode* temp = root;
        for(char c: prefix) {
            int pos = c - 'a';
            if(!temp->sub[pos]) {
                return false;
            }
            temp = temp->sub[pos];
        }
        return true;
    }
};
