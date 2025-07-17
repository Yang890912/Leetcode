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
    bool isValidBST(TreeNode* root) {
        // if(root == nullptr) return true;
        return isSupportValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isSupportValidBST(TreeNode* root, long left, long right) {
        if (root == nullptr) return true;
        if (root->val >= right || root->val <= left) return false;

        return isSupportValidBST(root->left, left, root->val) && isSupportValidBST(root->right, root->val, right);
    }
};