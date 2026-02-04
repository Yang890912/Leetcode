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
        vector<vector<int>> res;
        preOrder(res, root, 0);
        return res;
    }

    void preOrder(vector<vector<int>>& res, TreeNode* node, int level) {
        if (!node) return;

        if (level >= res.size()) res.push_back({node->val});
        else res[level].push_back(node->val);

        preOrder(res, node->left, level + 1);
        preOrder(res, node->right, level + 1);

        return;
    }
};