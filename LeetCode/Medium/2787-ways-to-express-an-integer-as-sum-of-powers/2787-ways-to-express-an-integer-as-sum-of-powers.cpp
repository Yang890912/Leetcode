class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            if (val > n) break;
            powers.push_back(val);
        }

        int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers) {
            for (int i = n; i - p >= 0; i--) {
                dp[i] = (dp[i] + dp[i - p]) % MOD;
            }
        }

        return dp[n];
    }
};