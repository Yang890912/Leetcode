class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int maxLen = 0;

        for (int i = 0; i < k; i++) {
            vector<int> dp(k, 0);

            for (int num : nums) {
                dp[num % k] = max(dp[num % k], dp[(k + i - (num % k)) % k] + 1);
                maxLen = max(maxLen, dp[num % k]);
            }
        }

        return maxLen;
    }
};