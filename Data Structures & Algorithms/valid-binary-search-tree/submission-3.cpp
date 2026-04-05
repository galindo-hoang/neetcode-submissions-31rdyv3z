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
    int previous = -1001;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!(isValidBST(root->left) && previous < root->val)) return false;
        previous = root->val;
        return isValidBST(root->right);
    }
};