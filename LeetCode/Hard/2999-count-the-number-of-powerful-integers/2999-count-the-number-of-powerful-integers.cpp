class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countFromOne(finish, s, limit) - countFromOne(start - 1, s, limit);
    }

    long long countFromOne(long long target, string check, int limit) {
        string targetStr = to_string(target);
        int prefixLength = targetStr.size() - check.size();

        if (prefixLength < 0) return 0;
        
        vector<vector<long long>> dp(prefixLength + 1, vector<long long>(2, 0));
        dp[prefixLength][0] = 1;
        dp[prefixLength][1] = targetStr.substr(prefixLength) >= check ? 1 : 0;

        for (int i = prefixLength - 1; i >= 0; i--) {
            int targetDigit = targetStr[i] - '0';

            dp[i][0] = (long long) (limit + 1) * dp[i + 1][0];
            
            if (targetDigit <= limit) dp[i][1] = (long long) targetDigit * dp[i + 1][0] + dp[i + 1][1];
            else dp[i][1] = (long long) (limit + 1) * dp[i + 1][0];
        }

        return dp[0][1];
    }
};