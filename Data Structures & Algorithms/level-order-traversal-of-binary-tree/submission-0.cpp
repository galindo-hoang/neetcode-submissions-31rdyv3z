/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> pending;
        pending.emplace(root, 0);
        while(!pending.empty()) {
            pair<TreeNode*,int> cur = pending.front();
            pending.pop();
            if(res.size() <= cur.second) {
                res.emplace_back(vector<int>());
            }
            res[cur.second].emplace_back(cur.first->val);
            if(cur.first->left) {
                pending.emplace(cur.first->left, cur.second + 1);
            }
            if(cur.first->right) {
                pending.emplace(cur.first->right, cur.second + 1);
            }
        }
        return res;
    }
};
