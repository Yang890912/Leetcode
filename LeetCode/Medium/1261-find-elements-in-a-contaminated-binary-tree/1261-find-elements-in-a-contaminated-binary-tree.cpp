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
class FindElements {
public:
    unordered_set<int> elements;
    
    void recover(TreeNode* node) {
        elements.insert(node->val);
        
        if (node->left != nullptr) {
            node->left->val = 2 * node->val + 1;
            recover(node->left);
        }

        if (node->right != nullptr) {
            node->right->val = 2 * node->val + 2;
            recover(node->right);
        }
    }

    FindElements(TreeNode* root) {
        if (root != nullptr) {
            root->val = 0;
            recover(root);
        }
    }
    
    bool find(int target) {
        return elements.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */