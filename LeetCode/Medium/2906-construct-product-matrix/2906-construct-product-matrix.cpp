class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        long long prefix = 1, suffix = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = prefix;
                prefix = prefix * grid[i][j] % 12345;
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                res[i][j] = suffix * res[i][j] % 12345;
                suffix = suffix * grid[i][j] % 12345;
            }
        }

        return res;
    }
};