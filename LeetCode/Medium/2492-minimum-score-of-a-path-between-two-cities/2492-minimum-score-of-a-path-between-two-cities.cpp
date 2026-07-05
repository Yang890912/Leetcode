class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> root(n + 1);

        for (int i = 1; i <= n; i++) root[i] = i;

        for (vector<int>& r : roads) {
            root[find(root, r[0])] = find(root, r[1]);
        }

        int res = INT_MAX;
        for (vector<int>& r : roads) {
            if (find(root, r[0]) == find(root, 1)) 
                res = min(res, r[2]);
        }

        return res;
    }

    int find(vector<int>& root, int element) {
        if (root[element] == element) return element;
        root[element] = find(root, root[element]);
        return root[element];
    }
};