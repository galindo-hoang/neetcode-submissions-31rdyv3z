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
    int res = true;
    bool isBalanced(TreeNode* root) {
        imple(root);
        return res;
    }
    int imple(TreeNode* root) {
        if(!root) return 0;
        int left = imple(root->left);
        int right = imple(root->right);
        if(abs(left - right) > 1) res = false;
        return max(left, right) + 1;
    }
};
