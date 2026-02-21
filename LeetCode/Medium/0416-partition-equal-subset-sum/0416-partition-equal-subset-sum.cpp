class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int num : nums) sum += num;

        if (sum % 2 == 1) return false;

        vector<bool> dp(sum + 1, false);
        int tar = sum / 2;
        dp[0] = true;
        for (int num : nums) {
            for (int t = tar; t >= num; t--) {
                dp[t] = dp[t] | dp[t - num];
                if (dp[tar]) return true;
            }
        }

        return dp[tar];
    }
};