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
    int goodNodes(TreeNode* root) {
        return impl(root, root->val);
    }

    int impl(TreeNode* root, int ma) {
        if(!root) return 0;
        int tmp = 0;
        if(root->val >= ma) {
            ++tmp;
            ma = root->val;
        }
        return tmp + impl(root->left, ma) + impl(root->right, ma);
    }
};
