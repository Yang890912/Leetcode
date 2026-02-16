/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node || node->val == p->val || node->val == q->val) return node;

        TreeNode* l = lowestCommonAncestor(node->left, p, q);
        TreeNode* r = lowestCommonAncestor(node->right, p, q);

        if (l && r) return node;
        else if (l) return l;
        else return r;
    }
};