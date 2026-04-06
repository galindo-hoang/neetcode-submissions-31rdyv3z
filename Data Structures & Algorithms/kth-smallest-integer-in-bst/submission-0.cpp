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
    vector<int> res;
    int kthSmallest(TreeNode* root, int k) {
        imple(root, k);
        return res[k - 1];
    }
    void imple(TreeNode* root, int k) {
        if(res.size() == k || !root) return;
        imple(root->left, k);
        res.emplace_back(root->val);
        if(res.size() == k) return;
        imple(root->right, k);
    }
};
