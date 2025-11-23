class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));

        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int r = 0; r < 3; r++) {
                dp[i][r] = max(dp[i][r], dp[i + 1][r]);

                int nr = (r + nums[i]) % 3;
                if (dp[i + 1][r] != INT_MIN) {
                    dp[i][nr] = max(dp[i][nr], dp[i + 1][r] + nums[i]);
                }
            }
        }

        return (dp[0][0] == INT_MIN) ? 0 : dp[0][0];
    }
};