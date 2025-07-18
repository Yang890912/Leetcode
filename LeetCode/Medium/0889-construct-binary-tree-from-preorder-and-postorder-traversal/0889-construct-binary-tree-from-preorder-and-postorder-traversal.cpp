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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> nodes;
        TreeNode* root = new TreeNode(preorder[0]);
        int preIdx = 1;
        int postIdx = 0;

        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* node = nodes.top();

            if (node->val == postorder[postIdx]) {
                nodes.pop();
                postIdx++;
            }
            else {
                TreeNode* newNode = new TreeNode(preorder[preIdx++]);
                if (node->left == nullptr) node->left = newNode;
                else node->right = newNode;
                nodes.push(newNode);
            }
        }
        
        return root;
    }
};