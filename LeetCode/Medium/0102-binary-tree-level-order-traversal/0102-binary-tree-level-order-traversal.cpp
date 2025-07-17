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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        traceTree(root, 0, traversal);
        return traversal;
    }

    void traceTree(TreeNode* root, int depth, vector<vector<int>>& traversal) {
        if (root == nullptr) return;

        if (depth == 0 || depth > traversal.size() - 1) traversal.push_back({root->val});
        else traversal[depth].push_back(root->val);

        traceTree(root->left, depth + 1, traversal);
        traceTree(root->right, depth + 1, traversal);
    }
};