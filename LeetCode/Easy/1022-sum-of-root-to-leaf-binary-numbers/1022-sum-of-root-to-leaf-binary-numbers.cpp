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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int size = q.size();
        while (!q.empty()) {
            while (size--) {
                TreeNode* node = q.front().first;
                int sum = q.front().second;
                q.pop();

                sum <<= 1;
                sum += node->val;
                if (node->left) q.push({node->left, sum});
                if (node->right) q.push({node->right, sum});
                if (!node->left && !node->right) res += sum;
            }
            size = q.size();
        }

        return res;
    }
};