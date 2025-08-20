class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (dp[i][j] == 1 && i > 0 && j > 0) {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                res += dp[i][j];
            }
        }

        return res;
    }
};