class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        vector<vector<long long>> prefixSum(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                if (i == 0 && j == 0) prefixSum[i][j] = grid[i][j];
                else if (i == 0) prefixSum[i][j] = grid[i][j] + prefixSum[i][j - 1];
                else if (j == 0) prefixSum[i][j] = grid[i][j] + prefixSum[i - 1][j];
                else prefixSum[i][j] = grid[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            if (total == prefixSum[i][n - 1] * 2) return true;
            else if (total < prefixSum[i][n - 1] * 2) break;
        }
        for (int j = 0; j < n; j++) {
            if (total == prefixSum[m - 1][j] * 2) return true;
            else if (total < prefixSum[m - 1][j] * 2) break;
        }

        return false;
    }
};