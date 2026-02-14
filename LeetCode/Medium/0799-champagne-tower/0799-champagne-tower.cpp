class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row == 0) return min(poured, 1); 

        vector<double> dp(102, 0.0);
        dp[1] = poured;
        int i = 1;
        while (i <= query_row) {
            vector<double> _dp(102, 0.0);
            for (int j = 1; j <= i + 1; j++) {
                if (dp[j - 1] > 1.0) _dp[j] += 0.5 * (dp[j - 1] - 1.0);
                if (dp[j] > 1.0) _dp[j] += 0.5 * (dp[j] - 1.0); 
            }
            dp = _dp;

            if (i == query_row) return min(dp[query_glass + 1], 1.0);

            i++;
        }

        return 0.0;
    }
};