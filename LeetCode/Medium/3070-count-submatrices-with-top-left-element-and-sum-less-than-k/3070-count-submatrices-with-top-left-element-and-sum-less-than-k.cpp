class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0);
                else if (i == 0) grid[i][j] += grid[i][j - 1];
                else if (j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] = grid[i][j] + grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];

                if (grid[i][j] <= k) res++;
            }
        }

        return res;
    }
};