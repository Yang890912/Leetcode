class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {    
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), INT_MAX));

        recursive(dp, values, 0, values.size() - 1);

        return dp[0][values.size() - 1];
    }

    int recursive(vector<vector<int>>& dp, const vector<int>& values, int start, int end) {
        if (end - start <= 1) return 0;
        if (dp[start][end] != INT_MAX) return dp[start][end];

        int res = INT_MAX;
        int w = values[start] * values[end];
        for (int k = start + 1; k <= end - 1; k++) {
            res = min(res, w * values[k] + recursive(dp, values, start, k) + recursive(dp, values, k, end));
        }
        dp[start][end] = res;
        
        return dp[start][end];
    }
};