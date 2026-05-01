class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prev(n, vector<int>(k + 1, INT_MIN));

        for (int i = 0; i < m; i++) {
            vector<vector<int>> curr(n, vector<int>(k + 1, INT_MIN)); 

            for (int j = 0; j < n; j++) {
                int cost = (grid[i][j] ? 1 : 0);

                if (i == 0 && j == 0) {
                    curr[j][cost] = grid[i][j];
                    continue;
                }

                for (int c = 0; c <= k - cost; c++) {
                    if (i > 0 && prev[j][c] != INT_MIN) {
                        curr[j][c + cost] = max(curr[j][c + cost], prev[j][c] + grid[i][j]);
                    }
                    if (j > 0 && curr[j - 1][c] != INT_MIN) {
                        curr[j][c + cost] = max(curr[j][c + cost], curr[j - 1][c] + grid[i][j]);
                    }
                }
            }

            prev = curr;
        }

        int res = -1;
        for (int c = 0; c <= k; c++) {
            res = max(res, prev[n - 1][c]);
        }

        return res;
    }
};