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
    int maxLevelSum(TreeNode* root) {
        map<int, int> levelToSum;
        traverseTree(1, root, levelToSum);

        int res = 0;
        int currMax = INT_MIN;
        for (auto pair : levelToSum) {
            if (pair.second > currMax) {
                res = pair.first;
                currMax = pair.second;
            }
        }

        return res;
    }

    void traverseTree(int level, TreeNode* node, map<int, int>& levelToSum) {
        if (!node) return;

        levelToSum[level] += node->val;

        traverseTree(level + 1, node->left, levelToSum);
        traverseTree(level + 1, node->right, levelToSum);

        return;
    }
};