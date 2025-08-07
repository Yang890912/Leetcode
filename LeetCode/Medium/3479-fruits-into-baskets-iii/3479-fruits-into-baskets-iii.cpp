struct Node {
    int l, r;
    int maxVal;        
    Node *left, *right;

    Node(int l, int r): l(l), r(r), maxVal(0), left(nullptr), right(nullptr) {}
};

class Solution {
    void build(Node* node, const vector<int>& arr) {
        if (node->l == node->r) {
            node->maxVal = arr[node->l];
            return;
        }

        int mid = (node->l + node->r) / 2;
        node->left = new Node(node->l, mid);
        node->right = new Node(mid + 1, node->r);
        build(node->left, arr);
        build(node->right, arr);
        node->maxVal = max(node->left->maxVal, node->right->maxVal);
    }

    void update(Node* node, int idx, int val) {
        if (node->l == node->r) {
            node->maxVal = val;
            return;
        }

        int mid = (node->l + node->r) / 2;
        if (idx <= mid) update(node->left, idx, val);
        else update(node->right, idx, val);
        node->maxVal = max(node->left->maxVal, node->right->maxVal);
    }

    int firstLarger(Node* node, int qVal) {
        if (node->maxVal < qVal) return node->r + 1;
        if (node->l == node->r) return node->r;

        int mid = (node->l + node->r) / 2;
        int leftLarger = firstLarger(node->left, qVal);
        if (leftLarger <= mid) return leftLarger;
        else return firstLarger(node->right, qVal);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        Node* root = new Node(0, n - 1);
        build(root, baskets);

        int res = 0;
        for (int fruit : fruits) {
            int pos = firstLarger(root, fruit);
            if (pos == n) res++;
            else update(root, pos, 0);
        }

        return res;
    }
};