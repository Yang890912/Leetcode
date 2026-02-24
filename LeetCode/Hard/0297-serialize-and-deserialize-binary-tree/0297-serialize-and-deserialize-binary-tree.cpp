/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preEncode(root, s);
        return s;
    }

    void preEncode(TreeNode* node, string& s) {
        if (node) {
            s = s + to_string(node->val) + " ";
            preEncode(node->left, s);
            preEncode(node->right, s);
        }
        else {
            s = s + "* ";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return preDecode(ss);
    }

    TreeNode* preDecode(stringstream& ss) {
        string token;
        ss >> token;
        if (token == "*") return nullptr;

        TreeNode* newNode = new TreeNode(stoi(token));
        newNode->left = preDecode(ss);
        newNode->right = preDecode(ss);
        
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));