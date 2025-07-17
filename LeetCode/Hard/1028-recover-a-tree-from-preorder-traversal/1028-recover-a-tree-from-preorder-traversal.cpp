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
    TreeNode* recoverFromPreorder(string traversal) {
        map<int, vector<TreeNode*>> levelTreeMap;
        int level = 0;
        int num = 0;

        for (int i = 0; i < traversal.size(); i++) {
            if (traversal[i] == '-') level++;
            else {
                num = num * 10 + traversal[i] - '0';
                if (i + 1 >= traversal.size() || traversal[i + 1] == '-') {
                    if (levelTreeMap.find(level) == levelTreeMap.end())
                        levelTreeMap[level] = {};
                    
                    TreeNode* node = new TreeNode(num);
                    levelTreeMap[level].push_back(node);

                    if (level > 0 && levelTreeMap[level - 1].back()->left == nullptr)
                        levelTreeMap[level - 1].back()->left = node;
                    else if (level > 0 && levelTreeMap[level - 1].back()->right == nullptr)
                        levelTreeMap[level - 1].back()->right = node;

                    num = 0;
                    level = 0;
                }
            }
        }

        return levelTreeMap[0][0];
    }
};