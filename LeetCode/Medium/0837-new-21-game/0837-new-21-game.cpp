class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n > k - 1 + maxPts) return 1.0;

        double res = 0.0;
        double numerator = 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        for (int i = 1; i <= n; i++) {
            dp[i] = numerator / maxPts;

            if (i < k) numerator += dp[i];  // 如果目前分數還不到 k，則可以用來當作後面的機率
            else res += dp[i]; 

            if (i - maxPts >= 0) numerator -= dp[i - maxPts];   // 減去計算不到的機率
        }

        return res;
    }

};