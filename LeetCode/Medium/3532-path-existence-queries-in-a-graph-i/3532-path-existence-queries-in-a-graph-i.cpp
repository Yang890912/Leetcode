class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> root(n, 0);

        for (int i = 0; i < n; i++) root[i] = i;

        for (int i = 1; i < n; i++) {
            if (abs(nums[i - 1] - nums[i]) <= maxDiff) root[i] = root[i - 1];
        }

        vector<bool> res;
        for (auto& q : queries) {
            if (root[q[0]] == root[q[1]]) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};