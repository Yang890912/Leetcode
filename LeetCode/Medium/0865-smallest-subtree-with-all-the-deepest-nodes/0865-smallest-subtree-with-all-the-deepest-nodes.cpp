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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return traverseTree(root, 1).first;
    }

    pair<TreeNode*, int> traverseTree(TreeNode* node, int level) {
        if (!node) return {nullptr, -1};

        pair<TreeNode*, int> l = traverseTree(node->left, level + 1);
        pair<TreeNode*, int> r = traverseTree(node->right, level + 1);

        if (!l.first && !r.first) return {node, level};
        if (l.first && r.first && l.second == r.second) return {node, r.second};
        if (l.second < r.second) return {r.first, r.second};

        return {l.first, l.second};
    }
};