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
    int count = 0;
    int goodNodes(TreeNode* root) {
        impl(root, root->val);
        return count;
    }

    void impl(TreeNode* root, int ma) {
        if(!root) return;
        if(root->val >= ma) {
            ++count;
            ma = root->val;
        }
        impl(root->left, ma);
        impl(root->right, ma);
    }
};
