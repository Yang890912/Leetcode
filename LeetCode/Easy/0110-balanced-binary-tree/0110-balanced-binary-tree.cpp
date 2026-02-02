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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        if (getHeight(root, 1) == -1) return false;

        return true;
    }

    int getHeight(TreeNode* node, int height) {
        if (!node) return height - 1;

        int l = getHeight(node->left, height + 1);
        int r = getHeight(node->right, height + 1);
        
        if (l == -1 || r == -1 || abs(l - r) >= 2) return -1;
        
        return max(l, r);
    }
};