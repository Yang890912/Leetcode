class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        int n = coins.size();

        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] > i) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        
        return dp[amount];
    }
};