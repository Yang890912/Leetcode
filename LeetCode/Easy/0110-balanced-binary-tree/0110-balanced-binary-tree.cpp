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
        if (root == nullptr) return true;
        else if (abs(heightOfTree(root->left) - heightOfTree(root->right)) > 1) return false;
        else if (!isBalanced(root->left)) return false;
        else if (!isBalanced(root->right)) return false;
        else return true;
    }

    int heightOfTree(TreeNode* root) {
        int height = 0;
        if (root == nullptr) return height;
        height = 1 + max(heightOfTree(root->left), heightOfTree(root->right));
        return height;
    }
};