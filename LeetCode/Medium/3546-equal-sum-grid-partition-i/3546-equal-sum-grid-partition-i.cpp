class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        long long tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp += rowSum[i];
            if (tmp * 2 == total) return true;
            else if (tmp * 2 > total) break;
        }
        tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += colSum[j];
            if (tmp * 2 == total) return true;
            else if (tmp * 2 > total) break;
        }

        return false;
    }
};