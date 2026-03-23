class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {0, 0}));
        dp[0][0] = {grid[0][0], grid[0][0]};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                vector<long long> cand;

                if (i > 0) {
                    cand.push_back(dp[i - 1][j].first * grid[i][j]);
                    cand.push_back(dp[i - 1][j].second * grid[i][j]);
                }
                if (j > 0) {
                    cand.push_back(dp[i][j - 1].first * grid[i][j]);
                    cand.push_back(dp[i][j - 1].second * grid[i][j]);
                }

                long long mn = INT_MAX;
                long long mx = INT_MIN;
                for (long long v : cand) {
                    mn = min(v, mn);
                    mx = max(v, mx);
                }

                dp[i][j] = {mn, mx};
            }
        }

        return dp[m - 1][n - 1].second >= 0 ? dp[m - 1][n - 1].second % MOD : -1;
    }
};