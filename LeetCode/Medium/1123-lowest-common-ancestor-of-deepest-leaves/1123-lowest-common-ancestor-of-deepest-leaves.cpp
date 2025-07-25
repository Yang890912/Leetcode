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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return trace(root, 0).first;
    }

    pair<TreeNode*, int> trace(TreeNode* node, int depth) {
        if (node == nullptr) return {nullptr, depth};

        pair<TreeNode*, int> leftNode = trace(node->left, depth + 1); 
        pair<TreeNode*, int> rightNode = trace(node->right, depth + 1);

        if (leftNode.second < rightNode.second) return {rightNode.first, rightNode.second};
        else if (leftNode.second > rightNode.second) return {leftNode.first, leftNode.second};
        else return {node, leftNode.second};
    }
};