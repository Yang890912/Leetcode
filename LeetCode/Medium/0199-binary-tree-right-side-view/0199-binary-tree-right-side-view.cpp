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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        preorder(res, root, 1);

        return res;
    }

    void preorder(vector<int>& res, TreeNode* node, int level) {
        if (!node) return;

        if (level > res.size()) res.push_back(node->val);
        else res[level - 1] = node->val;

        preorder(res, node->left, level + 1);
        preorder(res, node->right, level + 1);        
    }
};