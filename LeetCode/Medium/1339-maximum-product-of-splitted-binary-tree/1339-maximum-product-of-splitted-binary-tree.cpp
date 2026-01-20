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
    int maxProduct(TreeNode* root) {
        map<TreeNode*, int> nodeToSum;
        long long res = 0;
        int sum = subtreeSum(root, nodeToSum);
        traverseTree(nodeToSum, root, sum, res);

        return res % (long long)(1e9 + 7);
    }

    int subtreeSum(TreeNode* node, map<TreeNode*, int>& nodeToSum) {
        if (!node) return 0;

        int sum = node->val 
                + subtreeSum(node->left, nodeToSum) 
                + subtreeSum(node->right, nodeToSum);
        
        nodeToSum[node] = sum;

        return sum;
    }

    void traverseTree(map<TreeNode*, int>& nodeToSum, TreeNode* node, const int& sum, long long& currMax) {
        if (!node) return;

        long long prod = (long long)(sum - nodeToSum[node]) * nodeToSum[node];

        currMax = max(currMax, prod);

        traverseTree(nodeToSum, node->left, sum, currMax);
        traverseTree(nodeToSum, node->right, sum, currMax);

        return;
    }
};